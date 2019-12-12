#include "GameProcessManager.h"
#include "GameObjectManager.h"
#include "StdAfx.h"

void GameProcessManager::Init(void)
{
	std::cout << "//////////初期化処理の始まり//////////\n";
	{
		GameObjectManager::InitAll();




	}
	std::cout << "/*********初期化処理の終わり*********/\n";
	std::cout << "\n";
}

void GameProcessManager::Uninit(void)
{
	std::cout << "//////////終了化処理の始まり//////////\n";
	{
		GameObjectManager::UninitAll();

	}
	std::cout << "/*********終了化処理の終わり*********/\n";
	std::cout << "\n";
}

void GameProcessManager::ProcessInput(void)
{
	std::cout << "//////////入力処理の始まり//////////\n";
	{
		GameObjectManager::InputAll();


	}
	std::cout << "/*********入力処理の終わり*********/\n";
	std::cout << "\n";
}

void GameProcessManager::Update(void)
{
	std::cout << "//////////更新処理の始まり//////////\n";
	{
		GameObjectManager::UpdateAll();

	}
	std::cout << "/*********更新処理の終わり*********/\n";
	std::cout << "\n";
}

void GameProcessManager::GenerateOutput(void)
{
	std::cout << "//////////描画処理の始まり//////////\n";
	{
		GameObjectManager::DrawAll();

	}
	std::cout << "/*********描画処理の終わり*********/\n";
	std::cout << "\n";
}
