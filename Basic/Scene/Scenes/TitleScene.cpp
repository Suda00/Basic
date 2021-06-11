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

//������
void TitleScene::Initialize()
{

}

//�X�V
void TitleScene::Update(float elapsedTime)
{
	//�L�[�擾
	Keyboard::State keyState = Keyboard::Get().GetState();
	if (keyState.IsKeyDown(Keyboard::Z)) {
		SceneManager* sceneManager = GameContext<SceneManager>().Get();
		sceneManager->RequestState("Game");
	}
}
//�`��
void TitleScene::Render()
{

}
//�I��
void TitleScene::Finalize()
{
}
