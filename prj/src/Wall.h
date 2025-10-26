#pragma once

#include "Vec2.h"

class Wall
{

public:
	
	Vec2<float> leftUp;		// 左上座標
	Vec2<float> leftDown;	// 左下座標
	Vec2<float> rightDown;	// 右下座標
	Vec2<float> rightUp;	// 右上座標
	
	Wall(const Vec2<float>& leftUpPos, const Vec2<float>& leftDownPos, const Vec2<float>& rightDownPos, const Vec2<float>& rightUpPos)
		: leftUp(leftUpPos), leftDown(leftDownPos), rightDown(rightDownPos), rightUp(rightUpPos) {}

	// 描画
	void Render() const;
};