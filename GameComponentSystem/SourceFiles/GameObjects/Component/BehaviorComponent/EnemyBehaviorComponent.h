/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[EnemyBehaviorComponent.h]  �GAI�r�w�C�r�A�̃R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�GAI�r�w�C�r�A�R���|�[�l���g�̃N���X��`
=============================================================================*/
#ifndef ENEMY_BEHAVIOR_COMPONENT_H_
#define	ENEMY_BEHAVIOR_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../BehaviorComponent.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* �GAI�̃R���|�[�l���g
-------------------------------------*/
class EnemyBehaviorComponent : public BehaviorComponent
{
public:
	EnemyBehaviorComponent(class GameObject* owner, int updateOrder = 100);
	~EnemyBehaviorComponent(void);

	virtual TypeID GetComponentType() const override { return TypeID::EnemyBehaviorComponent; };


private:
};

#endif //ENEMY_BEHAVIOR_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/