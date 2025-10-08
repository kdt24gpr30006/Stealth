#pragma once
#include "CharaBase.h"
#include <map>
#include "WinMain.h"

class Enemy final : public CharaBase
{

public:
	Enemy()
	{
		// ‰æ‘œ‚Ì“Ç‚İ‚İ
		imageHandle = LoadGraph("data/enemy.png");
		// À•W‚Ì‰Šú‰»
		pos.Set(WINDOW_W / 2.0f, WINDOW_H / 2.0f);
		// ‘¬“x‚Ì‰Šú‰»
		velocity.Set(0.0f, 0.0f);
		// ”¼Œa‚Ì‰Šú‰»
		radius = 32;
	}
	~Enemy() {}
	// “®‚«
	void Move() override;
	// •`‰æ
	void Render() override;
};