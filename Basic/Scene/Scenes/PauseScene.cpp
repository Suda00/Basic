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

//������
void PauseScene::Initialize()
{

}

//�X�V
void PauseScene::Update(float elapsedTime)
{
	//�L�[�擾
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
//�`��
void PauseScene::Render()
{

}
//�I��
void PauseScene::Finalize()
{
}
