#include "Wall.h"

void Wall::Render() const
{
	DrawBoxAA(startPos.x, startPos.y, endPos.x, endPos.y, GetColor(100, 255, 100), FALSE);
}
