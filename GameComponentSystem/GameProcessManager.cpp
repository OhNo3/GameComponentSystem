#include "GameProcessManager.h"
#include "GameObjectManager.h"
#include "StdAfx.h"

void GameProcessManager::Init(void)
{
	std::cout << "//////////初期化処理の始まり//////////" << std::endl;
	GameObjectManager::InitAll();

	std::cout << "/*********初期化処理の終わり*********/" << std::endl;
}

void GameProcessManager::Uninit(void)
{
	std::cout << "//////////終了化処理の始まり//////////" << std::endl;
	GameObjectManager::UninitAll();


	std::cout << "/*********終了化処理の終わり*********/" << std::endl;
}

void GameProcessManager::Input(void)
{
	std::cout << "//////////入力処理の始まり//////////" << std::endl;
	GameObjectManager::InputAll();

	std::cout << "/*********入力処理の終わり*********/" << std::endl;
}

void GameProcessManager::Update(void)
{
	std::cout << "//////////更新処理の始まり//////////" << std::endl;
	GameObjectManager::UpdateAll();


	std::cout << "/*********更新処理の終わり*********/" << std::endl;
}

void GameProcessManager::Draw(void)
{
	std::cout << "//////////描画処理の始まり//////////" << std::endl;
	GameObjectManager::DrawAll();


	std::cout << "/*********描画処理の終わり*********/" << std::endl;
}
