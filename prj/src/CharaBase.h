#pragma once
#include "EntityBase.h"

class CharaBase : public EntityBase
{
protected:
	bool isturn;	// ���]���Ă��邩
public:
	CharaBase() : isturn(false) {}
	virtual ~CharaBase() {};

	// ���]�̃Z�b�g
	void SetIsTurn(bool turn) {
		isturn = turn;
	}
};