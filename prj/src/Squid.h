#pragma once
#include "Enemy.h"

class Squid final : public Enemy
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