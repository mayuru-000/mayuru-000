#pragma once
#include "../Library/GameObject.h"

class Field :public GameObject
{

public:
	Field();
	~Field();
	void Update() override;
	void Draw() override;

	int HitCheckR(int px, int py);
	int HitCheckL(int px, int py);
	int HitCheckD(int px, int py);
	int HitCheckU(int px, int py);

	int GetScX() { return scrollX; }

	void SetScX(int s) { scrollX = s; }

private:
	int fImage;
	int x, y;

	int fx = 0;
	int fy = 400;
	int scrollX;
};
