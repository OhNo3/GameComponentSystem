#pragma once


class MainProcessManager
{
private:
	MainProcessManager();

public:
	~MainProcessManager();

	//メインプロセス内でのふるまい
	static void Init(void);
	static void Uninit(void);
	static void Input(void);
	static void Update(void);
	static void Draw(void);
private:

};

