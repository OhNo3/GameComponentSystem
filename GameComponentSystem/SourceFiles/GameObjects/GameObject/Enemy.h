#pragma once

#include "../GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy(class GameManager* gameManager);
	~Enemy(void);

	virtual TypeID GetType(void) const { return TypeID::Enemy; }

private:

};

