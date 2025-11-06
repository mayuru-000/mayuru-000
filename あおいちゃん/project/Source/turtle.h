#pragma once
#include "../Library/GameObject.h"

class Turtle : public GameObject
{
public:
	Turtle();
	Turtle(int sx, int sy);
	~Turtle();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	float x, y;
	bool onGround;
};