#pragma once
#include "Vec2.h"
#include "Player.h"
#include <cmath>
#include <memory>

class Enemy
{
	Vec2<float> pos;    // ���W
	float angle;		// �����i�x�j
	float fov;			// ����p
	float dist;			// ���E����(px)
	float moveSpeed;	// �ړ����x

	// �O�������x�N�g���ɕϊ�
	Vec2<float> Forward() const;

public:

	Enemy(const Vec2<float>& startPos, float argAngle, float argFov, float argDist, float argSpeed);
	// �v���C���[�������Ă��邩
	bool CanSeePlayer(const std::shared_ptr<Player> player) const;
	// �X�V
	void Update(float totalTime);
	// �`��
	void Draw(bool detected) const;
};
