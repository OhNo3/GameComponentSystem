#include "StdAfx.h"
#include "GameObjectManager.h"
#include "GameObjects/GameObject.h"

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

void GameObjectManager::UpdateAll(float deltaTime)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑��X�V\n";

	for (auto game_objects_all : game_objects_)
	{
		game_objects_all->Update(deltaTime);
	}

	for (auto pending_game_objects_all : pending_game_objects_) 
	{
		pending_game_objects_all->Update(deltaTime);
	}
}

void GameObjectManager::GenerateOutputAll(void)
{
	std::cout << "�Q�[���I�u�W�F�N�g�̑��o�͉�\n";
}

void GameObjectManager::AddGameObject(GameObject* gameObject)
{
}

void GameObjectManager::RemoveGameObject(GameObject* gameObject)
{
}
