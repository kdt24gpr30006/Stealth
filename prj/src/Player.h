#pragma once
#include "CharaBase.h"
#include <string>


enum PlayerState
{
	IDLE,
	MOVE,
	CARRY,
	MAX,
};

class Player final : public CharaBase
{
	int invTime = 0;			// ���G����
	bool isHave = false;		// �����Ă��邩
	PlayerState state = MOVE;	// ���
	int imageAngle = 0;			// �摜�̊p�x

	// ���G���ǂ���
	bool IsInv();

	// ���G���Ԃ̊ԓ_��
	void InvRender();

	// ����
	void Move();

	// �摜�p�x�̍X�V
	void UpdateAngle();

public:

	int score = 0;		// �X�R�A

	Player();
	~Player() override {

	}

	// �U����H�炤
	void HitDamage();

	// �󔠂��E��
	void PickUp();

	// �󔠂̎��ʒu��Ԃ�
	Var2<float> GetHavePos();

	// �X�V
	void Update() override;

	// �`��
	void Render() override;
};