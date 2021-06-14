//
// Game.h
//

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"

#include<CommonStates.h>

#include "Common\Projection.h"
#include "Keyboard.h"
#include "Mouse.h"

#include "Scene\SceneManager.h"


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game : public DX::IDeviceNotify
{
public:		// 静的メンバ
	// 画面サイズ
	static const int SCREEN_W = 1280;
	static const int SCREEN_H = 720;

private:	// 静的メンバ
	// 最大画面サイズ
	static const int MAX_SCREEN_W = 1920;
	static const int MAX_SCREEN_H = 1080;

	// 画面モード
	static bool s_screenMode;

	//画面の倍率
	static DirectX::SimpleMath::Vector2 s_windowMagnification;


public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowMoved();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

	//画面モードを獲得する
	static void SetWindowMode(bool mode) { s_screenMode = mode; }
	static bool GetWindowMode() { return s_screenMode; }

	static DirectX::SimpleMath::Vector2 GetWindowMagnification() { return s_windowMagnification; }


private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>    m_deviceResources;

    // Rendering loop timer.
    DX::StepTimer                           m_timer;

	//射影行列
	std::unique_ptr<Projection>				m_projection;

	// コモンステート
	std::unique_ptr<DirectX::CommonStates>	m_pState;

	//マウス
	std::unique_ptr<DirectX::Mouse>			m_pMouse;

	//キーボード
	std::unique_ptr<DirectX::Keyboard>		m_pKeyboard;

	//シーンマネージャー
	std::unique_ptr<SceneManager>			m_pSceneManager;

};