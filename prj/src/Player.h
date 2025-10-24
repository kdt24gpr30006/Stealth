#pragma once
#include "Vec2.h"

class Player
{
	Vec2<float> pos;	// ���W
	float r;			// ���a
	float moveSpeed;	// �ړ����x

public:

	// ���W�̃Q�b�^�[
	Vec2<float> GetPos() const { return pos; }

	// ���a�̃Q�b�^�[
	float GetRadius() const { return r; }


	// �R���X�g���N�^
	Player();

	// ����
	void Move(float deltaTime);

	// �X�V
	void Update(float deltaTime);

	// �`��
	void Render() const;
};