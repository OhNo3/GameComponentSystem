#include "GameObjectManager.h"
#include "StdAfx.h"

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
}

void GameObjectManager::GenerateOutputAll(void)
{
	std::cout << "ゲームオブジェクトの総出力化\n";
}
