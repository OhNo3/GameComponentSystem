/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameObject.h] ゲームオブジェクトのベースクラス
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：
=============================================================================*/
#ifndef GAME_OBJECT_H_
#define	GAME_OBJECT_H_

/*--- インクルードファイル ---*/
#include "../StdAfx.h"

/*--- 構造体定義 ---*/

/*--- クラスの前方宣言 ---*/


/*-------------------------------------
/* ゲームオブジェクトのベースクラス
-------------------------------------*/
class GameObject
{
public:
	enum class TypeID
	{
		None = -1
		//自分自身
		, GameObject

		//光源
		, DirectionalLight

		//アクター(独立した役割を持つゲームオブジェクト)
		, Player
		, Enemy

		
		, MAX		//ゲームオブジェクトのIDの最大値
	};

	//ゲームオブオブジェクトが所有する型のID
	static const char* GameObjectTypeNames[static_cast<int>(TypeID::MAX)];

	enum class State
	{
		None = -1
		, Active	//活動するゲームオブジェクトか？
		, Paused	//停止するゲームオブジェクトか？
		, Dead		//死ぬゲームオブジェクトか？

		, MAX		//状態の最大値
	};

public:
	GameObject(class GameObjectManager* gameObjectManager);
	virtual ~GameObject(void);

	void Init(void);
	void Uninit(void);
	void Input(void); 
	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	void UpdateGameObject(float deltaTime);

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	void SetGameObjectState(GameObject::State state) { game_object_state_ = state; };
	State GetGameObjectState(void) { return game_object_state_; }

	virtual TypeID GetType() const { return TypeID::GameObject; }

	const std::vector<class Component*>& GetComponents() const { return components_; }

private:
	//GameObjectの所有者
	class GameObjectManager*		game_object_manager_;

	//GameObjectの状態
	GameObject::State				game_object_state_;

	//姿勢情報を再計算するか
	bool							re_compute_transform_;

	//所有コンポーネント
	std::vector<class Component*>	components_;
};

#endif //GAME_OBJECT_H_
/*=============================================================================
/*		End of File
=============================================================================*/