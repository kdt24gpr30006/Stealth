#pragma once
#include "Vec2.h"

class Player
{
	Vec2<float> pos;       // 座標
	float moveSpeed;       // 
public:

	// コンストラクタ
	Player();

	// 座標取得
	Vec2<float> GetPos() const { return pos; }

	// 動き
	void Move(float deltaTime);

	// 更新
	void Update(float deltaTime);

	// 描画
	void Render() const;
};