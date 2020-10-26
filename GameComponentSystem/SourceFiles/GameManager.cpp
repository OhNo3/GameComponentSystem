/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameManager.cpp] �Q�[���I�u�W�F�N�g�Ǘ����W���[��
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�Q�[���I�u�W�F�N�g�̊Ǘ��B�ǉ��ƍ폜�B���́A�X�V�A�`�揈�����Ǘ�
=============================================================================*/

/*--- �C���N���[�h�t�@�C�� ---*/
#include "StdAfx.h"
#include "GameManager.h"
#include "GameObjects/GameObject.h"


/*-----------------------------------------------------------------------------
/* �R���X�g���N�^
-----------------------------------------------------------------------------*/
GameManager::GameManager(void)
	: updating_background_objects_(false)
	, updating_game_objects_(false)
	, updating_ui_objects_(false)
{
	this->InitAll();
}

/*-----------------------------------------------------------------------------
/* �f�X�g���N�^
-----------------------------------------------------------------------------*/
GameManager::~GameManager(void)
{
}

/*-----------------------------------------------------------------------------
/* ����������
-----------------------------------------------------------------------------*/
void GameManager::InitAll(void)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑�������\n";
	std::cout << "\n";
}

/*-----------------------------------------------------------------------------
/* �I��������
-----------------------------------------------------------------------------*/
void GameManager::UninitAll(void)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑��I����\n";
	std::cout << "\n";
}

/*-----------------------------------------------------------------------------
/* ���͏���
-----------------------------------------------------------------------------*/
void GameManager::ProcessInputAll(void)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑�����\n";
	std::cout << "\n";
}

/*-----------------------------------------------------------------------------
/* �X�V����
-----------------------------------------------------------------------------*/
void GameManager::UpdateAll(float deltaTime)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑��X�V\n";

	{
		//�w�i�I�u�W�F�N�g�̍X�V
		this->UpdateBackgroundObjects(deltaTime);

		//�Q�[���I�u�W�F�N�g�̍X�V
		this->UpdateGameObjects(deltaTime);
		
		//UI�I�u�W�F�N�g�̍X�V
		this->UpdateUIObjects(deltaTime);

		std::cout << "\n";
	}
}

/*-----------------------------------------------------------------------------
/* �o�͐�������
-----------------------------------------------------------------------------*/
void GameManager::GenerateOutputAll(void)
{
	std::cout << "�w�i�I�u�W�F�N�g�̑��o�͉�\n";
	std::cout << "\n";

	std::cout << "�Q�[���I�u�W�F�N�g�̑��o�͉�\n";
	std::cout << "\n";

	std::cout << "UI�I�u�W�F�N�g�̑��o�͉�\n";
	std::cout << "\n";
}

/*-----------------------------------------------------------------------------
/* �w�i�I�u�W�F�N�g�̒ǉ�����
-----------------------------------------------------------------------------*/
void GameManager::AddBackgroundObjects(BackgroundObject* backgroundObject)
{
	//�Q�[���I�u�W�F�N�g�̍X�V�����œo�^���ύX
	if (updating_background_objects_)
	{
		pending_background_objects_.emplace_back(backgroundObject);//�ҋ@�R���e�i
	}
	else
	{
		background_objects_.emplace_back(backgroundObject);//�ғ��R���e�i
	}
}

/*-----------------------------------------------------------------------------
/* �w�i�I�u�W�F�N�g�̍폜����
-----------------------------------------------------------------------------*/
void GameManager::RemoveBackgroundObjects(BackgroundObject* backgroundObject)
{
}

/*-----------------------------------------------------------------------------
/* �Q�[���I�u�W�F�N�g�̒ǉ�����
-----------------------------------------------------------------------------*/
void GameManager::AddGameObject(GameObject* gameObject)
{
	//�Q�[���I�u�W�F�N�g�̍X�V�����œo�^���ύX
	if (updating_game_objects_)
	{
		pending_game_objects_.emplace_back(gameObject);//�ҋ@�R���e�i
	}
	else
	{
		game_objects_.emplace_back(gameObject);//�ғ��R���e�i
	}
}

/*-----------------------------------------------------------------------------
/* �Q�[���I�u�W�F�N�g�̍폜����
-----------------------------------------------------------------------------*/
void GameManager::RemoveGameObject(GameObject* gameObject)
{
	// Is it in pending actors?
	auto iter = std::find(pending_game_objects_.begin(), pending_game_objects_.end(), gameObject);
	if (iter != pending_game_objects_.end())
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, pending_game_objects_.end() - 1);
		pending_game_objects_.pop_back();
	}

	// Is it in actors?
	iter = std::find(game_objects_.begin(), game_objects_.end(), gameObject);
	if (iter != game_objects_.end())
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, game_objects_.end() - 1);
		game_objects_.pop_back();
	}
}

/*-----------------------------------------------------------------------------
/* UI�I�u�W�F�N�g�̒ǉ�����
-----------------------------------------------------------------------------*/
void GameManager::AddUIObjects(UIObject* uiObject)
{
}

/*-----------------------------------------------------------------------------
/* UI�I�u�W�F�N�g�̍폜����
-----------------------------------------------------------------------------*/
void GameManager::RemoveUIObjects(UIObject* uiObject)
{
}

/*-----------------------------------------------------------------------------
/* �Q�[���I�u�W�F�N�g�̍폜����
-----------------------------------------------------------------------------*/
void GameManager::UpdateBackgroundObjects(float deltaTime)
{

	//for (auto dead)
	//{
	//	delete 
	//}

}

/*-----------------------------------------------------------------------------
/* �Q�[���I�u�W�F�N�g�̍폜����
-----------------------------------------------------------------------------*/
void GameManager::UpdateGameObjects(float deltaTime)
{

	//if (true)
	//{
	//}
	////���ׂẴQ�[���I�u�W�F�N�g�̍X�V
	//updating_game_objects_ = true;
	//for (auto game_objects_all : game_objects_)
	//{
	//	game_objects_all->Update(deltaTime);
	//}
	//updating_game_objects_ = false;

	//for (auto pending_game_objects_all : pending_game_objects_)
	//{
	//	pending_game_objects_all->Update(deltaTime);
	//}

	//std::vector<class GameObject*> dead_game_objects;
	//for (auto dead_gameobjects : dead_game_objects)
	//{

	//}


}

/*-----------------------------------------------------------------------------
/* �Q�[���I�u�W�F�N�g�̍폜����
-----------------------------------------------------------------------------*/
void GameManager::UpdateUIObjects(float deltaTime)
{
}

/*=============================================================================
/*		End of File
=============================================================================*/