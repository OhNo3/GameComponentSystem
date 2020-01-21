#pragma once

#include "StdAfx.h"
#include "Component.h"

class GameObject
{
public:



	void AddComponent();
	void RemoveComponent();
	void SortComponent();
private:
	std::vector<Component*>  my_components;

};

