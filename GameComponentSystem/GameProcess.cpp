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
		GameProcessManager::Input();
		GameProcessManager::Update();
		GameProcessManager::Draw();
	}
}

//�I��������
void GameProcess::ShutDown(void)
{
	GameProcessManager::Uninit();
}