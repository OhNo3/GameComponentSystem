/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameManager.h] �Q�[���̏�Ԃ�I�u�W�F�N�g�̊Ǘ����W���[���w�b�_
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�Q�[���̏�Ԃ�I�u�W�F�N�g���Ǘ����邽�߂̃N���X
=============================================================================*/
#ifndef GAME_MANAGER_H_
#define	GAME_MANAGER_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "StdAfx.h"


/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �Q�[���I�u�W�F�N�g�̊Ǘ��N���X
-------------------------------------*/
class GameManager
{
public:
	enum class GameState
	{
		None = -1
		, Title
		, Gameplay
		, Result
		, Paused
		, Quit

		, MAX
	};

public:
	GameManager(void);
	~GameManager(void);

	class GameManager* Create(void)
	{
		return new GameManager();
	}

	void InitAll(void);
	void UninitAll(void);
	void InputAll(void);
	void UpdateAll(float deltaTime);
	void GenerateOutputAll(void);

public:
	//�Q�[���I�u�W�F�N�g�̒ǉ��ƍ폜
	void AddGameObject(class GameObject* gameObject);
	void RemoveGameObject(class GameObject* gameObject);

	//UI�I�u�W�F�N�g�̒ǉ��ƍ폜
	void AddUIObjects(class UIObject* uiObject);
	void RemoveUIObjects(class UIObject* uiObject);

private:
	//�e�X�V����
	void UpdateGameObjects(float deltaTime);
	void UpdateUIObjects(float deltaTime); 

private:
	//���݂̃Q�[���̏��
	GameState game_state_;

	//�e�I�u�W�F�N�g���X�V�����ǂ����H
	bool updating_game_objects_;
	bool updating_ui_objects_;

	//�Q�[���I�u�W�F�N�g
	std::vector<class GameObject*>  game_objects_;
	std::vector<class GameObject*>  pending_game_objects_;

	//UI�I�u�W�F�N�g
	std::vector<class UIObject*>  ui_objects_;
	std::vector<class UIObject*>  pending_ui_objects_;

private:
	class Camera* camera_;
};

#endif //GAME_MANAGER_H_
/*=============================================================================
/*		End of File
=============================================================================*/