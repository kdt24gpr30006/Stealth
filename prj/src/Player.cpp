#include "Player.h"

void Player::HitDamage()
{
}

void Player::InvRender()
{
}

Var2<float> Player::GetHavePos()
{
	return Var2<float>();
}

void Player::Move()
{
}

void Player::Render()
{
	// –³“GŽžŠÔ’†‚Í“_–Å
	if(invTime > 0)
	{
		InvRender();
	}
	
}
