#pragma once
#include "Var2.h"

class EntityBase
{
protected:
	Var2<float> pos;		// ���W
	Var2<float> velocity;	// ���x
	int radius;				// ���a
	int imageHandle;		// �摜�n���h��

public:

	EntityBase() : radius(0), imageHandle(-1) {}
	virtual ~EntityBase() {};

	// �X�V
	virtual void Update() = 0;
	// �`��
	virtual void Render() = 0;
};