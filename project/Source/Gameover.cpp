#include "Gameover.h"

Gameover::Gameover()
{
	hImage = LoadGraph("data/image/gameover.png");
}
Gameover::~Gameover()
{

}

void Gameover::Update()
{
}

void Gameover::Draw()
{
	DrawGraph(100, 100, hImage, 1);
}
