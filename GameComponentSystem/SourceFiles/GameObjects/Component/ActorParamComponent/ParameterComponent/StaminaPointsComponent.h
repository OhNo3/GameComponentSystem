/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[StaminaPointsComponent.h] �X�^�~�i�l�̃R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�X�^�~�i�l�Ɋւ��鏈���̃N���X��`
=============================================================================*/
#ifndef STAMINA_POINTS_COMPONENT_H_
#define	STAMINA_POINTS_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../ParameterComponent.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �X�^�~�i�l�N���X
-------------------------------------*/
class StaminaPointsComponent : public ParameterComponent
{
public:
	StaminaPointsComponent(class GameObject* owner, int updateOrder = 100);	//�f�t�H���g�����ōX�V����ύX��
	~StaminaPointsComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::StaminaPointsComponent; };

private:
	float stamina_;
};

#endif //STAMINA_POINTS_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/