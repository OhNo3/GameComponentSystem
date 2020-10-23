#include "StdAfx.h"
#include "GameProcess.h"

int main()
{
	//起動
	GameProcess* game_process = new GameProcess();
	game_process->StartUp();
	{
		//実行
		game_process->Run();
	}
	//終了
	game_process->ShutDown();
	delete game_process;
}