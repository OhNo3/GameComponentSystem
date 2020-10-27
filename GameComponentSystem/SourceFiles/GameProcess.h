/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameProcess.h] ゲーム実行処理モジュールヘッダ
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：ゲームの実行処理部分をまとめたクラス
=============================================================================*/
#ifndef GAME_PROCESS_H_
#define	GAME_PROCESS_H_

/*--- インクルードファイル ---*/

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* ゲーム実行処理のまとめクラス
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