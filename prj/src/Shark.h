#pragma once
#include "Enemy.h"

class Shark final : public Enemy
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