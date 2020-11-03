/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[EnemyBehaviorComponent.h]  敵AIビヘイビアのコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：敵AIビヘイビアコンポーネントのクラス定義
=============================================================================*/
#ifndef ENEMY_BEHAVIOR_COMPONENT_H_
#define	ENEMY_BEHAVIOR_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../BehaviorComponent.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* 敵AIのコンポーネント
-------------------------------------*/
class EnemyBehaviorComponent : public BehaviorComponent
{
public:
	EnemyBehaviorComponent(class GameObject* owner, int updateOrder = 100);
	~EnemyBehaviorComponent(void);

	virtual TypeID GetComponentType() const override { return TypeID::EnemyBehaviorComponent; };


private:
};

#endif //ENEMY_BEHAVIOR_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/