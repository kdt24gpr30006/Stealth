#pragma once

#include "Vec2.h"
#include "Wall.h"
#include <vector>
#include <memory>

class Element
{
	// ゴールの座標
	Vec2<float> goalPos;
	float goalRadius;

	// 壁
	std::vector<std::shared_ptr<Wall>> walls;

	// 壁の情報をcsvから読み込み
	std::vector<std::shared_ptr<Wall>> LoadWallInfo();

public:

	// 壁リストを返す
	const std::vector<std::shared_ptr<Wall>>& GetWalls() const { return walls; }

	// ゴールの座標を返す
	const Vec2<float>& GetGoalPos() const { return goalPos; }
	// ゴールの半径を返す
	const float GetGoalRadius() const { return goalRadius; }

	// コンストラクタ
	Element() : goalRadius(20.0f) {}
	~Element() {}

	// 初期化
	void Init();
	// 描画
	void Render() const;
};