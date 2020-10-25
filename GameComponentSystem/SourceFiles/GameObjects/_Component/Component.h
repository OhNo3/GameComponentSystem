/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Component.h] �R���|�[�l���g�̃x�[�X�N���X
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�R���|�[�l���g�̃x�[�X�N���X
=============================================================================*/
#ifndef COMPONENT_H_
#define	COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �R���|�[�l���g�̃x�[�X�N���X
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
	class GameObject*	owner_game_object_;	//����(�R���|�[�l���g)�̏��L��
	int					update_order_;		//�������g�̍X�V����
};

#endif //COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/
