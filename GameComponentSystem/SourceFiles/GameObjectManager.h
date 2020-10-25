/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameObjectManager.h] ゲームオブジェクトの管理モジュールヘッダ
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：ゲームオブジェクトを管理するためのクラス
=============================================================================*/
#ifndef GAME_OBJECT_MANAGER_H_
#define	GAME_OBJECT_MANAGER_H_

/*--- インクルードファイル ---*/
#include "StdAfx.h"


/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* ゲームオブジェクトの管理クラス
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

	//追加と削除
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