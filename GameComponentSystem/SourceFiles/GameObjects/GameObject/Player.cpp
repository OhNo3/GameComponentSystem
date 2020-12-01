/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Hoge.cpp] ���W���[��
/*	Author�FKousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	�����F
=============================================================================*/

/*--- �C���N���[�h�t�@�C�� ---*/
#include "../../StdAfx.h"
#include "Player.h"
#include "../Component/RenderComponent/SpriteComponent.h"

/*-----------------------------------------------------------------------------
/* �R���X�g���N�^
-----------------------------------------------------------------------------*/
Player::Player(GameManager* gameManager)
	:GameObject(gameManager)
{

	sprite_ = new SpriteComponent(this);
	sprite_->SetObjectName("�v���C���[�I�u�W�F�N�g");
}

/*-----------------------------------------------------------------------------
/* �f�X�g���N�^
-----------------------------------------------------------------------------*/
Player::~Player(void)
{
}

void Player::UpdateGameObject(float deltaTime)
{
	std::cout << "�v���C���[�̃Q�[���I�u�W�F�N�g���X�V���ꂽ\n";
}


/*=============================================================================
/*		End of File
=============================================================================*/