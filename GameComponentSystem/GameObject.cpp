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

	//現在から追加されるコンポーネントのUpdateOrderと
	//各コンポーネントのUpdateOrderとを比較
	//UpdateOrderが降順になるように適時追加していく。
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
						, component);	//探す対象

	if (iter != components_.end())
	{
		components_.erase(iter);
	}
}
