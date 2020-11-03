/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[HealthPointsComponent.h] 体力値のコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：体力値に関する処理のクラス定義
=============================================================================*/
#ifndef HEALTH_POINTS_COMPONENT_H_
#define	HEALTH_POINTS_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../ParameterComponent.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* 体力値クラス
-------------------------------------*/
class  HealthPointsComponent : public ParameterComponent
{
public:
	HealthPointsComponent(class GameObject* owner, int updateOrder = 100);	//デフォルト引数で更新順を変更可
	~HealthPointsComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::HealthPointsComponent; };

private:
	int health_;
};

#endif //HEALTH_POINTS_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/