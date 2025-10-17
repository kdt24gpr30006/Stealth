#pragma once
#include "CharaBase.h"
#include "WinMain.h"
#include <map>

class Enemy : public CharaBase
{
public:
	Enemy()
	{
		// ���W�̏�����
		pos.Set(WINDOW_W / 2.0f, WINDOW_H / 2.0f);
		// ���x�̏�����
		velocity.Set(0.0f, 0.0f);
		// ���a�̏�����
		radius = 32;
	}
	~Enemy() {}
	// ����
	virtual void Update() = 0;
	// �`��
	virtual void Render() = 0;
};