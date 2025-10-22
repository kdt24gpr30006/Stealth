#include "Enemy.h"
#include "DxLib.h"
#include <memory>

// �x�����W�A���ɕϊ�
static float ToRad(float degree)
{
	return degree * static_cast<float>(DX_PI) / 180.0f;
}

// ���W�A����x�ɕϊ�
static float ToDeg(float radian)
{
	return radian * 180.0f / static_cast<float>(DX_PI);
}

void Enemy::SetPatrolRoute(const Vec2<float> route)
{
	patrolRoute.emplace_back(route);
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
	// �����������ꍇ�͌����Ȃ�
	if (toPlayer.GetLengthSq() > dist * dist)
		return false;

	// �p�x�𒲂ׂ�
	Vec2<float> toPlayerN = toPlayer.Normalize();
	// ����p�̔����̗]���l���v�Z
	float cosThresh = static_cast<float>(std::cos(ToRad(fov) * 0.5));
	// ���ς��v�Z
	float dp = toPlayerN.Dot(Forward());
	// ����p���Ȃ猩����
	return dp >= cosThresh;
}

void Enemy::Update(float totalTime)
{
}

void Enemy::Draw(int* image) const
{
	// �{�̕`��
	DrawCircleAA(pos.x, pos.y, 12, 32, GetColor(255, 0, 0), TRUE);

	// ���E�摜�`��
	double lastAngle = static_cast<double>((angle + fov * 0.5f) / 360.0f * 100.0f);
	double startAngle = static_cast<double>((angle - fov * 0.5f) / 360.0f * 100.0f);
	DrawCircleGaugeF(pos.x, pos.y, lastAngle, *image, startAngle, dist);
}
