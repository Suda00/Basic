#include "../../pch.h"
#include "PauseScene.h"

#include <Keyboard.h>

#include"../../Common/GameContext.h"
#include"../SceneManager.h"

using namespace DirectX;

PauseScene::PauseScene()
	: SceneBase()
{
}


PauseScene::~PauseScene()
{
}

//初期化
void PauseScene::Initialize()
{

}

//更新
void PauseScene::Update(float elapsedTime)
{
	//キー取得
	Keyboard::State keyState = Keyboard::Get().GetState();
	if (keyState.IsKeyDown(Keyboard::X)) {
		SceneManager* sceneManager = GameContext<SceneManager>().Get();
		sceneManager->RequestState("Title");
	}
	if (keyState.IsKeyDown(Keyboard::C)) {
		SceneManager* sceneManager = GameContext<SceneManager>().Get();
		sceneManager->PopState();
	}
}
//描画
void PauseScene::Render()
{

}
//終了
void PauseScene::Finalize()
{
}
