#include "Component.h"
#include "../GameObject/GameObject.h"


const char* Component::TypeNames[NUM_COMPONENT_TYPES] = {
	"Component",
	"AudioComponent",

};


Component::Component(GameObject* gameObject, int updateOrder)
	: mOwner(gameObject)
	, mUpdateOrder(updateOrder)
{
	mOwner->AddComponent();
}

Component::~Component(void)
{
	mOwner->RemoveComponent();
}

void Component::Update(float deltaTime)
{
}

void Component::LoadProperties(void)
{
}

void Component::SaveProperties(void)
{
}
