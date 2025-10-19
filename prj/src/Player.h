#pragma once
#include "Vec2.h"

class Player
{
	Vec2<float> pos;       // ���W
	float moveSpeed;       // 
public:

	// �R���X�g���N�^
	Player();

	// ���W�擾
	Vec2<float> GetPos() const { return pos; }

	// ����
	void Move(float deltaTime);

	// �X�V
	void Update(float deltaTime);

	// �`��
	void Render() const;
};