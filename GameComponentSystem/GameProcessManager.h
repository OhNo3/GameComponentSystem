#pragma once


class GameProcessManager
{
private:
	GameProcessManager();

public:
	~GameProcessManager();

	//���C���v���Z�X���ł̂ӂ�܂�
	static void Init(void);
	static void Uninit(void);
	static void ProcessInput(void);
	static void Update(void);
	static void GenerateOutput(void);
private:

};

