#pragma once
#include <vector>
#include <memory>
#include "Var2.h"
#include "Image.h"

class EntityBase
{
protected:
	Var2<float> pos;							// ���W
	Var2<float> velocity;						// ���x
	float radius;								// ���a
	std::vector<std::unique_ptr<Image>> image;	// �摜

public:

	EntityBase() : radius(0){}
	virtual ~EntityBase() {};

	// �X�V
	virtual void Update() = 0;
	// �`��
	virtual void Render() = 0;
};