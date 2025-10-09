#include "Player.h"
#include "Field.h"
#include "Screen.h"


static const float Gravity = 1;
static const float V0 = -18.0;
bool onGround = 0 ;

//コンストラクタ
//最初に一度だけ実行
Player::Player()
{
	hImage = LoadGraph("data/image/aoi.png");

	x = 100;
	y = 0;
	velocity = 0;
}

Player::Player(int sx, int sy)
{
	hImage = LoadGraph("data/image/aoi.png");

	x = sx;
	y = sy;
	velocity = 0;
}

//デストラクタ
//最後に一度だけ実行
Player::~Player()
{
}

//計算・処理
void Player::Update()
{
	count++;

	if (count >= 10) {
		pat = (pat + 1) % 4;
		count = 0;
	}

	if (CheckHitKey(KEY_INPUT_D)) {
		GoRight();

		Field* field = FindGameObject<Field>();
		int ret = field->HitCheckR(x + 50, y + 5);
		int ret2 = field->HitCheckR(x + 50, y + 63);
		if (ret > 0)
		{ 
			x -= max(ret,ret2); 
		}
	}

	if (CheckHitKey(KEY_INPUT_A)) {
		GoLeft();

		Field* field = FindGameObject<Field>();
		int ret = field->HitCheckL(x + 14, y + 5);
		int ret2 = field->HitCheckL(x + 14, y + 63);
		if (ret > 0)
		{
			x += max(ret, ret2);
		}
	}
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (onGround == 1) {
			velocity = V0;
			onGround = 0;
		}

		Field* field = FindGameObject<Field>();
		int ret = field->HitCheckL(x + 14, y + 5);
		int ret2 = field->HitCheckL(x + 50, y + 63);
		if (ret > 0)
		{
			y += max(ret, ret2);
		}
	}

	y += velocity;
	velocity += Gravity;

	Field* field = FindGameObject<Field>();
	int ret = field->HitCheckD(x + 53, y + 64);;

	if (velocity >= 0) {
		Field* field = FindGameObject<Field>();
		int push1 = field->HitCheckD(x + 14, y + 64); // D点の下 
		int push2 = field->HitCheckD(x + 50, y + 64); // A点の下 
		int push = max(push1, push2);
		if (push > 0) {
			y -= push - 1;
			velocity = 0;
			onGround = true;
		}
		else {
			onGround = false;
		}
	}
	else {
		Field* field = FindGameObject<Field>();
		int push1 = field->HitCheckU(x + 14, y + 5);
		int push2 = field->HitCheckU(x + 50, y + 5);
		int push = max(push1, push2);
		if (push > 0) {
			y += push;
			velocity = 0;
		}
	}

	int sc = field->GetScX();
	if (x - sc >= 300) {
		field->SetScX(x-300);
	}

}
	
//表示
void Player::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScX();
	DrawRectGraph(x- sc, y, 64 * pat, 64 * 0, 64, 64, hImage, 1);
}
