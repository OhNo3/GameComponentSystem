#pragma once
#include "StdAfx.h"
#include "GameObject.h"

class GameObjectManager
{
private:
	GameObjectManager();

public:
	~GameObjectManager();

	static void InitAll(void);
	static void UninitAll(void);
	static void ProcessInputAll(void);
	static void UpdateAll(void);
	static void GenerateOutputAll(void);

private:
	std::vector<GameObject*>  game_object_;
	std::vector<GameObject*>  pending_game_object_;

};

