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
	void Update() override;
	// �`��
	void Render() override;
};