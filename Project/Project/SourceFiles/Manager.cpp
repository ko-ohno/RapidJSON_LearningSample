/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Manager.cpp] 全体の処理の管理クラス
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：全体の処理の管理クラス
=============================================================================*/

/*--- インクルードファイル ---*/
#include "StdAfx.h"
#include "Manager.h"
#include "JSONHelper/JSONHelper.h"

/*-----------------------------------------------------------------------------
/* コンストラクタ
-----------------------------------------------------------------------------*/
Manager::Manager(void)
{
	this->InitAll();
}

/*-----------------------------------------------------------------------------
/* デストラクタ
-----------------------------------------------------------------------------*/
Manager::~Manager(void)
{
	this->UninitAll();
}

/*-----------------------------------------------------------------------------
/* ファクトリメソッド
-----------------------------------------------------------------------------*/
Manager* Manager::Create(void)
{
	return new Manager();
}

/*-----------------------------------------------------------------------------
/* 初期化処理
-----------------------------------------------------------------------------*/
void Manager::InitAll(void)
{
	JSONHelper::RapidJSONSampler();
}

/*-----------------------------------------------------------------------------
/* 終了化処理
-----------------------------------------------------------------------------*/
void Manager::UninitAll(void)
{
}

/*-----------------------------------------------------------------------------
/* 入力処理
-----------------------------------------------------------------------------*/
void Manager::InputAll(void)
{
}

/*-----------------------------------------------------------------------------
/* 更新処理
-----------------------------------------------------------------------------*/
void Manager::UpdateAll(float deltaTime)
{
}

/*-----------------------------------------------------------------------------
/* 描画処理
-----------------------------------------------------------------------------*/
void Manager::GenerateOutputAll(void)
{
}

/*=============================================================================
/*		End of File
=============================================================================*/