/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Component.h] �R���|�[�l���g�̃x�[�X�N���X
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F
=============================================================================*/
#ifndef COMPONENT_H_
#define	COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �N���X
-------------------------------------*/
class Component
{
public:

	//�ǂ̃R���|�[�l���g�Ȃ̂�
	enum ComponentTypeID
	{
		CT_Component = 0,
		CT_TransformComponent,
		CT_ColliderComponent,
		CT_MoveComponent,
		CT_ActorComponent,


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
	class GameObject* mOwner; //����(�R���|�[�l���g)�̏��L��
	int mUpdateOrder;
};

#endif //COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/
