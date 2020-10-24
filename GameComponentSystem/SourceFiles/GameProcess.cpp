#include "StdAfx.h"
#include "GameProcess.h"
#include "GameProcessManager.h"

GameProcess::GameProcess()
{
}

GameProcess::~GameProcess()
{
}

//���C���ł̏������e
//�N��
void GameProcess::StartUp(void)
{
	GameProcessManager::Init();
}

//���s
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

//�I��������
void GameProcess::ShutDown(void)
{
	GameProcessManager::Uninit();
}