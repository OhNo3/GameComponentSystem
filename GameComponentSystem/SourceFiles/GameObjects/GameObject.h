/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameObject.h] �Q�[���I�u�W�F�N�g�̃x�[�X�N���X
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
/* �Q�[���I�u�W�F�N�g�̃x�[�X�N���X
-------------------------------------*/
class GameObject
{
public:
	enum class TypeID
	{
		None = -1
		//�������g
		, GameObject

		//����
		, DirectionalLight

		//�A�N�^�[(�Ɨ��������������Q�[���I�u�W�F�N�g)
		, Player
		, Enemy

		
		, MAX		//�Q�[���I�u�W�F�N�g��ID�̍ő�l
	};

	//�Q�[���I�u�I�u�W�F�N�g�����L����^��ID
	static const char* GameObjectTypeNames[static_cast<int>(TypeID::MAX)];

	enum class State
	{
		None = -1
		, Active	//��������Q�[���I�u�W�F�N�g���H
		, Paused	//��~����Q�[���I�u�W�F�N�g���H
		, Dead		//���ʃQ�[���I�u�W�F�N�g���H

		, MAX		//��Ԃ̍ő�l
	};

public:
	GameObject(class GameObjectManager* gameObjectManager);
	virtual ~GameObject(void);

	void Init(void);
	void Uninit(void);
	void Input(void); 
	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	void UpdateGameObject(float deltaTime);

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	void SetGameObjectState(GameObject::State state) { game_object_state_ = state; };
	State GetGameObjectState(void) { return game_object_state_; }

	virtual TypeID GetType() const { return TypeID::GameObject; }

	const std::vector<class Component*>& GetComponents() const { return components_; }

private:
	//GameObject�̏��L��
	class GameObjectManager*		game_object_manager_;

	//GameObject�̏��
	GameObject::State				game_object_state_;

	//�p�������Čv�Z���邩
	bool							re_compute_transform_;

	//���L�R���|�[�l���g
	std::vector<class Component*>	components_;
};

#endif //GAME_OBJECT_H_
/*=============================================================================
/*		End of File
=============================================================================*/