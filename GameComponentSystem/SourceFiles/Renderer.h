/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Renderer.h] �����_���[���W���[���w�b�_
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F�����_���[�̏o�͏����������܂Ƃ߂��N���X
=============================================================================*/
#ifndef RENDERER_H_
#define	RENDERER_H_

/*--- �C���N���[�h�t�@�C�� ---*/
#include "StdAfx.h"

/*--- �\���̒�` ---*/

/*--- �N���X�̑O���錾 ---*/


/*-------------------------------------
/*�����_���[�̏o�͏����̂܂Ƃ߃N���X
-------------------------------------*/
class Renderer
{
public:
	Renderer(class GameManager* gameManager);
	~Renderer();

	void Draw(void);

	void AddSprite(class SpriteComponent* spriteComponent);
	void RemoveSprite(class SpriteComponent* spriteComponent);


private:
	std::vector<class SpriteComponent*> sprites_;
};


#endif //RENDERER_H_
/*=============================================================================
/*		End of File
=============================================================================*/