#pragma once
#include "Vec2.h"
#include "Player.h"
#include <cmath>
#include <memory>

class Enemy
{
	Vec2<float> pos;    // 座標
	float angle;		// 向き（度）
	float fov;			// 視野角
	float dist;			// 視界距離(px)
	float moveSpeed;	// 移動速度

	// 前方向をベクトルに変換
	Vec2<float> Forward() const;

public:

	Enemy(const Vec2<float>& startPos, float argAngle, float argFov, float argDist, float argSpeed);
	// プレイヤーが見えているか
	bool CanSeePlayer(const std::shared_ptr<Player> player) const;
	// 更新
	void Update(float totalTime);
	// 描画
	void Draw(bool detected) const;
};
