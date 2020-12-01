#pragma once
#include "StdAfx.h"


class Renderer
{
public:
	Renderer(class GameManager* gameManager);
	~Renderer();

	void Draw(void);

	void AddSprite(class SpriteComponent* spriteComponent);
	void RemoveSprite(class SpriteComponent* spriteComponent);


private:
	std::vector<class SpriteComponent*> sprites_;
};

