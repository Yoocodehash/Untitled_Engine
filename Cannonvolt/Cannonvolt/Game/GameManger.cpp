#include "GameManger.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{

}

bool GameManager::OnCreate(Character* player_)
{
	playerPtr = player_;
	return false;
}

void GameManager::Update()
{
	if (playerPtr->IsDead()) {
		
		printf("Game Over");

		//Freeze the game due to lack of game over screen
		while (true) {

		}
	}
}
