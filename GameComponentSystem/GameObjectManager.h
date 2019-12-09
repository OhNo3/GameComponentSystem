#pragma once

class GameObjectManager
{
private:
	GameObjectManager();

public:
	~GameObjectManager();


	static void InitAll(void);
	static void UninitAll(void);
	static void InputAll(void);
	static void UpdateAll(void);
	static void DrawAll(void);



private:
};

