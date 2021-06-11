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

//初期化
void GameScene::Initialize()
{
	//カメラ初期化
	m_debugCamera = std::make_unique<DebugCamera>();
	
	//グリッド初期化
	DirectX::CommonStates* state		   = GameContext<DirectX::CommonStates>().Get();
	DX::DeviceResources*   deviceResources = GameContext<DX::DeviceResources>::Get();
	ID3D11Device*          device		   = deviceResources->GetD3DDevice();
	ID3D11DeviceContext*   deviceContext   = deviceResources->GetD3DDeviceContext();
	m_gridFloor = std::make_unique<GridFloor>(device, deviceContext, state, 10.0f, 10);

}
//更新
void GameScene::Update(float elapsedTime)
{
	Keyboard::State keyState = Keyboard::Get().GetState();
	if (keyState.IsKeyDown(Keyboard::P)) {
		SceneManager* sceneManager = GameContext<SceneManager>().Get();
		//シーンスタックを行う
		sceneManager->PushState("Pause");
	}
	m_debugCamera->update();
}
//描画
void GameScene::Render()
{
	DX::DeviceResources* deviceResources = GameContext<DX::DeviceResources>::Get();
	Projection*          projection      = GameContext<Projection>().Get();
	m_gridFloor->draw(deviceResources->GetD3DDeviceContext(), m_debugCamera->getViewMatrix(), projection->GetMatrix());

}
//終了
void GameScene::Finalize()
{
	m_debugCamera.reset();
	m_gridFloor.reset();
}

