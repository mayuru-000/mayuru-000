#include "bird.h"
#include "Field.h"
#include "Screen.h"

static const float Gravity = 0.2;
static const float V0 = -10.0;

Bird::Bird()
{
	hImage = LoadGraph("data/image/mob.png");
	x = 200;
	y = 500;
}

Bird::Bird(int sx, int sy)
{
	hImage = LoadGraph("data/image/mob.png");
	x = sx;
	y = sy;
}

Bird::~Bird()
{
}

void Bird::Update()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	//•\Ž¦À•W‚Í(x-sc,y)
	if (x - sc > Screen::WIDTH) {
		return;
	}
	if (x - sc <= -64) {
		DestroyMe();
	}
	x -= 1.5f;
}

void Bird::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	DrawRectGraph(x - sc, y, 0, 0, 64, 64, hImage, 1);
}

bool Bird::IsHit(float tx, float ty)
{
	float dx = tx - x;
	float dy = ty - y;
	float d = sqrt(dx * dx + dy * dy);

	if (d < 30 + 5) {
		DestroyMe();
	}
	return false;
}
