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
	//for (;;)
	if(true)
	{
		GameProcessManager::ProcessInput();
		GameProcessManager::Update();
		GameProcessManager::GenerateOutput();
	}
}

//�I��������
void GameProcess::ShutDown(void)
{
	GameProcessManager::Uninit();
}