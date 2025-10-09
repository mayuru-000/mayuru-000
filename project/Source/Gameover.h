#pragma once
#include "../Library/GameObject.h"

class Gameover:public GameObject
{
public:
	Gameover();
	~Gameover();
	void Update() override;
	void Draw() override;

private:
	int hImage;
};

