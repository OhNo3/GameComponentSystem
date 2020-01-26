#include "GameObject.h"
#include "GameObjectManager.h"
#include "StdAfx.h"



GameObject::GameObject(class GameObjectManager* gameObjectManager)
	: game_object_manager_(gameObjectManager)
	, game_object_state_(GOState_Active)
{
}

GameObject::~GameObject(void)
{
}

void GameObject::Update(float deltaTime)
{


	UpdateComponents(deltaTime);
	UpdateGameObject(deltaTime);

}

void GameObject::UpdateComponents(float deltaTime)
{
	for (auto component : components_)
	{
		component->Update(deltaTime);
	}
}

void GameObject::UpdateGameObject(float deltaTime)
{

}

void GameObject::AddComponent(Component* component)
{
	int my_update_order = component->GetUpdateOrder();

	//���݂���ǉ������R���|�[�l���g��UpdateOrder��
	//�e�R���|�[�l���g��UpdateOrder�Ƃ��r
	//UpdateOrder���~���ɂȂ�悤�ɓK���ǉ����Ă����B
	auto iter = components_.begin();
	for (;
		iter != components_.end();
		++iter)
	{
		if (my_update_order < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}
	components_.insert(iter, component);
}

void GameObject::RemoveComponent(Component* component)
{
	auto iter = std::find(components_.begin()
						, components_.end()
						, component);	//�T���Ώ�

	if (iter != components_.end())
	{
		components_.erase(iter);
	}
}
