/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameManager.h] ゲームの状態やオブジェクトの管理モジュールヘッダ
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：ゲームの状態やオブジェクトを管理するためのクラス
=============================================================================*/
#ifndef GAME_MANAGER_H_
#define	GAME_MANAGER_H_

/*--- インクルードファイル ---*/
#include "StdAfx.h"


/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* ゲームオブジェクトの管理クラス
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
	//ゲームオブジェクトの追加と削除
	void AddGameObject(class GameObject* gameObject);
	void RemoveGameObject(class GameObject* gameObject);

	//UIオブジェクトの追加と削除
	void AddUIObjects(class UIObject* uiObject);
	void RemoveUIObjects(class UIObject* uiObject);

private:
	//各更新処理
	void UpdateGameObjects(float deltaTime);
	void UpdateUIObjects(float deltaTime); 

private:
	//現在のゲームの状態
	GameState game_state_;

	//各オブジェクトが更新中かどうか？
	bool updating_game_objects_;
	bool updating_ui_objects_;

	//ゲームオブジェクト
	std::vector<class GameObject*>  game_objects_;
	std::vector<class GameObject*>  pending_game_objects_;

	//UIオブジェクト
	std::vector<class UIObject*>  ui_objects_;
	std::vector<class UIObject*>  pending_ui_objects_;

private:
	class Camera* camera_;
};

#endif //GAME_MANAGER_H_
/*=============================================================================
/*		End of File
=============================================================================*/