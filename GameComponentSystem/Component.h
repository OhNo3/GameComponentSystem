#pragma once



class Component
{
public:
	enum TypeID
	{
		TComponent = 0,
		TMoveComponent = 1,
	};


	Component(class GameObject* gameobject, int updateOrder = 100);
	
	virtual~Component(void);

	virtual void Update(float deltaTime);

	virtual void ProcessInput(void);

	virtual TypeID GetType() const = 0;


	class GameObject* GetOwner(void) { return mOwner; }


private:
	class GameObject* mOwner;

	int mUpdateOrder;
};

