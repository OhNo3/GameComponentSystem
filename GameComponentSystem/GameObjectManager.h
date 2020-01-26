#pragma once
#include "StdAfx.h"
#include "GameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	class GameObjectManager* Create(void)
	{
		return new GameObjectManager();
	}

	void InitAll(void);
	void UninitAll(void);
	void ProcessInputAll(void);
	void UpdateAll(void);
	void GenerateOutputAll(void);



private:
	std::vector<GameObject*>  game_object_;
	std::vector<GameObject*>  pending_game_object_;

};

