#pragma once

#include "Vec2.h"

class Wall
{
	Vec2<float> startPos; // 壁の始点座標
	Vec2<float> endPos;   // 壁の終点座標

public:
	
	Wall(const Vec2<float>& start, const Vec2<float>& end)
		: startPos(start), endPos(end) {}

	void Render() const;
};