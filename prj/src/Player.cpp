#include "Player.h"
#include "WinMain.h"
#include <algorithm>

void Player::Init()
{
	const float startPosX = static_cast<float>(WINDOW_W) / 2.0f;
	const float startPosY = 850.0f;

	pos.Set(startPosX, startPosY);
	radius = 10.0f;
	moveSpeed = 150.0f;
}

void Player::Move(float deltaTime)
{
	Vec2<float> move(0.0f, 0.0f);

	// キーが押されたとき
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

	// 実際の移動処理
	if (move.x != 0.0f || move.y != 0.0f)
	{
		// 向きを取得
		move = move.Normalize();
		// 移動
		pos = pos + move * (moveSpeed * deltaTime);
	}

	// 画面外に出ないよう
	pos.x = std::clamp(pos.x, radius, WINDOW_W - radius);
	pos.y = std::clamp(pos.y, radius, WINDOW_H - radius);
}

void Player::Update(float deltaTime)
{
	Move(deltaTime);
}

void Player::Render() const
{
	DrawCircleAA(pos.x, pos.y, radius, 32, GetColor(255, 255, 255), TRUE);
}
