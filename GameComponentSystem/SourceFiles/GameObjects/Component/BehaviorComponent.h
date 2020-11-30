/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[BehaviorComponent.h] AI�r�w�C�r�A�̃x�[�X�R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����FAI�r�w�C�r�A�R���|�[�l���g�̃x�[�X�ɂȂ�N���X��`
=============================================================================*/
#ifndef BEHAVIOR_COMPONENT_H_
#define	BEHAVIOR_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../Component.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* AI�r�w�C�r�A�R���|�[�l���g�̃x�[�X�N���X
-------------------------------------*/
class BehaviorComponent : public Component
{
public:
	BehaviorComponent(class GameObject* owner, int updateOrder = 100);
	~BehaviorComponent(void);

	virtual TypeID GetComponentType() const override { return TypeID::BehaviorComponent; };

private:
protected:
};

#endif //BEHAVIOR_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/