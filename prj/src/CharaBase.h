#pragma once
#include "EntityBase.h"

class CharaBase : public EntityBase
{
protected:
	bool isturn;	// ”½“]‚µ‚Ä‚¢‚é‚©
public:
	CharaBase() : isturn(false) {}
	virtual ~CharaBase() {};

	// ”½“]‚ÌƒZƒbƒg
	void SetIsTurn(bool turn) {
		isturn = turn;
	}
};