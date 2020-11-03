/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[PlayerParamComponent.h] 自機パラメータのコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：自機パラメータに関する処理のクラス定義
=============================================================================*/
#ifndef PLAYER_PARAM_COMPONENT_H_
#define	PLAYER_PARAM_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../ActorParamComponent.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* 自機パラメータのコンポーネント
-------------------------------------*/
class PlayerParamComponent : public ActorParamComponent
{
public:
	PlayerParamComponent(class GameObject* owner, int updateOrder = 100);	//デフォルト引数で更新順を変更可
	~PlayerParamComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::PlayerParamComponent; };

private:
protected:
};

#endif //PLAYER_PARAM_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/