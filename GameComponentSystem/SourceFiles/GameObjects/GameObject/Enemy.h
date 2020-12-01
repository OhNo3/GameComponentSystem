#pragma once

#include "../GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy(class GameManager* gameManager);
	~Enemy(void);

	void UpdateGameObject(float deltaTime) override;

	virtual TypeID GetType(void) const { return TypeID::Enemy; }

private:
	class SpriteComponent* sprite_;
};

