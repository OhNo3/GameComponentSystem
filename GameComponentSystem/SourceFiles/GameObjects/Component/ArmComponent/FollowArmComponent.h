/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[FollowArmComponent.h] 追尾するアームのコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：オブジェクト同士を補間・追尾するアームのコンポーネント
=============================================================================*/
#ifndef FOLLOW_ARM_COMPONENT_H_
#define	FOLLOW_ARM_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../ArmComponent.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/*  追尾するアームのコンポーネント
-------------------------------------*/
class FollowArmComponent : public ArmComponent
{
public:
	FollowArmComponent(class GameObject* owner, int updateOrder = 100);	//デフォルト引数で更新順を変更可
	~FollowArmComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::FollowArmComponent; };

private:
protected:
};

#endif //FOLLOW_ARM_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/