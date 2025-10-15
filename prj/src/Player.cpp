#include "Player.h"
#include "CheckInput.h"

template<typename T>
float TO_RAD(T degree)
{
	float PI = 3.1415926535f;
	// 度をラジアンに変換
	return static_cast<float>(degree) * PI / 180.0f;
}

bool Player::IsInv()
{
	// 無敵時間内だったら時間を減らしてtrueを返す
	if (invTime > 0)
	{
		invTime--;
		return true;
	}

	// 無敵時間外
	return false;
}

void Player::InvRender()
{
}

void Player::Move()
{

	// Wキーが押された時
	if (CheckHitKey(KEY_INPUT_W))
	{
		velocity.y -= 1.0f;
	}
	// Sキーが押された時
	if (CheckHitKey(KEY_INPUT_S))
	{
		velocity.y += 1.0f;
	}
	// Aキーが押された時
	if (CheckHitKey(KEY_INPUT_A))
	{
		velocity.x -= 1.0f;
	}
	// Dキーが押された時
	if (CheckHitKey(KEY_INPUT_D))
	{
		velocity.x += 1.0f;
	}

	// 斜め移動の速度調整
	// 移動ベクトルが0でない場合、単位ベクトルに正規化して移動
	if (velocity.x != 0.0f || velocity.y != 0.0f)
	{
		float length = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
		velocity.x /= length; // X方向の単位ベクトル
		velocity.y /= length; // Y方向の単位ベクトル

		pos.x += velocity.x * moveSpeed;
		pos.y += velocity.y * moveSpeed;

		// キャリー状態じゃないとき
		if (state != CARRY)
		{
			// 現在の状態をMOVEに
			state = MOVE;
		}
	
		// 速度を0に戻す
		velocity.x = 0.0f;
		velocity.y = 0.0f;

		// 画像の角度を更新
		UpdateAngle();
	}
	else
	{		
		// キャリー状態じゃないとき
		if (state != CARRY)
		{
			// 現在の状態をIDLEに
			state = IDLE;
		}
	}

}

void Player::UpdateAngle()
{
	// 画像の角度定数
	const int UP_ANGLE = 90;
	const int DOWN_ANGLE = 270;
	const int LEFT_ANGLE = 0;

	// 斜め移動時の角度
	const int ADDANGLE = 45;

	// 反転しているか
	isTurn = false;
	
	// 押されているキーによって画像の角度を変更
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
	// 座標の初期化
	pos.Set(400.0f, 300.0f);

	// 速度の初期化
	velocity.Set(0.0f, 0.0f);

	// 移動速度の設定
	moveSpeed = 3.0f;

	// 半径の初期化
	radius = 50;

	// 画像の読み込み
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
	// 無敵時間中は何もしない
	if (IsInv()) return;

	// 無敵時間を設定
	invTime = 120;

	// 宝箱を落とす
	isHave = false;
	state = IDLE;
}

void Player::PickUp()
{
	// 無敵時間中は拾えない
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
	// 画像の描画
	DrawRotaGraphF(pos.x, pos.y, 0.4, TO_RAD(imageAngle), image[state]->image, TRUE, isTurn);

	// 無敵時間中は点滅
	if (IsInv())
	{
		InvRender();
	}


#if _DEBUG
	// 当たり判定の円を描画
	DrawCircleAA(pos.x, pos.y, radius, 32, GetColor(255, 0, 0), FALSE);
#endif // _DEBUG
}
