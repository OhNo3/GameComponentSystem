#include "MainProcess.h"
#include "MainProcessManager.h"

//���C���ł̏������e
//�N��
void MainProcess::StartUp(void)
{
	MainProcessManager::Init();
}

//���s
void MainProcess::Run(void)
{
	//for (;;)
	if(true)
	{
		MainProcessManager::Input();
		MainProcessManager::Update();
		MainProcessManager::Draw();
	}
}

//�I��������
void MainProcess::ShutDown(void)
{
	MainProcessManager::Uninit();
}