#include "MainProcessManager.h"
#include "StdAfx.h"

void MainProcessManager::Init(void)
{
	std::cout << "//////////�����������̎n�܂�//////////" << std::endl;

	std::cout << "/*********�����������̏I���*********/" << std::endl;
}

void MainProcessManager::Uninit(void)
{
	std::cout << "//////////�I���������̎n�܂�//////////" << std::endl;

	std::cout << "/*********�I���������̏I���*********/" << std::endl;
}

void MainProcessManager::Input(void)
{
	std::cout << "//////////���͏����̎n�܂�//////////" << std::endl;

	std::cout << "/*********���͏����̏I���*********/" << std::endl;
}

void MainProcessManager::Update(void)
{
	std::cout << "//////////�X�V�����̎n�܂�//////////" << std::endl;



	std::cout << "/*********�X�V�����̏I���*********/" << std::endl;
}

void MainProcessManager::Draw(void)
{
	std::cout << "//////////�`�揈���̎n�܂�//////////" << std::endl;



	std::cout << "/*********�`�揈���̏I���*********/" << std::endl;
}
