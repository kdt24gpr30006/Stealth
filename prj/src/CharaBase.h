#pragma once
#include "EntityBase.h"

class CharaBase : public EntityBase
{
protected:
	bool isTurn;	// ”½“]‚µ‚Ä‚¢‚é‚©
	float moveSpeed; // ˆÚ“®‘¬“x
public:
	CharaBase() : isTurn(false), moveSpeed( 0 ) {}
	virtual ~CharaBase() {};

	// ”½“]‚ÌƒZƒbƒg
	void SetisTurn(bool turn) {
		isTurn = turn;
	}
};