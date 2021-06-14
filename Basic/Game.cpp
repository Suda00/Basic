//
// Game.cpp
//

#include "pch.h"
#include "Game.h"

#include "Common\GameContext.h"
#include "Scene\SceneManager.h"
#include "Scene\Scenes\GameScene.h"
#include "Scene\Scenes\TitleScene.h"
#include "Scene\Scenes\\PauseScene.h"

extern void ExitGame();

using namespace DirectX;

using Microsoft::WRL::ComPtr;

bool Game::s_screenMode = false;
DirectX::SimpleMath::Vector2 Game::s_windowMagnification = DirectX::SimpleMath::Vector2::Zero;

Game::Game()
{
    m_deviceResources = std::make_unique<DX::DeviceResources>();
    m_deviceResources->RegisterDeviceNotify(this);
	GameContext<DX::DeviceResources>::Register(m_deviceResources);
}

// Initialize the Direct3D resources required to run.
void Game::Initialize(HWND window, int width, int height)
{

	//マウスの作成
	m_pMouse = std::make_unique<Mouse>();
	m_pMouse->SetWindow(window);

	//キーボード作成
	m_pKeyboard = std::make_unique<Keyboard>();

	m_deviceResources->SetWindow(window, width, height);

    m_deviceResources->SetWindow(window, width, height);

    m_deviceResources->CreateDeviceResources();
    CreateDeviceDependentResources();

	auto device = m_deviceResources->GetD3DDevice();

	//コモンステート作成
	m_pState = std::make_unique<DirectX::CommonStates>(device);
	GameContext<DirectX::CommonStates>::Register(m_pState);


    m_deviceResources->CreateWindowSizeDependentResources();
    CreateWindowSizeDependentResources();



	m_pSceneManager = std::make_unique<SceneManager>();
	m_pSceneManager->RegisterState<TitleScene>("Title");
	m_pSceneManager->RegisterState<GameScene>("Game");
	m_pSceneManager->RegisterState<PauseScene>("Pause");
	m_pSceneManager->SetStartState("Title");
	GameContext<SceneManager>::Register(m_pSceneManager);


    // TODO: Change the timer settings if you want something other than the default variable timestep mode.
    // e.g. for 60 FPS fixed timestep update logic, call:
    /*
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 60);
    */


}

#pragma region Frame Update
// Executes the basic game loop.
void Game::Tick()
{
    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();
}

// Updates the world.
void Game::Update(DX::StepTimer const& timer)
{
    float elapsedTime = float(timer.GetElapsedSeconds());

    // TODO: Add your game logic here.
    elapsedTime;

	m_pSceneManager->Update(elapsedTime);
}
#pragma endregion

#pragma region Frame Render
// Draws the scene.
void Game::Render()
{
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    Clear();

    m_deviceResources->PIXBeginEvent(L"Render");
    auto context = m_deviceResources->GetD3DDeviceContext();

    // TODO: Add your rendering code here.
    context;

	m_pSceneManager->Render();

    m_deviceResources->PIXEndEvent();

    // Show the new frame.
    m_deviceResources->Present();
}

// Helper method to clear the back buffers.
void Game::Clear()
{
    m_deviceResources->PIXBeginEvent(L"Clear");

    // Clear the views.
    auto context = m_deviceResources->GetD3DDeviceContext();
    auto renderTarget = m_deviceResources->GetRenderTargetView();
    auto depthStencil = m_deviceResources->GetDepthStencilView();

    context->ClearRenderTargetView(renderTarget, Colors::CornflowerBlue);
    context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    context->OMSetRenderTargets(1, &renderTarget, depthStencil);

    // Set the viewport.
    auto viewport = m_deviceResources->GetScreenViewport();
    context->RSSetViewports(1, &viewport);

    m_deviceResources->PIXEndEvent();
}
#pragma endregion

#pragma region Message Handlers
// Message handlers
void Game::OnActivated()
{
    // TODO: Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: Game is being power-suspended (or minimized).
}

void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    // TODO: Game is being power-resumed (or returning from minimize).
}

void Game::OnWindowMoved()
{
    auto r = m_deviceResources->GetOutputSize();
    m_deviceResources->WindowSizeChanged(r.right, r.bottom);
}

void Game::OnWindowSizeChanged(int width, int height)
{
    if (!m_deviceResources->WindowSizeChanged(width, height))
        return;

    CreateWindowSizeDependentResources();

    // TODO: Game window is being resized.
}

// Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: Change to desired default window size (note minimum size is 320x200).
    width = SCREEN_W;
    height = SCREEN_H;

	// 画面のサイズ倍率
	s_windowMagnification.x = (float)MAX_SCREEN_W / (float)SCREEN_W;
	s_windowMagnification.y = (float)MAX_SCREEN_H / (float)SCREEN_H;
}
#pragma endregion

#pragma region Direct3D Resources
// These are the resources that depend on the device.
void Game::CreateDeviceDependentResources()
{
    auto device = m_deviceResources->GetD3DDevice();

    // TODO: Initialize device dependent objects here (independent of window size).
    device;
}

// Allocate all memory resources that change on a window SizeChanged event.
void Game::CreateWindowSizeDependentResources()
{
    // TODO: Initialize windows-size dependent objects here.
	//ニアクリップ(近距離表示可能範囲)
	float nearPlane = 0.01f;
	//ファークリップ(遠距離表示可能範囲)
	float farPlane = 1000.0f;

	//ウィンドウサイズからアスペクト比を算出する
	RECT size = m_deviceResources->GetOutputSize();
	float aspectRaito = float(size.right) / float(size.bottom);

	//画角を設定
	float forAngleY = XMConvertToRadians(45.0f);

	// 射影行列を作成する
	m_projection = std::make_unique<Projection>();
	m_projection->SetPerspectiveFieldOfView(
		forAngleY,
		aspectRaito,
		nearPlane,
		farPlane
	);
	GameContext<Projection>::Register(m_projection);



}

void Game::OnDeviceLost()
{
    // TODO: Add Direct3D resource cleanup here.
}

void Game::OnDeviceRestored()
{
    CreateDeviceDependentResources();

    CreateWindowSizeDependentResources();
}
#pragma endregion
