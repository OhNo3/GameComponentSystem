/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[SpringArmComponent.h] バネを持つアームのコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：バネ機能を持つオブジェクト同士を補間・追尾するアームのコンポーネント
=============================================================================*/
#ifndef FOLLOW_ARM_COMPONENT_H_
#define	FOLLOW_ARM_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../ArmComponent.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* バネを持つアームのコンポーネント
-------------------------------------*/
class SpringArmComponent : public ArmComponent
{
public:
	SpringArmComponent(class GameObject* owner, int updateOrder = 100);	//デフォルト引数で更新順を変更可
	~SpringArmComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::SpringArmComponent; };

private:
protected:
};

#endif //FOLLOW_ARM_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/