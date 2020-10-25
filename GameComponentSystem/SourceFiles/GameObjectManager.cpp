#include "StdAfx.h"
#include "GameObjectManager.h"
#include "GameObjects/GameObject.h"

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

void GameObjectManager::UpdateAll(float deltaTime)
{
	std::cout << "ゲームオブジェクトの総更新\n";

	for (auto game_objects_all : game_objects_)
	{
		game_objects_all->Update(deltaTime);
	}

	for (auto pending_game_objects_all : pending_game_objects_) 
	{
		pending_game_objects_all->Update(deltaTime);
	}
}

void GameObjectManager::GenerateOutputAll(void)
{
	std::cout << "ゲームオブジェクトの総出力化\n";
}

void GameObjectManager::AddGameObject(GameObject* gameObject)
{
}

void GameObjectManager::RemoveGameObject(GameObject* gameObject)
{
}
