/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[StaminaPointsComponent.h] スタミナ値のコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：スタミナ値に関する処理のクラス定義
=============================================================================*/
#ifndef STAMINA_POINTS_COMPONENT_H_
#define	STAMINA_POINTS_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../ParameterComponent.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* スタミナ値クラス
-------------------------------------*/
class StaminaPointsComponent : public ParameterComponent
{
public:
	StaminaPointsComponent(class GameObject* owner, int updateOrder = 100);	//デフォルト引数で更新順を変更可
	~StaminaPointsComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::StaminaPointsComponent; };

private:
	float stamina_;
};

#endif //STAMINA_POINTS_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/