#include "StdAfx.h"
#include "Renderer.h"
#include "GameObjects/Component/RenderComponent/SpriteComponent.h"

Renderer::Renderer(GameManager* gameManager)
{
	std::cout << "�����_���[����\n";
}

Renderer::~Renderer()
{
	std::cout << "�����_���[�j��\n";
}

void Renderer::Draw(void)
{
	std::cout << "\n";
	std::cout << "�����_���[�̏o�͉������̊J�n\n";

	for (auto sprite : sprites_)
	{
		sprite->Draw();
	}

	std::cout << "�����_���[�̏o�͉������̏I��\n";
	std::cout << "\n";
}

void Renderer::AddSprite(SpriteComponent* spriteComponent)
{
	int myDrawOrder = spriteComponent->GetDrawOrder();
	auto iter = sprites_.begin();
	for (;
		iter != sprites_.end();
		++iter)
	{
		if (myDrawOrder < (*iter)->GetDrawOrder())
		{
			break;
		}
	}

	// Inserts element before position of iterator
	sprites_.insert(iter, spriteComponent);

}

void Renderer::RemoveSprite(SpriteComponent* spriteComponent)
{ 
	auto iter = std::find(sprites_.begin(), sprites_.end(), spriteComponent);
	sprites_.erase(iter);
}
