#pragma once

#include "../StdAfx.h"
#include "Component/Component.h"
#include "Component/TransformComponent.h"

class GameObject
{
public:
	enum GameObjectTypeID
	{
		GO_Actor = 0,
		GO_Follow,
		GO_Target,

		NUM_GAMEOBJECT_TYPES
	};

	static const char* GameObjectTypeNames[NUM_GAMEOBJECT_TYPES];
	
	enum GameObjectState
	{
		GOState_Active = 0,
		GOState_Paused,
		GOState_Dead
	};

	GameObject(class GameObjectManager* gameObjectManager);
	virtual ~GameObject(void);


	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	void UpdateGameObject(float deltaTime);

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	void SetGameObjectState(GameObjectState state) { game_object_state_ = state; };
	GameObjectState GetGameObjectState(void) { return game_object_state_; }

private:
	//GameObjectの所有者
	class GameObjectManager* game_object_manager_;

	//GameObjectの状態
	GameObjectState game_object_state_;

	//所有コンポーネント
	std::vector<Component*> components_;

};

