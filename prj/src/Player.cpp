#include "Player.h"
#include "WinMain.h"

Player::Player()
{
	const float startPosX = static_cast<float>(WINDOW_H) / 2.0f;
	const float startPosY = 600.0f;

	pos.Set(startPosX, startPosY);
	r = 10.0f;
	moveSpeed = 200.0f;
}

void Player::Move(float deltaTime)
{
	Vec2<float> move(0.0f, 0.0f);

	// ƒL[‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
	if (CheckHitKey(KEY_INPUT_W))
	{
		move.y -= 1.0f;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		move.y += 1.0f;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		move.x -= 1.0f;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		move.x += 1.0f;
	}

	// ÀÛ‚ÌˆÚ“®ˆ—
	if (move.x != 0.0f || move.y != 0.0f)
	{
		// Œü‚«‚ğæ“¾
		move = move.Normalize();
		// ˆÚ“®
		pos = pos + move * (moveSpeed * deltaTime);
	}
}

void Player::Update(float deltaTime)
{
	Move(deltaTime);
}

void Player::Render() const
{
	DrawCircleAA(pos.x, pos.y, r, 32, GetColor(0, 0, 255), TRUE);
}
