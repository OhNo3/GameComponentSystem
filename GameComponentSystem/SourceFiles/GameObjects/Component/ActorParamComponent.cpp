/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[ActorParamComponent.cpp] アクターが持つ値のベースコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：アクターが共通して持つ各パラメータを定義する親クラス定義
=============================================================================*/

/*--- インクルードファイル ---*/
#include "../../StdAfx.h"
#include "ActorParamComponent.h"
#include "ActorParamComponent/ParameterComponent/HealthPointsComponent.h"
#include "ActorParamComponent/ParameterComponent/StaminaPointsComponent.h"


/*-----------------------------------------------------------------------------
/* コンストラクタ
-----------------------------------------------------------------------------*/
ActorParamComponent::ActorParamComponent(GameObject* owner, int updateOrder)
	: Component(owner, updateOrder)
{
	health_point_	= new HealthPointsComponent(owner, updateOrder);
	stamina_point_	= new StaminaPointsComponent(owner, updateOrder);
}

/*-----------------------------------------------------------------------------
/* デストラクタ
-----------------------------------------------------------------------------*/
ActorParamComponent::~ActorParamComponent(void)
{
}

/*=============================================================================
/*		End of File
=============================================================================*/