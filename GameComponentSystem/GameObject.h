#pragma once

#include "StdAfx.h"
#include "Component/Component.h"
#include "Component/TransformComponent.h"

class GameObject
{
public:
	enum TypeID
	{
		TActor = 0,
		TFollowObject,
		TTargetObject,

		NUM_GAMEOBJECT_TYPES
	};

	static const char* TypeNames[NUM_GAMEOBJECT_TYPES];
	
	enum GOState
	{
		GOActive = 0,
		GOPaused,
		GODead
	};

	GameObject();
	virtual ~GameObject(void);


	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

private:
	//GameObjectの状態
	GOState state_;

	//所有コンポーネント
	std::vector<Component*> component_;

};

