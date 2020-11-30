/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[MeshComponent.h] ���̓R���|�[�l���g�̃x�[�X�R���|�[�l���g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F���̓R���|�[�l���g�̃R���|�[�l���g�̃x�[�X�ɂȂ�N���X��`
=============================================================================*/
#ifndef MESH_COMPONENT_H_
#define	MESH_COMPONENT_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../RenderComponent.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/* ���̓R���|�[�l���g�̃x�[�X�N���X
-------------------------------------*/
class MeshComponent : public RenderComponent
{
public:
	MeshComponent(class GameObject* owner, int updateOrder = 100);
	~MeshComponent(void);

	TypeID GetComponentType(void) const override { return TypeID::MeshComponent; }

private:
protected:
};


#endif //RENDER_COMPONENT_H_
/*=============================================================================
/*		End of File
=============================================================================*/