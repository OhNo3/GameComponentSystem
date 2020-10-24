#include "StdAfx.h"
#include "GameProcess.h"
#include "GameProcessManager.h"

GameProcess::GameProcess()
{
}

GameProcess::~GameProcess()
{
}

//メインでの処理内容
//起動
void GameProcess::StartUp(void)
{
	GameProcessManager::Init();
}

//実行
void GameProcess::Run(void)
{
	float deltaTime;

	for (;;)
	{
		if (true)
		{
			deltaTime = 1.f / 60.f; //1FPS == 0.016.....f
		}

		GameProcessManager::ProcessInput();
		GameProcessManager::Update(deltaTime);
		GameProcessManager::GenerateOutput();
		if (true) { break; }
	}
}

//終了化処理
void GameProcess::ShutDown(void)
{
	GameProcessManager::Uninit();
}