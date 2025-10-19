#include "Player.h"
#include "WinMain.h"

Player::Player()
{
	pos.Set(static_cast<float>(WINDOW_W / 2), 600.0f);
	moveSpeed = 100.0f;
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
	DrawCircle((int)pos.x, (int)pos.y, 8, GetColor(0, 0, 255), TRUE);
}
