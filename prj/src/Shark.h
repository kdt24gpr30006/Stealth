#pragma once
#include "CharaBase.h"

class Shark final : public CharaBase
{
public:
	Shark()
	{
		// ‰æ‘œ‚Ì“Ç‚İ‚İ
		imageHandle = LoadGraph("");
	}
	~Shark() {}
	// “®‚«
	void Update() override;
	// •`‰æ
	void Render() override;
};