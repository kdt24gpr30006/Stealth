#pragma once
#include "CharaBase.h"

class Shark final : public CharaBase
{
public:
	Shark()
	{
	}
	~Shark() {}
	// ����
	void Update() override;
	// �`��
	void Render() override;
};