#pragma once
#include "CharaBase.h"

class Shark final : public CharaBase
{
public:
	Shark()
	{
		// �摜�̓ǂݍ���
		imageHandle = LoadGraph("");
	}
	~Shark() {}
	// ����
	void Move() override;
	// �`��
	void Render() override;
};