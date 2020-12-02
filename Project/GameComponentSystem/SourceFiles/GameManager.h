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


	class Renderer* GetRenderer(void) { return renderer_; }


public:
	//�Q�[���I�u�W�F�N�g�̒ǉ��ƍ폜
	void AddGameObject(class GameObject* gameObject);
	void RemoveGameObject(class GameObject* gameObject);

	//UI�I�u�W�F�N�g�̒ǉ�����
	void PushUIObject(class UIObject* uiObject);

private:
	//�e�X�V����
	void UpdateGameObjects(float deltaTime);
	void UpdateUIObjects(float deltaTime);

private:
	//���݂̃Q�[���̏��
	GameState game_state_;

	//�e�I�u�W�F�N�g���X�V�����ǂ����H
	bool updating_game_objects_;

	//�Q�[���I�u�W�F�N�g
	std::vector<class GameObject*>  game_objects_;
	std::vector<class GameObject*>  pending_game_objects_;

	//UI�I�u�W�F�N�g
	std::vector<class UIObject*>  ui_objects_;

private:
	class Renderer* renderer_;
	class Camera*	camera_;
	class Player*	player_;
	class Enemy*	enemy_;

};

#endif //GAME_MANAGER_H_
/*=============================================================================
/*		End of File
=============================================================================*/