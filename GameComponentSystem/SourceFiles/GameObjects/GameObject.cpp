/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Hoge.cpp] ���W���[��
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F
=============================================================================*/

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../StdAfx.h"
#include "../GameObjectManager.h"
#include "GameObject.h"
#include "_Component/Component.h"
#include "_Component/TransformComponent.h"



/*-----------------------------------------------------------------------------
/* �R���X�g���N�^
-----------------------------------------------------------------------------*/
GameObject::GameObject(class GameObjectManager* gameObjectManager)
	: game_object_manager_(gameObjectManager)
	, game_object_state_(State::Active)
	, re_compute_transform_(true)
{
	//�Q�[���I�u�W�F�N�g���Ǘ���֒ǉ�
	game_object_manager_->AddGameObject(this);

	//�Q�[���I�u�W�F�N�g�̏�����
	this->Init();
}

/*-----------------------------------------------------------------------------
/* �f�X�g���N�^
-----------------------------------------------------------------------------*/
GameObject::~GameObject(void)
{
	this->Uninit();

	game_object_manager_->RemoveGameObject(this);
}

/*-----------------------------------------------------------------------------
/* ����������
-----------------------------------------------------------------------------*/
void GameObject::Init(void)
{
	
}

/*-----------------------------------------------------------------------------
/* �I��������
-----------------------------------------------------------------------------*/
void GameObject::Uninit(void)
{
	//�R���|�[�l���g�̔j��
	while (!components_.empty())
	{
		delete components_.back();
	}
}

/*-----------------------------------------------------------------------------
/* ���͏���
-----------------------------------------------------------------------------*/
void GameObject::Input(void)
{
}

/*-----------------------------------------------------------------------------
/* �X�V����
-----------------------------------------------------------------------------*/
void GameObject::Update(float deltaTime)
{
	UpdateComponents(deltaTime);
	UpdateGameObject(deltaTime);
}

/*-----------------------------------------------------------------------------
/* �X�V����
-----------------------------------------------------------------------------*/
void GameObject::UpdateComponents(float deltaTime)
{
	for (auto components : components_)
	{
		std::cout << "�Q�[���I�u�W�F�N�g���X�V���ꂽ" << std::endl;
		components->Update(deltaTime);
	}
}

/*-----------------------------------------------------------------------------
/* �X�V����
-----------------------------------------------------------------------------*/
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

/*=============================================================================
/*		End of File
=============================================================================*/