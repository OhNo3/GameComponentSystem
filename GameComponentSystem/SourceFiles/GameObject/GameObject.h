/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameObject.h] ���W���[���w�b�_
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F
=============================================================================*/
#ifndef GAME_OBJECT_H_
#define	GAME_OBJECT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../StdAfx.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �N���X
-------------------------------------*/
class GameObject
{
public:
	enum TypeID
	{
		ID_None = -1
		, ID_Actor
		, ID_Follow
		, ID_Target

		, MAX_TYPE_ID
	};

	static const char* GameObjectTypeNames[MAX_TYPE_ID];

	enum State
	{
		None = -1
		, Active
		, Paused
		, Dead

		, MAX_STATE
	};

	GameObject(class GameObjectManager* gameObjectManager);
	virtual ~GameObject(void);


	void Init(void);
	void Uninit(void);
	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	void UpdateGameObject(float deltaTime);

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	void SetGameObjectState(State state) { game_object_state_ = state; };
	State GetGameObjectState(void) { return game_object_state_; }

	const std::vector<class Component*>& GetComponents() const { return components_; }

private:
	//GameObject�̏��L��
	class GameObjectManager* game_object_manager_;

	//GameObject�̏��
	GameObject::State game_object_state_;

	//�Q�[���I�u�W�F�N�g�̎p�����
	class TransformComponent* transform_component_;

	//�p�������Čv�Z���邩
	bool re_compute_transform_;

	//���L�R���|�[�l���g
	std::vector<class Component*> components_;
};


#endif //_H_
/*=============================================================================
/*		End of File
=============================================================================*/
