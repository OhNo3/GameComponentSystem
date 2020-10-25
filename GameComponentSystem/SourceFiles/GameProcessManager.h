/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameProcessManager.h] ゲーム実行の内部処理モジュールヘッダ
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：ゲーム実行の内部処理を定義したクラス
=============================================================================*/
#ifndef GAME_PROCESS_MANAGER_H_
#define	GAME_PROCESS_MANAGER_H_

/*--- インクルードファイル ---*/

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* ゲーム実行の内部処理の管理クラス
-------------------------------------*/
class GameProcessManager
{
private:
	GameProcessManager(void);

public:
	~GameProcessManager(void);

	//メインプロセス内でのふるまい
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