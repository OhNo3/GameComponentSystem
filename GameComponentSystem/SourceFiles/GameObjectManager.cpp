/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameObjectManager.cpp] ゲームオブジェクト管理モジュール
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：ゲームオブジェクトの管理。追加と削除。入力、更新、描画処理を管理
=============================================================================*/

/*--- インクルードファイル ---*/
#include "StdAfx.h"
#include "GameObjectManager.h"
#include "GameObjects/GameObject.h"


/*-----------------------------------------------------------------------------
/* コンストラクタ
-----------------------------------------------------------------------------*/
GameObjectManager::GameObjectManager(void)
{
}

/*-----------------------------------------------------------------------------
/* デストラクタ
-----------------------------------------------------------------------------*/
GameObjectManager::~GameObjectManager(void)
{
}

/*-----------------------------------------------------------------------------
/* 初期化処理
-----------------------------------------------------------------------------*/
void GameObjectManager::InitAll(void)
{
	std::cout << "ゲームオブジェクトの総初期化\n";
}

/*-----------------------------------------------------------------------------
/* 終了化処理
-----------------------------------------------------------------------------*/
void GameObjectManager::UninitAll(void)
{
	std::cout << "ゲームオブジェクトの総終了化\n";
}

/*-----------------------------------------------------------------------------
/* 入力処理
-----------------------------------------------------------------------------*/
void GameObjectManager::ProcessInputAll(void)
{
	std::cout << "ゲームオブジェクトの総入力\n";
}

/*-----------------------------------------------------------------------------
/* 更新処理
-----------------------------------------------------------------------------*/
void GameObjectManager::UpdateAll(float deltaTime)
{
	std::cout << "ゲームオブジェクトの総更新\n";

	for (auto game_objects_all : game_objects_)
	{
		game_objects_all->Update(deltaTime);
	}

	for (auto pending_game_objects_all : pending_game_objects_) 
	{
		pending_game_objects_all->Update(deltaTime);
	}
}

/*-----------------------------------------------------------------------------
/* 出力生成処理
-----------------------------------------------------------------------------*/
void GameObjectManager::GenerateOutputAll(void)
{
	std::cout << "ゲームオブジェクトの総出力化\n";
}

/*-----------------------------------------------------------------------------
/* ゲームオブジェクトの追加処理
-----------------------------------------------------------------------------*/
void GameObjectManager::AddGameObject(GameObject* gameObject)
{
}

/*-----------------------------------------------------------------------------
/* ゲームオブジェクトの削除処理
-----------------------------------------------------------------------------*/
void GameObjectManager::RemoveGameObject(GameObject* gameObject)
{
}

/*=============================================================================
/*		End of File
=============================================================================*/