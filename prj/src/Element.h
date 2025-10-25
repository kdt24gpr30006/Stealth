#pragma once

#include "Vec2.h"
#include "Wall.h"
#include <vector>
#include <memory>

class Element
{
	// ƒS[ƒ‹‚ÌÀ•W
	Vec2<float> goalPos;

	// •Ç
	std::vector<std::shared_ptr<Wall>> walls;

	// •Ç‚Ìî•ñ‚ğcsv‚©‚ç“Ç‚İ‚İ
	std::vector<std::shared_ptr<Wall>> LoadWallInfo();

public:
	Element() {}
	~Element() {}

	void Init();
	void Update();
	void Render() const;
};