/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[PlayerParamComponent.h] ���@�p�����[�^�̃R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F���@�p�����[�^�Ɋւ��鏈���̃N���X��`
=============================================================================*/
#ifndef PLAYER_PARAM_COMPONENT_H_
#define	PLAYER_PARAM_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../ActorParamComponent.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* ���@�p�����[�^�̃R���|�[�l���g
-------------------------------------*/
class PlayerParamComponent : public ActorParamComponent
{
public:
	PlayerParamComponent(class GameObject* owner, int updateOrder = 100);	//�f�t�H���g�����ōX�V����ύX��
	~PlayerParamComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::PlayerParamComponent; };

private:
protected:
};

#endif //PLAYER_PARAM_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/