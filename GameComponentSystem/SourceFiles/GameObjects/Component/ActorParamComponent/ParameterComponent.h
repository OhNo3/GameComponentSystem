/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[ParameterComponent.h] パラメータ値のベースコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：各パラメータ値のベースとなる親クラスの定義
=============================================================================*/
#ifndef PARAMETER_COMPONENT_H_
#define	PARAMETER_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../ActorParamComponent.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* パラメータ値のベースコンポーネント
-------------------------------------*/
class ParameterComponent : public ActorParamComponent
{
public:
	ParameterComponent(class GameObject* owner, int updateOrder = 100);	//デフォルト引数で更新順を変更可
	~ParameterComponent(void);

	virtual TypeID GetComponentType() const override { return TypeID::ParameterComponent; };

private:
protected:
};

#endif //PARAMETER_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/