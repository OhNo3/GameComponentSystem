#include "GameObjectManager.h"
#include "StdAfx.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::InitAll(void)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑�������\n";
}

void GameObjectManager::UninitAll(void)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑��I����\n";
}

void GameObjectManager::ProcessInputAll(void)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑�����\n";
}

void GameObjectManager::UpdateAll(void)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑��X�V\n";

	for (auto game_objects_all : game_object_)
	{
		game_objects_all->Update(16.0f);
	}

	for (auto pending_game_objects_all : pending_game_object_)
	{

	}
}

void GameObjectManager::GenerateOutputAll(void)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑��o�͉�\n";
}
