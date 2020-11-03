/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameProcess.h] �Q�[�����s�������W���[���w�b�_
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�Q�[���̎��s�����������܂Ƃ߂��N���X
=============================================================================*/
#ifndef GAME_PROCESS_H_
#define	GAME_PROCESS_H_

/*--- �C���N���[�h�t�@�C�� ---*/

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �Q�[�����s�����̂܂Ƃ߃N���X
-------------------------------------*/
class GameProcess
{
public:
	GameProcess(void);
	~GameProcess(void);

public:
	bool StartUp(void);
	void Run(void);
	void ShutDown(void);

private:
	bool Init(void);
	void Uninit(void);
	void ProcessInput(void);
	void Update(float deltaTime);
	void GenerateOutput(void);

private:
	class GameManager* game_manager_;

};

#endif //GAME_PROCESS_H_
/*=============================================================================
/*		End of File
=============================================================================*/