#include "../../StdAfx.h"
#include "Enemy.h"
#include "../Component/RenderComponent/SpriteComponent.h"

Enemy::Enemy(GameManager* gameManager)
	: GameObject(gameManager)
{
	std::cout << "�G�l�~�[�̃Q�[���I�u�W�F�N�g�̍쐬\n";

	sprite_ = new SpriteComponent(this, 10);
	sprite_->SetObjectName("�G�l�~�[�I�u�W�F�N�g");
}

Enemy::~Enemy(void)
{
	std::cout << "�G�l�~�[�̃Q�[���I�u�W�F�N�g�̔j��\n";
}

void Enemy::UpdateGameObject(float deltaTime)
{
	std::cout << "�G�l�~�[�̃Q�[���I�u�W�F�N�g���X�V���ꂽ\n";
}
