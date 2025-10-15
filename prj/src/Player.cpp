#include "Player.h"
#include "CheckInput.h"

template<typename T>
float TO_RAD(T degree)
{
	float PI = 3.1415926535f;
	// �x�����W�A���ɕϊ�
	return static_cast<float>(degree) * PI / 180.0f;
}

bool Player::IsInv()
{
	// ���G���ԓ��������玞�Ԃ����炵��true��Ԃ�
	if (invTime > 0)
	{
		invTime--;
		return true;
	}

	// ���G���ԊO
	return false;
}

void Player::InvRender()
{
}

void Player::Move()
{

	// W�L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_W))
	{
		velocity.y -= 1.0f;
	}
	// S�L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_S))
	{
		velocity.y += 1.0f;
	}
	// A�L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_A))
	{
		velocity.x -= 1.0f;
	}
	// D�L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_D))
	{
		velocity.x += 1.0f;
	}

	// �΂߈ړ��̑��x����
	// �ړ��x�N�g����0�łȂ��ꍇ�A�P�ʃx�N�g���ɐ��K�����Ĉړ�
	if (velocity.x != 0.0f || velocity.y != 0.0f)
	{
		float length = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
		velocity.x /= length; // X�����̒P�ʃx�N�g��
		velocity.y /= length; // Y�����̒P�ʃx�N�g��

		pos.x += velocity.x * moveSpeed;
		pos.y += velocity.y * moveSpeed;

		// �L�����[��Ԃ���Ȃ��Ƃ�
		if (state != CARRY)
		{
			// ���݂̏�Ԃ�MOVE��
			state = MOVE;
		}
	
		// ���x��0�ɖ߂�
		velocity.x = 0.0f;
		velocity.y = 0.0f;

		// �摜�̊p�x���X�V
		UpdateAngle();
	}
	else
	{		
		// �L�����[��Ԃ���Ȃ��Ƃ�
		if (state != CARRY)
		{
			// ���݂̏�Ԃ�IDLE��
			state = IDLE;
		}
	}

}

void Player::UpdateAngle()
{
	// �摜�̊p�x�萔
	const int UP_ANGLE = 90;
	const int DOWN_ANGLE = 270;
	const int LEFT_ANGLE = 0;

	// �΂߈ړ����̊p�x
	const int ADDANGLE = 45;

	// ���]���Ă��邩
	isTurn = false;
	
	// ������Ă���L�[�ɂ���ĉ摜�̊p�x��ύX
	if (CheckHitKey(KEY_INPUT_W) && CheckHitKey(KEY_INPUT_A))
	{
		imageAngle = LEFT_ANGLE + ADDANGLE;
	}
	else if (CheckHitKey(KEY_INPUT_W) && CheckHitKey(KEY_INPUT_D))
	{
		imageAngle = DOWN_ANGLE + ADDANGLE;
		isTurn = true;
	}
	else if (CheckHitKey(KEY_INPUT_S) && CheckHitKey(KEY_INPUT_A))
	{
		imageAngle = DOWN_ANGLE + ADDANGLE;
	}
	else if (CheckHitKey(KEY_INPUT_S) && CheckHitKey(KEY_INPUT_D))
	{
		imageAngle = LEFT_ANGLE + ADDANGLE;
		isTurn = true;
	}
	else if(CheckHitKey(KEY_INPUT_W))
	{
		imageAngle = UP_ANGLE;
	}
	else if (CheckHitKey(KEY_INPUT_A))
	{
		imageAngle = LEFT_ANGLE;
	}
	else if (CheckHitKey(KEY_INPUT_S))
	{
		imageAngle = UP_ANGLE;
		isTurn = true;
	}
	else if (CheckHitKey(KEY_INPUT_D))
	{
		imageAngle = LEFT_ANGLE;
		isTurn = true;
	}
}

Player::Player()
{
	// ���W�̏�����
	pos.Set(400.0f, 300.0f);

	// ���x�̏�����
	velocity.Set(0.0f, 0.0f);

	// �ړ����x�̐ݒ�
	moveSpeed = 3.0f;

	// ���a�̏�����
	radius = 50;

	// �摜�̓ǂݍ���
	image.reserve(MAX);
	for (int i = 0; i < MAX; i++)
	{
		image.push_back(std::make_unique<Image>());
	}
	image[IDLE]->Load("data/player/Idle.png");
	image[MOVE]->Load("data/player/Move.png");
	image[CARRY]->Load("data/player/Carry.png");
}
Var2<float> Player::GetHavePos()
{
	return Var2<float>();
}

void Player::HitDamage()
{
	// ���G���Ԓ��͉������Ȃ�
	if (IsInv()) return;

	// ���G���Ԃ�ݒ�
	invTime = 120;

	// �󔠂𗎂Ƃ�
	isHave = false;
	state = IDLE;
}

void Player::PickUp()
{
	// ���G���Ԓ��͏E���Ȃ�
	if (IsInv()) return;

	isHave = true;
	state = CARRY;
}

void Player::Update()
{
	Move();
}

void Player::Render()
{
	// �摜�̕`��
	DrawRotaGraphF(pos.x, pos.y, 0.4, TO_RAD(imageAngle), image[state]->image, TRUE, isTurn);

	// ���G���Ԓ��͓_��
	if (IsInv())
	{
		InvRender();
	}


#if _DEBUG
	// �����蔻��̉~��`��
	DrawCircleAA(pos.x, pos.y, radius, 32, GetColor(255, 0, 0), FALSE);
#endif // _DEBUG
}
