#include "Enemy.h"
#include "DxLib.h"
#include <memory>

// 度をラジアンに変換
static float ToRad(float degree)
{
	return degree * static_cast<float>(DX_PI) / 180.0f;
}

// ラジアンを度に変換
static float ToDeg(float radian)
{
	return radian * 180.0f / static_cast<float>(DX_PI);
}

void Enemy::SetPatrolRoute(const Vec2<float> route)
{
	patrolRoute.emplace_back(route);
}

Vec2<float> Enemy::Forward() const
{
	// 前方向をベクトルに変換して返す
	return Vec2<float>(std::cos(ToRad(angle)), std::sin(ToRad(angle)));
}

bool Enemy::CanSeePlayer(const std::shared_ptr<Player> player) const
{
	// 距離を見る
	Vec2<float> toPlayer = player->GetPos() - pos;
	// 距離が遠い場合は見えない
	if (toPlayer.GetLengthSq() > dist * dist)
		return false;

	// 角度を調べる
	Vec2<float> toPlayerN = toPlayer.Normalize();
	// 視野角の半分の余弦値を計算
	float cosThresh = static_cast<float>(std::cos(ToRad(fov) * 0.5));
	// 内積を計算
	float dp = toPlayerN.Dot(Forward());
	// 視野角内なら見える
	return dp >= cosThresh;
}

void Enemy::Update(float totalTime)
{
}

void Enemy::Draw(int* image) const
{
	// 本体描画
	DrawCircleAA(pos.x, pos.y, 12, 32, GetColor(255, 0, 0), TRUE);

	// 視界画像描画
	double lastAngle = static_cast<double>((angle + fov * 0.5f) / 360.0f * 100.0f);
	double startAngle = static_cast<double>((angle - fov * 0.5f) / 360.0f * 100.0f);
	DrawCircleGaugeF(pos.x, pos.y, lastAngle, *image, startAngle, dist);
}
