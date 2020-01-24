#pragma once

#include "../StdAfx.h"
#include "../Component/Component.h"
#include "../Component/TransformComponent.h"

class GameObject
{
public:

	void Update(float deltaTime);

	void AddComponent();
	void RemoveComponent();
	void SortComponent();
private:
	std::vector<Component*>  components_;

};

