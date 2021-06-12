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
private:	// �ÓI�����o
	// ��ʃT�C�Y
	static const int SCREEN_W = 1280;
	static const int SCREEN_H = 720;

	// �ő��ʃT�C�Y
	static const int MAX_SCREEN_W = 1920;
	static const int MAX_SCREEN_H = 1080;

	// ��ʃ��[�h
	static bool m_screenMode;

	//��ʂ̔{��
	static DirectX::SimpleMath::Vector2 m_windowMagnification;


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

	//��ʃ��[�h���l������
	static void SetWindowMode(bool mode) { m_screenMode = mode; }
	static bool GetWindowMode() { return m_screenMode; }

	static DirectX::SimpleMath::Vector2 GetWindowMagnification() { return m_windowMagnification; }


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

	//�ˉe�s��
	std::unique_ptr<Projection>				m_projection;

	// �R�����X�e�[�g
	std::unique_ptr<DirectX::CommonStates>	m_pState;

	//�}�E�X
	std::unique_ptr<DirectX::Mouse>			m_pMouse;

	//�L�[�{�[�h
	std::unique_ptr<DirectX::Keyboard>		m_pKeyboard;

	//�V�[���}�l�[�W���[
	std::unique_ptr<SceneManager>			m_pSceneManager;

};