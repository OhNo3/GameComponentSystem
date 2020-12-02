/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Camera.h] �J�����̃Q�[���I�u�W�F�N�g
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�J�����̃Q�[���I�u�W�F�N�g�̃N���X��`
=============================================================================*/
#ifndef CAMERA_H_
#define	CAMERA_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../GameObject.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/*�@�J�����̃Q�[���I�u�W�F�N�g�N���X
-------------------------------------*/
class Camera : public GameObject
{
public:
	Camera(class GameManager* gameManager);
	~Camera(void);

	void UpdateGameObject(float deltaTime) override;

	virtual TypeID GetType(void) const { return TypeID::Camera; }


private:
	class CameraComponent* camera_component_;
};

#endif //CAMERA_H_
/*=============================================================================
/*		End of File
=============================================================================*/