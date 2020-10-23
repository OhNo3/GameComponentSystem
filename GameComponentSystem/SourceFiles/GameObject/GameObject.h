/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameObject.h] モジュールヘッダ
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
/* クラス
-------------------------------------*/
class GameObject
{
public:
	enum TypeID
	{
		ID_None = -1
		, ID_Actor
		, ID_Follow
		, ID_Target

		, MAX_TYPE_ID
	};

	static const char* GameObjectTypeNames[MAX_TYPE_ID];

	enum State
	{
		None = -1
		, Active
		, Paused
		, Dead

		, MAX_STATE
	};

	GameObject(class GameObjectManager* gameObjectManager);
	virtual ~GameObject(void);


	void Init(void);
	void Uninit(void);
	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	void UpdateGameObject(float deltaTime);

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	void SetGameObjectState(State state) { game_object_state_ = state; };
	State GetGameObjectState(void) { return game_object_state_; }

	const std::vector<class Component*>& GetComponents() const { return components_; }

private:
	//GameObjectの所有者
	class GameObjectManager* game_object_manager_;

	//GameObjectの状態
	GameObject::State game_object_state_;

	//ゲームオブジェクトの姿勢情報
	class TransformComponent* transform_component_;

	//姿勢情報を再計算するか
	bool re_compute_transform_;

	//所有コンポーネント
	std::vector<class Component*> components_;
};


#endif //_H_
/*=============================================================================
/*		End of File
=============================================================================*/
