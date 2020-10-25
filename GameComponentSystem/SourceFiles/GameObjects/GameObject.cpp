/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Hoge.cpp] モジュール
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：
=============================================================================*/

/*--- インクルードファイル ---*/
#include "../StdAfx.h"
#include "../GameObjectManager.h"
#include "GameObject.h"
#include "_Component/Component.h"
#include "_Component/TransformComponent.h"



/*-----------------------------------------------------------------------------
/* コンストラクタ
-----------------------------------------------------------------------------*/
GameObject::GameObject(class GameObjectManager* gameObjectManager)
	: game_object_manager_(gameObjectManager)
	, game_object_state_(State::Active)
	, re_compute_transform_(true)
{
	//ゲームオブジェクトを管理先へ追加
	game_object_manager_->AddGameObject(this);

	//ゲームオブジェクトの初期化
	this->Init();
}

/*-----------------------------------------------------------------------------
/* デストラクタ
-----------------------------------------------------------------------------*/
GameObject::~GameObject(void)
{
	this->Uninit();

	game_object_manager_->RemoveGameObject(this);
}

/*-----------------------------------------------------------------------------
/* 初期化処理
-----------------------------------------------------------------------------*/
void GameObject::Init(void)
{
	
}

/*-----------------------------------------------------------------------------
/* 終了化処理
-----------------------------------------------------------------------------*/
void GameObject::Uninit(void)
{
	//コンポーネントの破棄
	while (!components_.empty())
	{
		delete components_.back();
	}
}

/*-----------------------------------------------------------------------------
/* 入力処理
-----------------------------------------------------------------------------*/
void GameObject::Input(void)
{
}

/*-----------------------------------------------------------------------------
/* 更新処理
-----------------------------------------------------------------------------*/
void GameObject::Update(float deltaTime)
{
	UpdateComponents(deltaTime);
	UpdateGameObject(deltaTime);
}

/*-----------------------------------------------------------------------------
/* 更新処理
-----------------------------------------------------------------------------*/
void GameObject::UpdateComponents(float deltaTime)
{
	for (auto components : components_)
	{
		std::cout << "ゲームオブジェクトが更新された" << std::endl;
		components->Update(deltaTime);
	}
}

/*-----------------------------------------------------------------------------
/* 更新処理
-----------------------------------------------------------------------------*/
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

/*=============================================================================
/*		End of File
=============================================================================*/