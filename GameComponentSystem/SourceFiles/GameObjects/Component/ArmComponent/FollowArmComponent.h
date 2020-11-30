/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[FollowArmComponent.h] �ǔ�����A�[���̃R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�I�u�W�F�N�g���m���ԁE�ǔ�����A�[���̃R���|�[�l���g
=============================================================================*/
#ifndef FOLLOW_ARM_COMPONENT_H_
#define	FOLLOW_ARM_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../ArmComponent.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/*  �ǔ�����A�[���̃R���|�[�l���g
-------------------------------------*/
class FollowArmComponent : public ArmComponent
{
public:
	FollowArmComponent(class GameObject* owner, int updateOrder = 100);	//�f�t�H���g�����ōX�V����ύX��
	~FollowArmComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::FollowArmComponent; };

private:
protected:
};

#endif //FOLLOW_ARM_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/