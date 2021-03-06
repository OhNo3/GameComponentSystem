/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Enemy.h] エネミーのゲームオブジェクトクラス
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：エネミーのゲームオブジェクトクラス定義
=============================================================================*/
#ifndef ENEMY_H_
#define	ENEMY_H_

/*--- インクルードファイル ---*/
#include "../GameObject.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* エネミーのゲームオブジェクトクラス
-------------------------------------*/
class Enemy : public GameObject
{
public:
	Enemy(class GameManager* gameManager);
	~Enemy(void);

	void UpdateGameObject(float deltaTime) override;

	virtual TypeID GetType(void) const { return TypeID::Enemy; }

private:
	class SpriteComponent* sprite_;
};

#endif //ENEMY_H_
/*=============================================================================
/*		End of File
=============================================================================*/