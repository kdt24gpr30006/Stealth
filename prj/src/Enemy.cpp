#include "Enemy.h"
#include "DxLib.h"
#include <memory>

// �x�����W�A���ɕϊ�
static float ToRad(float degree)
{
	return degree * static_cast<float>(DX_PI) / 180.0f;
}

Enemy::Enemy(const Vec2<float>& startPos, float argAngle, float argFov, float argDist, float argSpeed)
	: pos(startPos), fov(argFov), dist(argDist), moveSpeed(argSpeed)
{
	angle = ToRad(argAngle);
}

Vec2<float> Enemy::Forward() const
{
	// �O�������x�N�g���ɕϊ����ĕԂ�
	return Vec2<float>(std::cos(ToRad(angle)), std::sin(ToRad(angle)));
}

bool Enemy::CanSeePlayer(const std::shared_ptr<Player> player) const
{
	// ����������
	Vec2<float> toPlayer = player->GetPos() - pos;
	if (toPlayer.GetLengthSq() > dist * dist)
		return false;

	// �p�x�𒲂ׂ�
	Vec2<float> toPlayerN = toPlayer.Normalize();
	// ����p�̔����̗]���l���v�Z
	float cosThresh = static_cast<float>(std::cos(ToRad(fov) * 0.5));
	// ���ς��v�Z
	float dp = toPlayerN.Dot(Forward());
	// �������
	return dp >= cosThresh;
}

void Enemy::Update(float totalTime)
{
	// ��U��A�j���[�V����
	angle += std::sin(totalTime + (pos.x + pos.y) * 0.01f) * 0.5f;
}

void Enemy::Draw(bool detected) const
{
	// �{�̕`��
	DrawCircleAA(pos.x, pos.y, 12, 32, GetColor(255, 0, 0), TRUE);

	// ����`��
	float rad = ToRad(angle);
	// ����p�̔����̃��W�A�����v�Z
	float halfFovRad = ToRad(fov) * 0.5f;
	// ����[�̕����x�N�g�����v�Z
	Vec2<float> leftDir(std::cos(rad - halfFovRad), std::sin(rad - halfFovRad));
	Vec2<float> rightDir(std::cos(rad + halfFovRad), std::sin(rad + halfFovRad));
	// �[�̈ʒu���v�Z
	Vec2<float> leftEnd = pos + leftDir * dist;
	Vec2<float> rightEnd = pos + rightDir * dist;

	// �`��
	DrawLineAA(pos.x, pos.y, leftEnd.x, leftEnd.y, GetColor(200, 200, 200));
	DrawLineAA(pos.x, pos.y, rightEnd.x, rightEnd.y, GetColor(200, 200, 200));
	DrawCircleAA(pos.x, pos.y, dist, 32, GetColor(100, 100, 100), FALSE);

	// �����}�[�N�`��
	if (detected)
		DrawFormatStringF(pos.x, pos.y - 30.0f, GetColor(255, 0, 0), "!!");
}
