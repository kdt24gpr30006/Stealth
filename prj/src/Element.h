#pragma once

#include "Vec2.h"
#include "Wall.h"
#include <vector>
#include <memory>

class Element
{
	// �S�[���̍��W
	Vec2<float> goalPos;

	// ��
	std::vector<std::shared_ptr<Wall>> walls;

	// �ǂ̏���csv����ǂݍ���
	std::vector<std::shared_ptr<Wall>> LoadWallInfo();

public:
	Element() {}
	~Element() {}

	void Init();
	void Update();
	void Render() const;
};