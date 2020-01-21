#pragma once



class Component
{
public:
	enum OwnerTypeID
	{
		OTComponent = 0,
		OTMoveComponent = 1,

		NUM_COMPONENT_TYPES
	};

	static const char* OwnerTypeNames[NUM_COMPONENT_TYPES];

	Component(class GameObject* gameObject, int updateOrder = 100);
	
	virtual~Component(void);

	virtual void Update(float deltaTime);

	virtual void ProcessInput(void) {}


	class GameObject* GetOwner(void) { return mOwner; }
	int GetUpdateOrder() const { return mUpdateOrder; }

	virtual OwnerTypeID GetType() const = 0;

	// Load/Save
	virtual void LoadProperties(void);
	virtual void SaveProperties(void);


	//virtual void LoadProperties(const rapidjson::Value& inObj);
	//virtual void SaveProperties(rapidjson::Document::AllocatorType& alloc,
	//	rapidjson::Value& inObj) const;

	static void Create()
	{

	}

protected:

	class GameObject* mOwner;

	int mUpdateOrder;
};

