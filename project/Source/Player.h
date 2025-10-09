#pragma once
#include "../Library/GameObject.h"

class Player:public GameObject
{

public:
	Player();
	Player(int sx, int sy);
	~Player();
	void Update() override;
	void Draw() override;
	void GoRight(){ x += sp; }
	void GoLeft(){ x -= sp; }

private:

	int hImage;
	int count = 0;
	int pat = 0;
	float x, y;
	float sp = 10;
	float velocity;
	const int CHR_SIZE = 64;
};