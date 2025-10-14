#pragma once
#include "CharaBase.h"
#include "WinMain.h"
#include <map>

class Enemy final : public CharaBase
{
public:
	Enemy()
	{
		// �摜�̓ǂݍ���
		imageHandle = LoadGraph("data/enemy.png");
		// ���W�̏�����
		pos.Set(WINDOW_W / 2.0f, WINDOW_H / 2.0f);
		// ���x�̏�����
		velocity.Set(0.0f, 0.0f);
		// ���a�̏�����
		radius = 32;
	}
	~Enemy() {}
	// ����
	void Update() override;
	// �`��
	void Render() override;
};