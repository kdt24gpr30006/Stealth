#pragma once

#include "Vec2.h"
#include "Player.h"
#include <cmath>
#include <memory>
#include <vector>

class Enemy
{
	Vec2<float> pos;    // 座標
	float r;			// 半径
	float angle;		// 向き
	float fov;			// 視野角
	float dist;			// 視界距離
	float moveSpeed;	// 移動速度

	int nextPosIndex = 0; // 次の巡回地点のインデックス

	std::vector<Vec2<float>> patrolRoute;	// 巡回経路

	// 前方向をベクトルに変換
	Vec2<float> Forward() const;

public:

	// コンストラクタ
	Enemy(const Vec2<float>& startPos, float argR, float argAngle, float argFov, float argDist, float argSpeed)
		: pos(startPos), r(argR), angle(argAngle), fov(argFov), dist(argDist), moveSpeed(argSpeed){}

	// 巡回経路の設定
	void SetPatrolRoute(const Vec2<float> route);

	// プレイヤーが見えているか
	bool CanSeePlayer(const std::shared_ptr<Player> player) const;
	// 更新
	void Update(float deltaTime);
	// 描画
	void Render(int* image) const;
};

