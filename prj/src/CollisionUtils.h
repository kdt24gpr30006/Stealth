#pragma once
#include "Vec2.h"
#include "Wall.h"

// ‰~‚Æ•Ç‚ÌÕ“Ë”»’è
bool CheckCircleWithWall(const Vec2<float>& circlePos, float circleRadius, const Wall& wall, Vec2<float>& outPush);
