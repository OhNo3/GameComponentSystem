
#include "MainProcess.h"

int main()
{
	//起動
	MainProcess* main_process = new MainProcess();
	main_process->StartUp();
	{
		//実行
		main_process->Run();
	}
	//終了
	main_process->ShutDown();
	delete main_process;
}