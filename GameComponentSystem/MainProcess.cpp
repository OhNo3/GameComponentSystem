#include "MainProcess.h"
#include "MainProcessManager.h"

MainProcess::MainProcess()
{
}

MainProcess::~MainProcess()
{
}

//メインでの処理内容
//起動
void MainProcess::StartUp(void)
{
	MainProcessManager::Init();
}

//実行
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

//終了化処理
void MainProcess::ShutDown(void)
{
	MainProcessManager::Uninit();
}