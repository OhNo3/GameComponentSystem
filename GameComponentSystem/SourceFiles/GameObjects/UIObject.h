#pragma once

class UIObject
{
public:

public:
	enum class TypeID
	{
		None = -1
		//自分自身
		, UIObject



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
	UIObject(class GameManager* gameManager);
	virtual ~UIObject(void);

	void Init(void);
	void Uninit(void);
	void Input(void);
	virtual void InputGameObject(void);	//後でoverrideできるように
	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	virtual void UpdateGameObject(float deltaTime);	//後でoverrideできるように

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	void SetState(State state) { state_ = state; };
	State GetState(void) { return state_; }

	virtual TypeID GetType(void) const { return TypeID::UIObject; } //後でoverrideできるように

	const std::vector<class Component*>& GetComponents() const { return components_; }

private:
	//GameObjectの所有者
	class GameManager* game_manager_;

	//GameObjectの状態
	State							state_;

	//姿勢制御コンポーネント
	class TransformComponent* transform_components_;

	//姿勢情報を再計算するか
	bool							re_compute_transform_;

	//所有コンポーネント
	std::vector<class Component*>	components_;

private:
};

