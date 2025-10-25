#pragma once

#include "Vec2.h"
#include "Player.h"
#include <cmath>
#include <memory>
#include <vector>

class Enemy
{
	Vec2<float> pos;    // ���W
	float r;			// ���a
	float angle;		// ����
	float fov;			// ����p
	float dist;			// ���E����
	float moveSpeed;	// �ړ����x

	int nextPosIndex = 0; // ���̏���n�_�̃C���f�b�N�X

	std::vector<Vec2<float>> patrolRoute;	// ����o�H

	// �O�������x�N�g���ɕϊ�
	Vec2<float> Forward() const;

public:

	// �R���X�g���N�^
	Enemy(const Vec2<float>& startPos, float argR, float argAngle, float argFov, float argDist, float argSpeed)
		: pos(startPos), r(argR), angle(argAngle), fov(argFov), dist(argDist), moveSpeed(argSpeed){}

	// ����o�H�̐ݒ�
	void SetPatrolRoute(const Vec2<float> route);

	// �v���C���[�������Ă��邩
	bool CanSeePlayer(const std::shared_ptr<Player> player) const;
	// �X�V
	void Update(float deltaTime);
	// �`��
	void Render(int* image) const;
};

