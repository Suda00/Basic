#include "../../pch.h"
#include "GameScene.h"


#include <Keyboard.h>

#include "../../Game/Camera/FollowCamera.h"

#include "../SceneManager.h"
#include "../../Common/GameContext.h"

#include "../../GridFloor.h"
#include "../../DebugCamera.h"

#include "../../Common/Projection.h"
#include "../../DeviceResources.h"

using namespace DirectX;

GameScene::GameScene()
	: SceneBase()
	, m_debugCamera()
	, m_gridFloor()
{
}


GameScene::~GameScene()
{
}

//������
void GameScene::Initialize()
{
	//�J����������
	m_debugCamera = std::make_unique<DebugCamera>();
	
	//�O���b�h������
	DirectX::CommonStates* state		   = GameContext<DirectX::CommonStates>().Get();
	DX::DeviceResources*   deviceResources = GameContext<DX::DeviceResources>::Get();
	ID3D11Device*          device		   = deviceResources->GetD3DDevice();
	ID3D11DeviceContext*   deviceContext   = deviceResources->GetD3DDeviceContext();
	m_gridFloor = std::make_unique<GridFloor>(device, deviceContext, state, 10.0f, 10);

}
//�X�V
void GameScene::Update(float elapsedTime)
{
	Keyboard::State keyState = Keyboard::Get().GetState();
	if (keyState.IsKeyDown(Keyboard::P)) {
		SceneManager* sceneManager = GameContext<SceneManager>().Get();
		//�V�[���X�^�b�N���s��
		sceneManager->PushState("Pause");
	}
	m_debugCamera->update();
}
//�`��
void GameScene::Render()
{
	DX::DeviceResources* deviceResources = GameContext<DX::DeviceResources>::Get();
	Projection*          projection      = GameContext<Projection>().Get();
	m_gridFloor->draw(deviceResources->GetD3DDeviceContext(), m_debugCamera->getViewMatrix(), projection->GetMatrix());

}
//�I��
void GameScene::Finalize()
{
	m_debugCamera.reset();
	m_gridFloor.reset();
}

