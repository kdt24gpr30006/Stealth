#include "Player.h"
#include "CheckInput.h"

bool Player::IsInv()
{
	// –³“GŽžŠÔ“à‚¾‚Á‚½‚çŽžŠÔ‚ðŒ¸‚ç‚µ‚Ätrue‚ð•Ô‚·
	if(invTime > 0)
	{
		invTime--;
		return true;
	}

	// –³“GŽžŠÔŠO
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
	// –³“GŽžŠÔ’†‚Í“_–Å
	if(IsInv())
	{
		InvRender();
	}
}
