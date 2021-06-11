#include "../../pch.h"
#include "TitleScene.h"

#include <Keyboard.h>

#include"../../Common/GameContext.h"
#include"../SceneManager.h"

using namespace DirectX;

TitleScene::TitleScene() 
	: SceneBase()
{
}


TitleScene::~TitleScene()
{
}

//初期化
void TitleScene::Initialize()
{

}

//更新
void TitleScene::Update(float elapsedTime)
{
	//キー取得
	Keyboard::State keyState = Keyboard::Get().GetState();
	if (keyState.IsKeyDown(Keyboard::Z)) {
		SceneManager* sceneManager = GameContext<SceneManager>().Get();
		sceneManager->RequestState("Game");
	}
}
//描画
void TitleScene::Render()
{

}
//終了
void TitleScene::Finalize()
{
}
