#pragma once


class GameProcessManager
{
private:
	GameProcessManager();

public:
	~GameProcessManager();

	//メインプロセス内でのふるまい
	static void Init(void);
	static void Uninit(void);
	static void Input(void);
	static void Update(void);
	static void Draw(void);
private:

};

