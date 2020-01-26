#include "GameProcessManager.h"
#include "GameObjectManager.h"
#include "StdAfx.h"

//�ÓI�ϐ��錾
GameObjectManager* GameProcessManager::game_object_manager_ = nullptr;

GameProcessManager::GameProcessManager()
{
}

GameProcessManager::~GameProcessManager()
{
}

void GameProcessManager::Init(void)
{
	std::cout << "//////////�����������̎n�܂�//////////\n";
	{ 
		game_object_manager_ = game_object_manager_->Create();
		game_object_manager_->InitAll();
	}
	std::cout << "/*********�����������̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::Uninit(void)
{
	std::cout << "//////////�I���������̎n�܂�//////////\n";
	{
		game_object_manager_->UninitAll();
	}
	std::cout << "/*********�I���������̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::ProcessInput(void)
{
	std::cout << "//////////���͏����̎n�܂�//////////\n";
	{
		game_object_manager_->ProcessInputAll();
	}
	std::cout << "/*********���͏����̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::Update(void)
{
	std::cout << "//////////�X�V�����̎n�܂�//////////\n";
	{
		game_object_manager_->UpdateAll();
	}
	std::cout << "/*********�X�V�����̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::GenerateOutput(void)
{
	std::cout << "//////////�`�揈���̎n�܂�//////////\n";
	{
		game_object_manager_->GenerateOutputAll();
	}
	std::cout << "/*********�`�揈���̏I���*********/\n";
	std::cout << "\n";
}
