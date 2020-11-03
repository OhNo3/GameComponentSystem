/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameManager.cpp] �Q�[���̏�Ԃ�I�u�W�F�N�g�̊Ǘ����W���[��
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�Q�[����ԂƃI�u�W�F�N�g�̊Ǘ��B�ǉ��ƍ폜�B���́A�X�V�A�`��Ȃ�
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
	std::cout << "�Q�[���}�l�[�W���̋N��\n";
	this->InitAll();
}

/*-----------------------------------------------------------------------------
/* �f�X�g���N�^
-----------------------------------------------------------------------------*/
GameManager::~GameManager(void)
{
	this->UninitAll();
	std::cout << "�Q�[���}�l�[�W���̒�~\n";
}

/*-----------------------------------------------------------------------------
/* ����������
-----------------------------------------------------------------------------*/
void GameManager::InitAll(void)
{
	std::cout << "�Q�[���}�l�[�W���̏���������\n";

	//�O���t�B�b�N�X�̗����グ��Z�[�u�f�[�^�̃��[�h�Ȃǂ��s��
	std::cout << "�O���t�B�b�N�X�̗����グ\n";
	std::cout << "�Z�[�u�f�[�^�̃��[�h\n";
}

/*-----------------------------------------------------------------------------
/* �I��������
-----------------------------------------------------------------------------*/
void GameManager::UninitAll(void)
{
	std::cout << "�Q�[���}�l�[�W���̏I��������\n";

	std::cout << "�Z�[�u�f�[�^�̃A�����[�h\n";
	std::cout << "�O���t�B�b�N�X�̔j��\n";
}

/*-----------------------------------------------------------------------------
/* ���͏���
-----------------------------------------------------------------------------*/
void GameManager::InputAll(void)
{
	std::cout << "�Q�[���}�l�[�W���̓��͏���\n";

	if (game_state_ == GameState::Gameplay)
	{
		//�Q�[���I�u�W�F�N�g�̓��͏���
		for (auto game_object : game_objects_)
		{
			game_object->Input();
		}
	}
}

/*-----------------------------------------------------------------------------
/* �X�V����
-----------------------------------------------------------------------------*/
void GameManager::UpdateAll(float deltaTime)
{
	std::cout << "�Q�[���}�l�[�W���̍X�V����\n";

	if (game_state_ == GameState::Gameplay)
	{
		//�w�i�I�u�W�F�N�g�̍X�V
		this->UpdateBackgroundObjects(deltaTime);

		//�Q�[���I�u�W�F�N�g�̍X�V
		this->UpdateGameObjects(deltaTime);
		
		//UI�I�u�W�F�N�g�̍X�V
		this->UpdateUIObjects(deltaTime);
	}
}

/*-----------------------------------------------------------------------------
/* �o�͐�������
-----------------------------------------------------------------------------*/
void GameManager::GenerateOutputAll(void)
{
	std::cout << "�Q�[���}�l�[�W���̏o�͉�����\n";
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
	// �ҋ@�R���e�i
	// "backgroundObject"���R���e�i�̒�����T���o���Ĕj������
	auto iter = std::find(pending_background_objects_.begin(), pending_background_objects_.end(), backgroundObject);
	if (iter != pending_background_objects_.end())
	{
		//��v����"backgroundObject"���R���e�i�̖����ֈړ������A���������̂�j������
		std::iter_swap(iter, pending_background_objects_.end() - 1);
		pending_background_objects_.pop_back();
	}

	// �ғ��R���e�i
	// "backgroundObject"���R���e�i�̒�����T���o���Ĕj������
	iter = std::find(background_objects_.begin(), background_objects_.end(), backgroundObject);
	if (iter != background_objects_.end())
	{
		//��v����"backgroundObject"���R���e�i�̖����ֈړ������A���������̂�j������
		std::iter_swap(iter, background_objects_.end() - 1);
		background_objects_.pop_back();
	}
}

/*-----------------------------------------------------------------------------
/* �Q�[���I�u�W�F�N�g�̒ǉ�����
-----------------------------------------------------------------------------*/
void GameManager::AddGameObject(GameObject* gameObject)
{
	// �Q�[���I�u�W�F�N�g�̍X�V�����œo�^���ύX
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
	// �ҋ@�R���e�i
	// "gameObject"���R���e�i�̒�����T���o���Ĕj������
	auto iter = std::find(pending_game_objects_.begin(), pending_game_objects_.end(), gameObject);
	if (iter != pending_game_objects_.end())
	{
		//��v����"gameObject"���R���e�i�̖����ֈړ������A���������̂�j������
		std::iter_swap(iter, pending_game_objects_.end() - 1);
		pending_game_objects_.pop_back();
	}

	// �ғ��R���e�i
	// "gameObject"���R���e�i�̒�����T���o���Ĕj������
	iter = std::find(game_objects_.begin(), game_objects_.end(), gameObject);
	if (iter != game_objects_.end())
	{
		//��v����"gameObject"���R���e�i�̖����ֈړ������A���������̂�j������
		std::iter_swap(iter, game_objects_.end() - 1);
		game_objects_.pop_back();
	}
}

/*-----------------------------------------------------------------------------
/* UI�I�u�W�F�N�g�̒ǉ�����
-----------------------------------------------------------------------------*/
void GameManager::AddUIObjects(UIObject* uiObject)
{
	// UI�I�u�W�F�N�g�̍X�V�����œo�^���ύX
	if (updating_ui_objects_)
	{
		pending_ui_objects_.emplace_back(uiObject);//�ҋ@�R���e�i
	}
	else
	{
		ui_objects_.emplace_back(uiObject);//�ғ��R���e�i
	}
}

/*-----------------------------------------------------------------------------
/* UI�I�u�W�F�N�g�̍폜����
-----------------------------------------------------------------------------*/
void GameManager::RemoveUIObjects(UIObject* uiObject)
{
	// �ҋ@�R���e�i
	// "uiObject"���R���e�i�̒�����T���o���Ĕj������
	auto iter = std::find(pending_ui_objects_.begin(), pending_ui_objects_.end(), uiObject);
	if (iter != pending_ui_objects_.end())
	{
		//��v����"uiObject"���R���e�i�̖����ֈړ������A���������̂�j������
		std::iter_swap(iter, pending_ui_objects_.end() - 1);
		pending_ui_objects_.pop_back();
	}

	// �ғ��R���e�i
	// "uiObject"���R���e�i�̒�����T���o���Ĕj������
	iter = std::find(ui_objects_.begin(), ui_objects_.end(), uiObject);
	if (iter != ui_objects_.end())
	{
		//��v����"uiObject"���R���e�i�̖����ֈړ������A���������̂�j������
		std::iter_swap(iter, ui_objects_.end() - 1);
		ui_objects_.pop_back();
	}
}

/*-----------------------------------------------------------------------------
/* �w�i�I�u�W�F�N�g�̑��X�V����
-----------------------------------------------------------------------------*/
void GameManager::UpdateBackgroundObjects(float deltaTime)
{
	//���ׂẴQ�[���I�u�W�F�N�g�̍X�V
	updating_game_objects_ = true;
	for (auto game_object : game_objects_)
	{
		game_object->Update(deltaTime);
	}
	updating_game_objects_ = false;

	//�ҋ@���X�g�̃Q�[���I�u�W�F�N�g�̑���
	for (auto pending_game_object : pending_game_objects_)
	{
		pending_game_object->Update(deltaTime);
		game_objects_.emplace_back(pending_game_object);
	}
	pending_game_objects_.clear();

	//�Q�[���I�u�W�F�N�g���j���̏�Ԃ��`�F�b�N
	std::vector<class GameObject*> dead_game_objects;
	for (auto game_object : game_objects_)
	{
		if (game_object->GetState() == GameObject::State::Dead)
		{
			dead_game_objects.emplace_back(game_object);
		}
	}

	//�j���\��̃Q�[���I�u�W�F�N�g�̃�������j��
	for (auto dead_game_object : dead_game_objects)
	{
		delete dead_game_object;
	}
}

/*-----------------------------------------------------------------------------
/* �Q�[���I�u�W�F�N�g�̑��X�V����
-----------------------------------------------------------------------------*/
void GameManager::UpdateGameObjects(float deltaTime)
{
	//���ׂẴQ�[���I�u�W�F�N�g�̍X�V
	updating_game_objects_ = true;
	for (auto game_object : game_objects_)
	{
		game_object->Update(deltaTime);
	}
	updating_game_objects_ = false;

	//�ҋ@���X�g�̃Q�[���I�u�W�F�N�g�̑���
	for (auto pending_game_object : pending_game_objects_)
	{
		pending_game_object->Update(deltaTime);
		game_objects_.emplace_back(pending_game_object);
	}
	pending_game_objects_.clear();

	//�Q�[���I�u�W�F�N�g���j���̏�Ԃ��`�F�b�N
	std::vector<class GameObject*> dead_game_objects;
	for (auto game_object : game_objects_)
	{
		if (game_object->GetState() == GameObject::State::Dead)
		{
			dead_game_objects.emplace_back(game_object);
		}
	}

	//�j���\��̃Q�[���I�u�W�F�N�g�̃�������j��
	for (auto dead_game_object : dead_game_objects)
	{
		delete dead_game_object;
	}
}

/*-----------------------------------------------------------------------------
/* UI�I�u�W�F�N�g�̑��X�V����
-----------------------------------------------------------------------------*/
void GameManager::UpdateUIObjects(float deltaTime)
{
	//���ׂẴQ�[���I�u�W�F�N�g�̍X�V
	updating_game_objects_ = true;
	for (auto game_object : game_objects_)
	{
		game_object->Update(deltaTime);
	}
	updating_game_objects_ = false;

	//�ҋ@���X�g�̃Q�[���I�u�W�F�N�g�̑���
	for (auto pending_game_object : pending_game_objects_)
	{
		pending_game_object->Update(deltaTime);
		game_objects_.emplace_back(pending_game_object);
	}
	pending_game_objects_.clear();

	//�Q�[���I�u�W�F�N�g���j���̏�Ԃ��`�F�b�N
	std::vector<class GameObject*> dead_game_objects;
	for (auto game_object : game_objects_)
	{
		if (game_object->GetState() == GameObject::State::Dead)
		{
			dead_game_objects.emplace_back(game_object);
		}
	}

	//�j���\��̃Q�[���I�u�W�F�N�g�̃�������j��
	for (auto dead_game_object : dead_game_objects)
	{
		delete dead_game_object;
	}
}

/*=============================================================================
/*		End of File
=============================================================================*/