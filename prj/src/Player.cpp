#include "Player.h"
#include "CheckInput.h"

bool Player::IsInv()
{
	// ���G���ԓ��������玞�Ԃ����炵��true��Ԃ�
	if(invTime > 0)
	{
		invTime--;
		return true;
	}

	// ���G���ԊO
	return false;
}

void Player::InvRender()
{
}

void Player::Move()
{
}

Var2<float> Player::GetHavePos()
{
	return Var2<float>();
}

void Player::HitDamage()
{
}

void Player::Update()
{
	Move();
}

void Player::Render()
{
	// ���G���Ԓ��͓_��
	if(IsInv())
	{
		InvRender();
	}
}
