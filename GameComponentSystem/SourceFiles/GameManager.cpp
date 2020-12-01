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
#include "Renderer.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/GameObject/Camera.h"
#include "GameObjects/GameObject/Player.h"
#include "GameObjects/GameObject/Enemy.h"



/*-----------------------------------------------------------------------------
/* �R���X�g���N�^
-----------------------------------------------------------------------------*/
GameManager::GameManager(void)
	: updating_game_objects_(false)
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
	renderer_ = new Renderer(this);

	std::cout << "�Z�[�u�f�[�^�̃��[�h\n";

	game_objects_.clear();
	pending_game_objects_.clear();

	std::cout << "�Q�[���I�u�W�F�N�g�̍쐬�J�n\n";
	std::cout << "\n";

	game_state_ = GameState::Gameplay;
	camera_ = new Camera(this);
	player_ = new Player(this);
	enemy_ = new Enemy(this);

	std::cout << "\n";
	std::cout << "�Q�[���I�u�W�F�N�g�̍쐬�I��\n";

}

/*-----------------------------------------------------------------------------
/* �I��������
-----------------------------------------------------------------------------*/
void GameManager::UninitAll(void)
{
	std::cout << "�Q�[���}�l�[�W���̏I��������\n";
	std::cout << "�Q�[���I�u�W�F�N�g�̔j���J�n\n";
	delete camera_;
	delete player_;
	delete enemy_;

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
		//�Q�[���I�u�W�F�N�g�̍X�V
		this->UpdateGameObjects(deltaTime);
		
		//UI�I�u�W�F�N�g�̍X�V
		//this->UpdateUIObjects(deltaTime);
	}
}

/*-----------------------------------------------------------------------------
/* �o�͐�������
-----------------------------------------------------------------------------*/
void GameManager::GenerateOutputAll(void)
{
	std::cout << "�Q�[���}�l�[�W���̏o�͉�����\n";

	renderer_->Draw();
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

/*=============================================================================
/*		End of File
=============================================================================*/