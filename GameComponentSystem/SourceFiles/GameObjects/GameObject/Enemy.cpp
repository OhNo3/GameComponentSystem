#include "../../StdAfx.h"
#include "Enemy.h"
#include "../Component/RenderComponent/SpriteComponent.h"

Enemy::Enemy(GameManager* gameManager)
	: GameObject(gameManager)
{
	std::cout << "エネミーのゲームオブジェクトの作成\n";

	sprite_ = new SpriteComponent(this, 10);
	sprite_->SetObjectName("エネミーオブジェクト");
}

Enemy::~Enemy(void)
{
	std::cout << "エネミーのゲームオブジェクトの破棄\n";
}

void Enemy::UpdateGameObject(float deltaTime)
{
	std::cout << "エネミーのゲームオブジェクトが更新された\n";
}
