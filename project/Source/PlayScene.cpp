#include "PlayScene.h"
#include "Player.h"
#include "Field.h"
#include "Gameover.h"

PlayScene::PlayScene()
{
	//new Player(100,100);
	new Field();
	new Gameover();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(0, 20, "Push [T]Key To Title", GetColor(255, 255, 255));
}
