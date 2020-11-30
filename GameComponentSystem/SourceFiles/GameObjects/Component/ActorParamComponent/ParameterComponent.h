/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[ParameterComponent.h] �p�����[�^�l�̃x�[�X�R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�e�p�����[�^�l�̃x�[�X�ƂȂ�e�N���X�̒�`
=============================================================================*/
#ifndef PARAMETER_COMPONENT_H_
#define	PARAMETER_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../ActorParamComponent.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �p�����[�^�l�̃x�[�X�R���|�[�l���g
-------------------------------------*/
class ParameterComponent : public ActorParamComponent
{
public:
	ParameterComponent(class GameObject* owner, int updateOrder = 100);	//�f�t�H���g�����ōX�V����ύX��
	~ParameterComponent(void);

	virtual TypeID GetComponentType() const override { return TypeID::ParameterComponent; };

private:
protected:
};

#endif //PARAMETER_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/