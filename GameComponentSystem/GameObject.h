#pragma once

#include "StdAfx.h"
#include "Component/Component.h"
#include "Component/TransformComponent.h"

class GameObject
{
public:
	enum GameObjectTypeID
	{
		TActor = 0,
		TFollowObject,
		TTargetObject,

		NUM_GAMEOBJECT_TYPES
	};

	static const char* GameObjectTypeNames[NUM_GAMEOBJECT_TYPES];
	
	enum GameObjectState
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
	//GameObject�̏��
	GameObjectState state_;

	//���L�R���|�[�l���g
	std::vector<Component*> component_;

};

