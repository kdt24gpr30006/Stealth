#pragma once
#include "CharaBase.h"

class Squid final : public CharaBase
{
public:
	Squid()
	{
	}
	~Squid() {}
	// ����
	void Update() override;
	// �`��
	void Render() override;
};