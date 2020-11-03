/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[SpriteComponent.h] 入力コンポーネントのベースコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：入力コンポーネントのコンポーネントのベースになるクラス定義
=============================================================================*/
#ifndef SPRITE_COMPONENT_H_
#define	SPRITE_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../RenderComponent.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* 入力コンポーネントのベースクラス
-------------------------------------*/
class SpriteComponent : public RenderComponent
{
public:
	SpriteComponent(class GameObject* owner, int updateOrder = 100);
	~SpriteComponent(void);

	TypeID GetComponentType(void) const override { return TypeID::SpriteComponent; }

private:
protected:
};


#endif //SPRITE_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/