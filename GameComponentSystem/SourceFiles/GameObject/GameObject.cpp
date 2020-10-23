#include "../StdAfx.h"
#include "../GameObjectManager.h"
#include "GameObject.h"
#include "Component/Component.h"
#include "Component/TransformComponent.h"


GameObject::GameObject(class GameObjectManager* gameObjectManager)
	: game_object_manager_(gameObjectManager)
	, game_object_state_(Active)
	, transform_component_(new TransformComponent())
	, re_compute_transform_(true)
{
	//ゲームオブジェクトを管理先へ追加
	game_object_manager_->AddGameObject(this);

	//ゲームオブジェクトの初期化
	this->Init();
}

GameObject::~GameObject(void)
{
	this->Uninit();

	game_object_manager_->RemoveGameObject(this);
}
  
void GameObject::Init(void)
{
	
}

void GameObject::Uninit(void)
{
	//姿勢情報の破棄
	delete transform_component_;

	//コンポーネントの破棄
	while (!components_.empty())
	{
		delete components_.back();
	}
}

void GameObject::Update(float deltaTime)
{
	UpdateComponents(deltaTime);
	UpdateGameObject(deltaTime);
}

void GameObject::UpdateComponents(float deltaTime)
{
	for (auto components : components_)
	{
		components->Update(deltaTime);
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