#include "GameObjectManager.h"
#include "StdAfx.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::InitAll(void)
{
	std::cout << "ゲームオブジェクトの総初期化\n";
}

void GameObjectManager::UninitAll(void)
{
	std::cout << "ゲームオブジェクトの総終了化\n";
}

void GameObjectManager::ProcessInputAll(void)
{
	std::cout << "ゲームオブジェクトの総入力\n";
}

void GameObjectManager::UpdateAll(void)
{
	std::cout << "ゲームオブジェクトの総更新\n";

	for (auto game_objects_all : game_object_)
	{
		game_objects_all->Update(16.0f);
	}

	for (auto pending_game_objects_all : pending_game_object_)
	{

	}
}

void GameObjectManager::GenerateOutputAll(void)
{
	std::cout << "ゲームオブジェクトの総出力化\n";
}
