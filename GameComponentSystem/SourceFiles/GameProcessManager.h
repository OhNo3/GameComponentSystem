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
	static void ProcessInput(void);
	static void Update(float deltaTime);
	static void GenerateOutput(void);
private:
	static class GameObjectManager* game_object_manager_;
};

