#pragma once
#include "CharaBase.h"

class Player final : public CharaBase
{
	int invTime = 0;		// ���G����
	bool isHave = false;	// �����Ă��邩

	// ���G���ǂ���
	bool IsInv();	

	// ���G���Ԃ̊ԓ_��
	void InvRender();

	// ����
	void Move();

public:

	int score = 0;		// �X�R�A

	Player()
	{
		pos.Set(400.0f, 300.0f);
		velocity.Set(0.0f, 0.0f);
		radius = 32;
	}
	~Player() override {

	}

	// �U����H�炤
	void HitDamage();

	// �󔠂̎��ʒu��Ԃ�
	Var2<float> GetHavePos();

	// �X�V
	void Update() override;

	// �`��
	void Render() override;
};