#pragma once
#include "StdAfx.h"
#include "GameObject/GameObject.h"

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
	void UpdateAll(float deltaTime);
	void GenerateOutputAll(void);

	void AddGameObject(class GameObject* gameObject);
	void RemoveGameObject(class GameObject* gameObject);

private:
	std::vector<GameObject*>  game_objects_;
	std::vector<GameObject*>  pending_game_objects_;
};

