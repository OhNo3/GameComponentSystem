#pragma once

class UIObject
{
public:

public:
	enum class TypeID
	{
		None = -1
		//�������g
		, UIObject



		, MAX		//�Q�[���I�u�W�F�N�g��ID�̍ő�l
	};

	//�Q�[���I�u�I�u�W�F�N�g�����L����^��ID
	static const char* GameObjectTypeNames[static_cast<int>(TypeID::MAX)];

	enum class State
	{
		None = -1
		, Active	//��������Q�[���I�u�W�F�N�g���H
		, Paused	//��~����Q�[���I�u�W�F�N�g���H
		, Dead		//���ʃQ�[���I�u�W�F�N�g���H

		, MAX		//��Ԃ̍ő�l
	};

public:
	UIObject(class GameManager* gameManager);
	virtual ~UIObject(void);

	void Init(void);
	void Uninit(void);
	void Input(void);
	virtual void InputGameObject(void);	//���override�ł���悤��
	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	virtual void UpdateGameObject(float deltaTime);	//���override�ł���悤��

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	void SetState(State state) { state_ = state; };
	State GetState(void) { return state_; }

	virtual TypeID GetType(void) const { return TypeID::UIObject; } //���override�ł���悤��

	const std::vector<class Component*>& GetComponents() const { return components_; }

private:
	//GameObject�̏��L��
	class GameManager* game_manager_;

	//GameObject�̏��
	State							state_;

	//�p������R���|�[�l���g
	class TransformComponent* transform_components_;

	//�p�������Čv�Z���邩
	bool							re_compute_transform_;

	//���L�R���|�[�l���g
	std::vector<class Component*>	components_;

private:
};

