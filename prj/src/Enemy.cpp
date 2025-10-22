#include "Enemy.h"
#include "DxLib.h"

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
 // プレイヤーの中心からの距離
    Vec2<float> toPlayer = player->GetPos() - pos;

	// プレイヤーの半径を視界距離に加算
    float distance = dist + player->GetRadius();  

	// 距離外なら見えない
    if (toPlayer.GetLengthSq() > distance * distance)
        return false;  

	// 角度を調べる
	Vec2<float> toPlayerN = toPlayer.Normalize();
	// 視野角の半分の余弦値を計算
	float cosThresh = std::cos(ToRad(fov) * 0.5);
	// 内積を計算
	float dp = toPlayerN.Dot(Forward());
	// 視野角内なら見える
	return dp >= cosThresh;
}

void Enemy::Update(float deltaTime)
{
}

void Enemy::Draw(int* image) const
{
	// 本体描画
	DrawCircleAA(pos.x, pos.y, 12, 32, GetColor(255, 0, 0), TRUE);

	// 視界画像描画

	// 角度の調整用
	const float ANGLE_OFFSET = 90.0f;

	// 視野角の範囲を計算
	float startAngle = angle - fov / 2 + ANGLE_OFFSET;  // 視野角の開始角度
	float endAngle = angle + fov / 2 + ANGLE_OFFSET;    // 視野角の終了角度

	// 求めた角度を%に変換する
	double startPercent = startAngle / 360.0 * 100.0; 
	double endPercent = endAngle / 360.0 * 100.0;     

	// 画像のスケール(視界距離に合わせるように)
	const double scale = dist / 100 * 0.8;

	// 扇形の描画
	DrawCircleGaugeF(pos.x, pos.y, endPercent, *image, startPercent, scale);
}
