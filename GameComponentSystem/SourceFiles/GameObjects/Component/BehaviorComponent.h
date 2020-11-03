/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[BehaviorComponent.h] AIビヘイビアのベースコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：AIビヘイビアコンポーネントのベースになるクラス定義
=============================================================================*/
#ifndef BEHAVIOR_COMPONENT_H_
#define	BEHAVIOR_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../Component.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* AIビヘイビアコンポーネントのベースクラス
-------------------------------------*/
class BehaviorComponent : public Component
{
public:
	BehaviorComponent(class GameObject* owner, int updateOrder = 100);
	~BehaviorComponent(void);

	virtual TypeID GetComponentType() const override { return TypeID::BehaviorComponent; };

private:
protected:
};

#endif //BEHAVIOR_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/