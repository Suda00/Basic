#pragma once
//#ifndef FOLLOW_CAMERA
//#define FOLLOW_CAMERA

#include <SimpleMath.h>

class FollowCamera
{
private:
	//ビュー行列
	DirectX::SimpleMath::Matrix m_viewMatrix;
	//射影行列
	DirectX::SimpleMath::Matrix m_projectionMatrix;
	//視点
	DirectX::SimpleMath::Vector3 m_eye;
	//注視点
	DirectX::SimpleMath::Vector3 m_target;
	//ベクトル
	DirectX::SimpleMath::Vector3 m_up;

	// 参照視点
	DirectX::SimpleMath::Vector3 m_refEyePos;

	// 参照注視点
	DirectX::SimpleMath::Vector3 m_refTargetPos;



public:
	FollowCamera();
	~FollowCamera();

public:
	void Initialize(float fov, float aspect);
	void Update();


	//アクセッサ
	//ビュー行列の取得
	DirectX::SimpleMath::Matrix GetViewMatrix() {
		return m_viewMatrix;
	}
	//プロジェクション行列の取得
	DirectX::SimpleMath::Matrix GetProjectionMatrix() {
		return m_projectionMatrix;
	}


	//カメラの座標・注視点のアクセッサ(ゲッター・セッター)
	DirectX::SimpleMath::Vector3 GetTargetPosition() {
		return m_target;
	}

	void SetTargetPosition(DirectX::SimpleMath::Vector3 target) {
		m_target = target;
	}
	DirectX::SimpleMath::Vector3 GetEyePosition() {
		return m_eye;
	}

	void SetEyePosition(DirectX::SimpleMath::Vector3 eye) {
		m_eye = eye;
	}

	//参照視点・参照注視点のアクセッサ(ゲッター・セッター)
	DirectX::SimpleMath::Vector3 GetRefTargetPosition() {
		return m_refTargetPos;
	}

	void SetRefTargetPosition(DirectX::SimpleMath::Vector3 reftarget) {
		m_refTargetPos = reftarget;
	}
	DirectX::SimpleMath::Vector3 GetRefEyePosition() {
		return m_refEyePos;
	}

	void SetRefEyePosition(DirectX::SimpleMath::Vector3 refeye) {
		m_refEyePos = refeye;
	}


	DirectX::SimpleMath::Matrix FollowCamera::CreateMatrix_Screen2World(int screen_w, int screen_h);
};

//#endif // !FOLLOW_CAMERA
