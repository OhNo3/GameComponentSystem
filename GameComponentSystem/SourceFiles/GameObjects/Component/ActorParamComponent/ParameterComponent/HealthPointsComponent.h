/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[HealthPointsComponent.h] �̗͒l�̃R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�̗͒l�Ɋւ��鏈���̃N���X��`
=============================================================================*/
#ifndef HEALTH_POINTS_COMPONENT_H_
#define	HEALTH_POINTS_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../ParameterComponent.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �̗͒l�N���X
-------------------------------------*/
class  HealthPointsComponent : public ParameterComponent
{
public:
	HealthPointsComponent(class GameObject* owner, int updateOrder = 100);	//�f�t�H���g�����ōX�V����ύX��
	~HealthPointsComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::HealthPointsComponent; };

private:
	int health_;
};

#endif //HEALTH_POINTS_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/