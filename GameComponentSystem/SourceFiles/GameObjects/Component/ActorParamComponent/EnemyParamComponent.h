/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[EnemyParamComponent.h] 敵パラメータのコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：敵パラメータに関する処理のクラス定義
=============================================================================*/
#ifndef ENEMY_PARAM_COMPONENT_H_
#define	ENEMY_PARAM_COMPONENT_H_

/*--- インクルードファイル ---*/
#include "../ActorParamComponent.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* スタミナ値クラス
-------------------------------------*/
class EnemyParamComponent : public ActorParamComponent
{
public:
	EnemyParamComponent(class GameObject* owner, int updateOrder = 100);	//デフォルト引数で更新順を変更可
	~EnemyParamComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::EnemyParamComponent; };

private:
protected:
};

#endif //ENEMY_PARAM_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/