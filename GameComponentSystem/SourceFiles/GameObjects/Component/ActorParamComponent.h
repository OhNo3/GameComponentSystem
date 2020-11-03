/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[ActorParamComponent.h] アクターが持つ値のベースコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：アクターが共通して持つ各パラメータを定義する親クラス定義
=============================================================================*/
#ifndef ACTOR_PARAM_COMPONENT_H_
#define	ACTOR_PARAM_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../Component.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/
 

/*-------------------------------------
/* アクターが持つ値のベースコンポーネント
-------------------------------------*/
class ActorParamComponent : public Component
{
public:
	ActorParamComponent(class GameObject* owner, int updateOrder = 100);
	~ActorParamComponent(void);

	virtual TypeID GetComponentType() const override { return TypeID::ActorParamComponent; };


protected:
	//アクターにベースとして所持させたい項目を設置

	class ParameterComponent* health_point_;	//体力
	class ParameterComponent* stamina_point_;	//スタミナ
};

#endif //ACTOR_PARAM_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/