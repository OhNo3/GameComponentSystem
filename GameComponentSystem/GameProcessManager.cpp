#include "GameProcessManager.h"
#include "ComponentManager.h"
#include "StdAfx.h"

void GameProcessManager::Init(void)
{
	std::cout << "//////////�����������̎n�܂�//////////\n";
	{
		ComponentManager::InitAll();
	}
	std::cout << "/*********�����������̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::Uninit(void)
{
	std::cout << "//////////�I���������̎n�܂�//////////\n";
	{
		ComponentManager::UninitAll();
	}
	std::cout << "/*********�I���������̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::ProcessInput(void)
{
	std::cout << "//////////���͏����̎n�܂�//////////\n";
	{
		ComponentManager::ProcessInputAll();
	}
	std::cout << "/*********���͏����̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::Update(void)
{
	std::cout << "//////////�X�V�����̎n�܂�//////////\n";
	{
		ComponentManager::UpdateAll();
	}
	std::cout << "/*********�X�V�����̏I���*********/\n";
	std::cout << "\n";
}

void GameProcessManager::GenerateOutput(void)
{
	std::cout << "//////////�`�揈���̎n�܂�//////////\n";
	{
		ComponentManager::GenerateOutputAll();
	}
	std::cout << "/*********�`�揈���̏I���*********/\n";
	std::cout << "\n";
}
