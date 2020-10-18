#include "GameProcessManager.h"
#include "GameObjectManager.h"
#include "StdAfx.h"

//静的変数宣言
GameObjectManager* GameProcessManager::game_object_manager_ = nullptr;

GameProcessManager::GameProcessManager()
{
}

GameProcessManager::~GameProcessManager()
{
}

void GameProcessManager::Init(void)
{
	std::cout << "//////////初期化処理の始まり//////////\n";
	{ 
		game_object_manager_ = game_object_manager_->Create();
		game_object_manager_->InitAll();
	}
	std::cout << "/*********初期化処理の終わり*********/\n";
	std::cout << "\n";
}

void GameProcessManager::Uninit(void)
{
	std::cout << "//////////終了化処理の始まり//////////\n";
	{
		game_object_manager_->UninitAll();
	}
	std::cout << "/*********終了化処理の終わり*********/\n";
	std::cout << "\n";
}

void GameProcessManager::ProcessInput(void)
{
	std::cout << "//////////入力処理の始まり//////////\n";
	{
		game_object_manager_->ProcessInputAll();
	}
	std::cout << "/*********入力処理の終わり*********/\n";
	std::cout << "\n";
}

void GameProcessManager::Update(void)
{
	std::cout << "//////////更新処理の始まり//////////\n";
	{
		game_object_manager_->UpdateAll();
	}
	std::cout << "/*********更新処理の終わり*********/\n";
	std::cout << "\n";
}

void GameProcessManager::GenerateOutput(void)
{
	std::cout << "//////////描画処理の始まり//////////\n";
	{
		game_object_manager_->GenerateOutputAll();
	}
	std::cout << "/*********描画処理の終わり*********/\n";
	std::cout << "\n";
}
