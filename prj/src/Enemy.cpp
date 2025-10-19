#include "Enemy.h"
#include "DxLib.h"
#include <memory>

// 度をラジアンに変換
static float ToRad(float degree)
{
	return degree * static_cast<float>(DX_PI) / 180.0f;
}

Enemy::Enemy(const Vec2<float>& startPos, float argAngle, float argFov, float argDist, float argSpeed)
	: pos(startPos), fov(argFov), dist(argDist), moveSpeed(argSpeed)
{
	angle = ToRad(argAngle);
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
	if (toPlayer.GetLengthSq() > dist * dist)
		return false;

	// 角度を調べる
	Vec2<float> toPlayerN = toPlayer.Normalize();
	// 視野角の半分の余弦値を計算
	float cosThresh = static_cast<float>(std::cos(ToRad(fov) * 0.5));
	// 内積を計算
	float dp = toPlayerN.Dot(Forward());
	// 視野内か
	return dp >= cosThresh;
}

void Enemy::Update(float totalTime)
{
	// 首振りアニメーション
	angle += std::sin(totalTime + (pos.x + pos.y) * 0.01f) * 0.5f;
}

void Enemy::Draw(bool detected) const
{
	// 本体描画
	DrawCircleAA(pos.x, pos.y, 12, 32, GetColor(255, 0, 0), TRUE);

	// 視野描画
	float rad = ToRad(angle);
	// 視野角の半分のラジアンを計算
	float halfFovRad = ToRad(fov) * 0.5f;
	// 視野端の方向ベクトルを計算
	Vec2<float> leftDir(std::cos(rad - halfFovRad), std::sin(rad - halfFovRad));
	Vec2<float> rightDir(std::cos(rad + halfFovRad), std::sin(rad + halfFovRad));
	// 端の位置を計算
	Vec2<float> leftEnd = pos + leftDir * dist;
	Vec2<float> rightEnd = pos + rightDir * dist;

	// 描画
	DrawLineAA(pos.x, pos.y, leftEnd.x, leftEnd.y, GetColor(200, 200, 200));
	DrawLineAA(pos.x, pos.y, rightEnd.x, rightEnd.y, GetColor(200, 200, 200));
	DrawCircleAA(pos.x, pos.y, dist, 32, GetColor(100, 100, 100), FALSE);

	// 発見マーク描画
	if (detected)
		DrawFormatStringF(pos.x, pos.y - 30.0f, GetColor(255, 0, 0), "!!");
}
