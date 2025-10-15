#pragma once
#include "EntityBase.h"

class CharaBase : public EntityBase
{
protected:
	bool isTurn;	// ���]���Ă��邩
	float moveSpeed; // �ړ����x
public:
	CharaBase() : isTurn(false), moveSpeed( 0 ) {}
	virtual ~CharaBase() {};

	// ���]�̃Z�b�g
	void SetisTurn(bool turn) {
		isTurn = turn;
	}
};