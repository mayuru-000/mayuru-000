#include "Stone.h"
#include "Field.h"
#include "bird.h"
#include "Screen.h"

Stone::Stone()
{
	hImage = LoadGraph("data/image/stone.png");
}

Stone::Stone(int sx, int sy,float vx,float vy)
{
	x = sx;
	y = sy;
	velocityX = vx;
	velocityY = vy;
	hImage = LoadGraph("data/image/stone.png");

}

Stone::~Stone()
{
}

void Stone::Update()
{
	x += velocityX;
	y += velocityY;

	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	if ((x - sc <= 0) || ((x - sc > Screen::WIDTH))) {
		DestroyMe();
	}
	//bird‚ª1‚Ì‚Æ‚«‚Ì‚Ý
		//Bird* bird = FindGameObject<Bird>();
		//bird->IsHit(x, y);
	//‚¢‚Á‚Ï‚¢‚¢‚é‚Æ‚«
	auto birds = FindGameObjects<Bird>();
	for (auto b : birds) {
		if (b->IsHit(x, y)) {
			DestroyMe();
		}
	}

}

void Stone::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	DrawRectGraph(x - sc, y, 0, 0, 64, 64, hImage, 1);
}

