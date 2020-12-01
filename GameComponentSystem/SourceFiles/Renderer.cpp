#include "StdAfx.h"
#include "Renderer.h"
#include "GameObjects/Component/RenderComponent/SpriteComponent.h"

Renderer::Renderer(GameManager* gameManager)
{
	std::cout << "レンダラー生成\n";
}

Renderer::~Renderer()
{
	std::cout << "レンダラー破棄\n";
}

void Renderer::Draw(void)
{
	std::cout << "\n";
	std::cout << "レンダラーの出力化処理の開始\n";

	for (auto sprite : sprites_)
	{
		sprite->Draw();
	}

	std::cout << "レンダラーの出力化処理の終了\n";
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
