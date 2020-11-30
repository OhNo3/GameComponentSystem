/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[ActorParamComponent.h] �A�N�^�[�����l�̃x�[�X�R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�A�N�^�[�����ʂ��Ď��e�p�����[�^���`����e�N���X��`
=============================================================================*/
#ifndef ACTOR_PARAM_COMPONENT_H_
#define	ACTOR_PARAM_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../Component.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/
 

/*-------------------------------------
/* �A�N�^�[�����l�̃x�[�X�R���|�[�l���g
-------------------------------------*/
class ActorParamComponent : public Component
{
public:
	ActorParamComponent(class GameObject* owner, int updateOrder = 100);
	~ActorParamComponent(void);

	virtual TypeID GetComponentType() const override { return TypeID::ActorParamComponent; };


protected:
	//�A�N�^�[�Ƀx�[�X�Ƃ��ď��������������ڂ�ݒu

	class ParameterComponent* health_point_;	//�̗�
	class ParameterComponent* stamina_point_;	//�X�^�~�i
};

#endif //ACTOR_PARAM_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/