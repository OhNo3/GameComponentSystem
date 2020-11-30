/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[SpringArmComponent.h] �o�l�����A�[���̃R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�o�l�@�\�����I�u�W�F�N�g���m���ԁE�ǔ�����A�[���̃R���|�[�l���g
=============================================================================*/
#ifndef FOLLOW_ARM_COMPONENT_H_
#define	FOLLOW_ARM_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../ArmComponent.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �o�l�����A�[���̃R���|�[�l���g
-------------------------------------*/
class SpringArmComponent : public ArmComponent
{
public:
	SpringArmComponent(class GameObject* owner, int updateOrder = 100);	//�f�t�H���g�����ōX�V����ύX��
	~SpringArmComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::SpringArmComponent; };

private:
protected:
};

#endif //FOLLOW_ARM_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/