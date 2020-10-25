/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameObjectManager.h] �Q�[���I�u�W�F�N�g�̊Ǘ����W���[���w�b�_
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�Q�[���I�u�W�F�N�g���Ǘ����邽�߂̃N���X
=============================================================================*/
#ifndef GAME_OBJECT_MANAGER_H_
#define	GAME_OBJECT_MANAGER_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "StdAfx.h"


/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �Q�[���I�u�W�F�N�g�̊Ǘ��N���X
-------------------------------------*/
class GameObjectManager
{
public:
	GameObjectManager(void);
	~GameObjectManager(void);

	class GameObjectManager* Create(void)
	{
		return new GameObjectManager();
	}

	void InitAll(void);
	void UninitAll(void);
	void ProcessInputAll(void);
	void UpdateAll(float deltaTime);
	void GenerateOutputAll(void);

	//�ǉ��ƍ폜
	void AddGameObject(class GameObject* gameObject);
	void RemoveGameObject(class GameObject* gameObject);

private:
	std::vector<class GameObject*>  game_objects_;
	std::vector<class GameObject*>  pending_game_objects_;
};

#endif //GAME_OBJECT_MANAGER_H_
/*=============================================================================
/*		End of File
=============================================================================*/