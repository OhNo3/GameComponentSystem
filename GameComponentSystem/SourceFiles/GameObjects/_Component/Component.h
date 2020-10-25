/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Component.h] コンポーネントのベースクラス
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：コンポーネントのベースクラス
=============================================================================*/
#ifndef COMPONENT_H_
#define	COMPONENT_H_

/*--- インクルードファイル ---*/

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* コンポーネントのベースクラス
-------------------------------------*/
class Component
{
public:
	enum class TypeID
	{
		None = -1
		, Component
		, TransformComponent
		, ColliderComponent
		, MovementComponent
		, ActorComponent
		
		, MAX
	};

	static const char* ComponentTypeNames[static_cast<int>(TypeID::MAX)];

public:
	Component(class GameObject* gameObject, int updateOrder = 100);
	virtual~Component(void);

	virtual void Init(void);
	virtual void Uninit(void);
	virtual void Input(void);
	virtual void Update(float deltaTime);

	class GameObject* GetOwnerGameObject(void) { return owner_game_object_; }
	int GetUpdateOrder(void) const	 { return update_order_; }

	virtual TypeID GetComponentType() const = 0;

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
	class GameObject*	owner_game_object_;	//自分(コンポーネント)の所有者
	int					update_order_;		//自分自身の更新順位
};

#endif //COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/
