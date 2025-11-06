#include "turtle.h"
#include "Field.h"

static const float Gravity = 0.2;
static const float V0 = -10.0;

Turtle::Turtle()
{
	hImage = LoadGraph("data/image/mob.png");
	x = 200;
	y = 500;
	onGround = false;
}

Turtle::Turtle(int sx, int sy)
{
	hImage = LoadGraph("data/image/mob.png");
	x = sx;
	y = sy;
	onGround = false;
}

Turtle::~Turtle()
{
}

void Turtle::Update()
{

}

void Turtle::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	DrawRectGraph(x - sc, y, 0, 64*5, 64, 64, hImage, 1);
}
