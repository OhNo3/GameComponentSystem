#pragma once
#include "Component.h"

class CameraComponent : public Component
{
public:

	void CallCamera();

	void Update(float deltaTime) override;


private:


};

