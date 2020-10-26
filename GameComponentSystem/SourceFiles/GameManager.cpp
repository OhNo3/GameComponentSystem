/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameManager.cpp] ゲームオブジェクト管理モジュール
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：ゲームオブジェクトの管理。追加と削除。入力、更新、描画処理を管理
=============================================================================*/

/*--- インクルードファイル ---*/
#include "StdAfx.h"
#include "GameManager.h"
#include "GameObjects/GameObject.h"


/*-----------------------------------------------------------------------------
/* コンストラクタ
-----------------------------------------------------------------------------*/
GameManager::GameManager(void)
	: updating_background_objects_(false)
	, updating_game_objects_(false)
	, updating_ui_objects_(false)
{
	this->InitAll();
}

/*-----------------------------------------------------------------------------
/* デストラクタ
-----------------------------------------------------------------------------*/
GameManager::~GameManager(void)
{
}

/*-----------------------------------------------------------------------------
/* 初期化処理
-----------------------------------------------------------------------------*/
void GameManager::InitAll(void)
{
	std::cout << "ゲームオブジェクトの総初期化\n";
	std::cout << "\n";
}

/*-----------------------------------------------------------------------------
/* 終了化処理
-----------------------------------------------------------------------------*/
void GameManager::UninitAll(void)
{
	std::cout << "ゲームオブジェクトの総終了化\n";
	std::cout << "\n";
}

/*-----------------------------------------------------------------------------
/* 入力処理
-----------------------------------------------------------------------------*/
void GameManager::ProcessInputAll(void)
{
	std::cout << "ゲームオブジェクトの総入力\n";
	std::cout << "\n";
}

/*-----------------------------------------------------------------------------
/* 更新処理
-----------------------------------------------------------------------------*/
void GameManager::UpdateAll(float deltaTime)
{
	std::cout << "ゲームオブジェクトの総更新\n";

	{
		//背景オブジェクトの更新
		this->UpdateBackgroundObjects(deltaTime);

		//ゲームオブジェクトの更新
		this->UpdateGameObjects(deltaTime);
		
		//UIオブジェクトの更新
		this->UpdateUIObjects(deltaTime);

		std::cout << "\n";
	}
}

/*-----------------------------------------------------------------------------
/* 出力生成処理
-----------------------------------------------------------------------------*/
void GameManager::GenerateOutputAll(void)
{
	std::cout << "背景オブジェクトの総出力化\n";
	std::cout << "\n";

	std::cout << "ゲームオブジェクトの総出力化\n";
	std::cout << "\n";

	std::cout << "UIオブジェクトの総出力化\n";
	std::cout << "\n";
}

/*-----------------------------------------------------------------------------
/* 背景オブジェクトの追加処理
-----------------------------------------------------------------------------*/
void GameManager::AddBackgroundObjects(BackgroundObject* backgroundObject)
{
	//ゲームオブジェクトの更新中かで登録先を変更
	if (updating_background_objects_)
	{
		pending_background_objects_.emplace_back(backgroundObject);//待機コンテナ
	}
	else
	{
		background_objects_.emplace_back(backgroundObject);//稼働コンテナ
	}
}

/*-----------------------------------------------------------------------------
/* 背景オブジェクトの削除処理
-----------------------------------------------------------------------------*/
void GameManager::RemoveBackgroundObjects(BackgroundObject* backgroundObject)
{
}

/*-----------------------------------------------------------------------------
/* ゲームオブジェクトの追加処理
-----------------------------------------------------------------------------*/
void GameManager::AddGameObject(GameObject* gameObject)
{
	//ゲームオブジェクトの更新中かで登録先を変更
	if (updating_game_objects_)
	{
		pending_game_objects_.emplace_back(gameObject);//待機コンテナ
	}
	else
	{
		game_objects_.emplace_back(gameObject);//稼働コンテナ
	}
}

/*-----------------------------------------------------------------------------
/* ゲームオブジェクトの削除処理
-----------------------------------------------------------------------------*/
void GameManager::RemoveGameObject(GameObject* gameObject)
{
	// Is it in pending actors?
	auto iter = std::find(pending_game_objects_.begin(), pending_game_objects_.end(), gameObject);
	if (iter != pending_game_objects_.end())
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, pending_game_objects_.end() - 1);
		pending_game_objects_.pop_back();
	}

	// Is it in actors?
	iter = std::find(game_objects_.begin(), game_objects_.end(), gameObject);
	if (iter != game_objects_.end())
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, game_objects_.end() - 1);
		game_objects_.pop_back();
	}
}

/*-----------------------------------------------------------------------------
/* UIオブジェクトの追加処理
-----------------------------------------------------------------------------*/
void GameManager::AddUIObjects(UIObject* uiObject)
{
}

/*-----------------------------------------------------------------------------
/* UIオブジェクトの削除処理
-----------------------------------------------------------------------------*/
void GameManager::RemoveUIObjects(UIObject* uiObject)
{
}

/*-----------------------------------------------------------------------------
/* ゲームオブジェクトの削除処理
-----------------------------------------------------------------------------*/
void GameManager::UpdateBackgroundObjects(float deltaTime)
{

	//for (auto dead)
	//{
	//	delete 
	//}

}

/*-----------------------------------------------------------------------------
/* ゲームオブジェクトの削除処理
-----------------------------------------------------------------------------*/
void GameManager::UpdateGameObjects(float deltaTime)
{

	//if (true)
	//{
	//}
	////すべてのゲームオブジェクトの更新
	//updating_game_objects_ = true;
	//for (auto game_objects_all : game_objects_)
	//{
	//	game_objects_all->Update(deltaTime);
	//}
	//updating_game_objects_ = false;

	//for (auto pending_game_objects_all : pending_game_objects_)
	//{
	//	pending_game_objects_all->Update(deltaTime);
	//}

	//std::vector<class GameObject*> dead_game_objects;
	//for (auto dead_gameobjects : dead_game_objects)
	//{

	//}


}

/*-----------------------------------------------------------------------------
/* ゲームオブジェクトの削除処理
-----------------------------------------------------------------------------*/
void GameManager::UpdateUIObjects(float deltaTime)
{
}

/*=============================================================================
/*		End of File
=============================================================================*/