/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameProcessManager.h] �Q�[�����s�̓����������W���[���w�b�_
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�Q�[�����s�̓����������`�����N���X
=============================================================================*/
#ifndef GAME_PROCESS_MANAGER_H_
#define	GAME_PROCESS_MANAGER_H_

/*--- �C���N���[�h�t�@�C�� ---*/

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �Q�[�����s�̓��������̊Ǘ��N���X
-------------------------------------*/
class GameProcessManager
{
private:
	GameProcessManager(void);

public:
	~GameProcessManager(void);

	//���C���v���Z�X���ł̂ӂ�܂�
	static void Init(void);
	static void Uninit(void);
	static void ProcessInput(void);
	static void Update(float deltaTime);
	static void GenerateOutput(void);
private:
	static class GameObjectManager* game_object_manager_;
};

#endif //GAMEP_ROCESS_MANAGER_H_
/*=============================================================================
/*		End of File
=============================================================================*/