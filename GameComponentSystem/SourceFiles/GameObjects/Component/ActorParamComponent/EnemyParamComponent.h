/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[EnemyParamComponent.h] �G�p�����[�^�̃R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�G�p�����[�^�Ɋւ��鏈���̃N���X��`
=============================================================================*/
#ifndef ENEMY_PARAM_COMPONENT_H_
#define	ENEMY_PARAM_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../ActorParamComponent.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �X�^�~�i�l�N���X
-------------------------------------*/
class EnemyParamComponent : public ActorParamComponent
{
public:
	EnemyParamComponent(class GameObject* owner, int updateOrder = 100);	//�f�t�H���g�����ōX�V����ύX��
	~EnemyParamComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Input(void) override;
	void Update(float deltaTime) override;

	virtual TypeID GetComponentType() const override { return TypeID::EnemyParamComponent; };

private:
protected:
};

#endif //ENEMY_PARAM_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/