#pragma once


class MainProcessManager
{
private:
	MainProcessManager();

public:
	~MainProcessManager();

	//���C���v���Z�X���ł̂ӂ�܂�
	static void Init(void);
	static void Uninit(void);
	static void Input(void);
	static void Update(void);
	static void Draw(void);
private:

};

