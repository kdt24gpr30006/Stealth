#pragma once
#include "CharaBase.h"

class Squid final : public CharaBase
{
public:
	Squid()
	{
		// �摜�̓ǂݍ���
		imageHandle = LoadGraph("");
	}
	~Squid() {}
	// ����
	void Move() override;
	// �`��
	void Render() override;
};