/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[UIObject.cpp] UIオブジェクトのベースクラス
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明： UIオブジェクトの共通の処理を定義
=============================================================================*/

/*--- インクルードファイル ---*/
#include "../StdAfx.h"
#include "UIObject.h"
#include "../GameManager.h"

/*-----------------------------------------------------------------------------
/* コンストラクタ
-----------------------------------------------------------------------------*/
UIObject::UIObject(class GameManager* gameManager)
	: game_manager_(gameManager)
	, state_(State::Closing)
{
	gameManager->PushUIObject(this);
}

/*-----------------------------------------------------------------------------
/* デストラクタ
-----------------------------------------------------------------------------*/
UIObject::~UIObject(void)
{
}

/*-----------------------------------------------------------------------------
/* 初期化処理
-----------------------------------------------------------------------------*/
void UIObject::Init(void)
{
}

/*-----------------------------------------------------------------------------
/* 終了化処理
-----------------------------------------------------------------------------*/
void UIObject::Uninit(void)
{
}

/*-----------------------------------------------------------------------------
/* 入力処理
-----------------------------------------------------------------------------*/
void UIObject::Input(void)
{
}

/*-----------------------------------------------------------------------------
/* 更新処理
-----------------------------------------------------------------------------*/
void UIObject::Update(float deltaTime)
{
}

/*-----------------------------------------------------------------------------
/* 描画処理
-----------------------------------------------------------------------------*/
void UIObject::Draw(void)
{
}

/*=============================================================================
/*		End of File
=============================================================================*/