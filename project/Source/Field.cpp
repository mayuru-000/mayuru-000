#include "Field.h"
#include "Player.h"
#include <vector>
using namespace std;

vector<vector<int>> maps = { 

	{ 0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
	{ 0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1 },
	{ 0,2,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

Field::Field()
{
	scrollX = 0;

	fImage = LoadGraph("data/image/bgchar.png");

	for (y = 0; y < maps.size(); y++) {
		for (x = 0; x < maps[y].size(); x++) {
			if (maps[y][x] == 2) {
				//DrawRectGraph((x * 64), fy + (y * 64), 0, 32, 64, 64, fImage, 1);
				new Player(x * 64, fy + (y * 64));
			}
		}
	}
}

Field::~Field()
{
}

void Field::Update()
{
	//scrollX  += 1;   //‹­§ƒXƒNƒ[ƒ‹
}

void Field::Draw()
{
	for (y = 0; y < maps.size(); y++) {
		for (x = 0; x < maps[y].size(); x++) {
			if (maps[y][x] == 1) {
				DrawRectGraph((x * 64) - scrollX, fy + (y * 64), 0, 32, 64, 64, fImage, 1);
			}
		}
	}
}

int Field::HitCheckR(int px, int py)
{
	if (py < 400) { return 0; }
	if (px < 0) { return 0; }
	if (maps[(py - fy) / 64][px / 64] == 1)
	{ 
		return px % 64 + 1;
	}
	return 0;
}

int Field::HitCheckL(int px, int py)
{
	if (py < 400) { return 0; }
	if (px < 0) { return 0; }
	if (maps[(py - fy) / 64][px / 64] == 1)
	{
		return 64 - px % 64;
	}
	return 0;
}

int Field::HitCheckD(int px, int py)
{
	if (py < 400) { return 0; }
	if (px < 0) { return 0; }
	if (maps[(py - fy) / 64][px / 64] == 1)
	{
		return (py - 400) % 64 + 1;
	}
	return 0;
}

int Field::HitCheckU(int px, int py)
{
	if (py < 400) { return 0; }
	if (px < 0) { return 0; }
	if (maps[(py - fy) / 64][px / 64] == 1)
	{
		return 64 - (py - fy) % 64;
	}
	return 0;
}
