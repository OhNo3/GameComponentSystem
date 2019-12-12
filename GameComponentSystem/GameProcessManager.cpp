#include "GameProcessManager.h"
#include "GameObjectManager.h"
#include "StdAfx.h"

void GameProcessManager::Init(void)
{
	std::cout << "//////////�����������̎n�܂�//////////\n";
	{
		GameObjectManager::InitAll();




	}
	std::cout << "/*********�����������̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::Uninit(void)
{
	std::cout << "//////////�I���������̎n�܂�//////////\n";
	{
		GameObjectManager::UninitAll();

	}
	std::cout << "/*********�I���������̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::ProcessInput(void)
{
	std::cout << "//////////���͏����̎n�܂�//////////\n";
	{
		GameObjectManager::InputAll();


	}
	std::cout << "/*********���͏����̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::Update(void)
{
	std::cout << "//////////�X�V�����̎n�܂�//////////\n";
	{
		GameObjectManager::UpdateAll();

	}
	std::cout << "/*********�X�V�����̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::GenerateOutput(void)
{
	std::cout << "//////////�`�揈���̎n�܂�//////////\n";
	{
		GameObjectManager::DrawAll();

	}
	std::cout << "/*********�`�揈���̏I���*********/\n";
	std::cout << "\n";
}
