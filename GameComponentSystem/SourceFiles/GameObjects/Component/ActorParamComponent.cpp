/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[ActorParamComponent.cpp] �A�N�^�[�����l�̃x�[�X�R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�A�N�^�[�����ʂ��Ď��e�p�����[�^���`����e�N���X��`
=============================================================================*/

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../../StdAfx.h"
#include "ActorParamComponent.h"
#include "ActorParamComponent/ParameterComponent/HealthPointsComponent.h"
#include "ActorParamComponent/ParameterComponent/StaminaPointsComponent.h"


/*-----------------------------------------------------------------------------
/* �R���X�g���N�^
-----------------------------------------------------------------------------*/
ActorParamComponent::ActorParamComponent(GameObject* owner, int updateOrder)
	: Component(owner, updateOrder)
{
	health_point_	= new HealthPointsComponent(owner, updateOrder);
	stamina_point_	= new StaminaPointsComponent(owner, updateOrder);
}

/*-----------------------------------------------------------------------------
/* �f�X�g���N�^
-----------------------------------------------------------------------------*/
ActorParamComponent::~ActorParamComponent(void)
{
}

/*=============================================================================
/*		End of File
=============================================================================*/