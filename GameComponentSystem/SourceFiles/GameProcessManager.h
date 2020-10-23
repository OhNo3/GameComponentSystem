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
	static void Update(float deltaTime);
	static void GenerateOutput(void);
private:
	static class GameObjectManager* game_object_manager_;
};

