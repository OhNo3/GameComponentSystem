#include "GameProcessManager.h"
#include "GameObjectManager.h"
#include "StdAfx.h"

void GameProcessManager::Init(void)
{
	std::cout << "//////////�����������̎n�܂�//////////" << std::endl;
	GameObjectManager::InitAll();

	std::cout << "/*********�����������̏I���*********/" << std::endl;
}

void GameProcessManager::Uninit(void)
{
	std::cout << "//////////�I���������̎n�܂�//////////" << std::endl;
	GameObjectManager::UninitAll();


	std::cout << "/*********�I���������̏I���*********/" << std::endl;
}

void GameProcessManager::Input(void)
{
	std::cout << "//////////���͏����̎n�܂�//////////" << std::endl;
	GameObjectManager::InputAll();

	std::cout << "/*********���͏����̏I���*********/" << std::endl;
}

void GameProcessManager::Update(void)
{
	std::cout << "//////////�X�V�����̎n�܂�//////////" << std::endl;
	GameObjectManager::UpdateAll();


	std::cout << "/*********�X�V�����̏I���*********/" << std::endl;
}

void GameProcessManager::Draw(void)
{
	std::cout << "//////////�`�揈���̎n�܂�//////////" << std::endl;
	GameObjectManager::DrawAll();


	std::cout << "/*********�`�揈���̏I���*********/" << std::endl;
}
