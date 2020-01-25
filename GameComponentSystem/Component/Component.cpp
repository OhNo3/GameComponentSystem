#include "Component.h"
#include "../GameObject.h"


const char* Component::TypeNames[NUM_COMPONENT_TYPES] = {
	"Component",
	"AudioComponent",

};

Component::Component(GameObject* gameObject, int updateOrder)
	: mOwner(gameObject)
	, mUpdateOrder(updateOrder)
{
	mOwner->AddComponent(this);
}

Component::~Component(void)
{
	mOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime)
{
}

void Component::ProcessInput(void)
{
}

void Component::LoadProperties(void)
{
}

void Component::SaveProperties(void)
{
}
