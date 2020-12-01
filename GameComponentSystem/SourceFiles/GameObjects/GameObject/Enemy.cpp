#include "../../StdAfx.h"
#include "Enemy.h"
#include "../Component/RenderComponent/SpriteComponent.h"

Enemy::Enemy(GameManager* gameManager)
	: GameObject(gameManager)
{
	sprite_ = new SpriteComponent(this, 10);
	sprite_->SetObjectName("エネミーオブジェクト");
}

Enemy::~Enemy(void)
{
}

void Enemy::UpdateGameObject(float deltaTime)
{
	std::cout << "エネミーのゲームオブジェクトが更新された\n";
}
