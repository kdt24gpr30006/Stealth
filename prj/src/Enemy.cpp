#include "Enemy.h"
#include "DxLib.h"

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
 // �v���C���[�̒��S����̋���
    Vec2<float> toPlayer = player->GetPos() - pos;

	// �v���C���[�̔��a�����E�����ɉ��Z
    float distance = dist + player->GetRadius();  

	// �����O�Ȃ猩���Ȃ�
    if (toPlayer.GetLengthSq() > distance * distance)
        return false;  

	// �p�x�𒲂ׂ�
	Vec2<float> toPlayerN = toPlayer.Normalize();
	// ����p�̔����̗]���l���v�Z
	float cosThresh = std::cos(ToRad(fov) * 0.5);
	// ���ς��v�Z
	float dp = toPlayerN.Dot(Forward());
	// ����p���Ȃ猩����
	return dp >= cosThresh;
}

void Enemy::Update(float deltaTime)
{
}

void Enemy::Draw(int* image) const
{
	// �{�̕`��
	DrawCircleAA(pos.x, pos.y, 12, 32, GetColor(255, 0, 0), TRUE);

	// ���E�摜�`��

	// �p�x�̒����p
	const float ANGLE_OFFSET = 90.0f;

	// ����p�͈̔͂��v�Z
	float startAngle = angle - fov / 2 + ANGLE_OFFSET;  // ����p�̊J�n�p�x
	float endAngle = angle + fov / 2 + ANGLE_OFFSET;    // ����p�̏I���p�x

	// ���߂��p�x��%�ɕϊ�����
	double startPercent = startAngle / 360.0 * 100.0; 
	double endPercent = endAngle / 360.0 * 100.0;     

	// �摜�̃X�P�[��(���E�����ɍ��킹��悤��)
	const double scale = dist / 100 * 0.8;

	// ��`�̕`��
	DrawCircleGaugeF(pos.x, pos.y, endPercent, *image, startPercent, scale);
}
