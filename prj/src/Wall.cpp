#include "Wall.h"

void Wall::Render() const
{
	DrawLineAA(leftUp.x, leftUp.y, rightUp.x, rightUp.y, GetColor(0, 255, 0));
	DrawLineAA(rightUp.x, rightUp.y, rightDown.x, rightDown.y, GetColor(0, 255, 0));
	DrawLineAA(rightDown.x, rightDown.y, leftDown.x, leftDown.y, GetColor(0, 255, 0));
	DrawLineAA(leftDown.x, leftDown.y, leftUp.x, leftUp.y, GetColor(0, 255, 0));
}