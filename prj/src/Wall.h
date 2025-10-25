#pragma once

#include "Vec2.h"

class Wall
{
	Vec2<float> startPos; // �ǂ̎n�_���W
	Vec2<float> endPos;   // �ǂ̏I�_���W

public:
	
	Wall(const Vec2<float>& start, const Vec2<float>& end)
		: startPos(start), endPos(end) {}

	void Render() const;
};