#pragma once
#include "CharaBase.h"

class Squid final : public CharaBase
{
public:
	Squid()
	{
		// ‰æ‘œ‚Ì“Ç‚İ‚İ
		imageHandle = LoadGraph("");
	}
	~Squid() {}
	// “®‚«
	void Move() override;
	// •`‰æ
	void Render() override;
};