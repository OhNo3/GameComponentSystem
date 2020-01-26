#pragma once



class Component
{
public:

	//どのコンポーネントなのか
	enum ComponentTypeID
	{
		TComponent = 0,
		TTransformComponent,
		TColliderComponent,
		TMoveComponent,
		TActorComponent,


		NUM_COMPONENT_TYPES
	};

	static const char* ComponentTypeNames[NUM_COMPONENT_TYPES];

	Component(class GameObject* gameObject, int updateOrder = 100);
	
	virtual~Component(void);

	virtual void Update(float deltaTime);
	virtual void ProcessInput(void);


	class GameObject* GetOwnerGameObject(void) { return mOwner; }
	int GetUpdateOrder(void) const	 { return mUpdateOrder; }

	virtual ComponentTypeID GetComponentType() const = 0;

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
	class GameObject* mOwner; //自分(コンポーネント)の所有者
	int mUpdateOrder;
};

