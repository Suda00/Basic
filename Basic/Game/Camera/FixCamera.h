#pragma once


#include <SimpleMath.h>

class FixCamera
{
private:
	//ビュー行列
	DirectX::SimpleMath::Matrix m_viewMatrix;
	//射影行列
	DirectX::SimpleMath::Matrix m_projrctionMatrix;
	//視点
	DirectX::SimpleMath::Vector3 m_eye;
	//注視点
	DirectX::SimpleMath::Vector3 m_target;
	//ベクトル
	DirectX::SimpleMath::Vector3 m_up;


public:
	FixCamera();
	~FixCamera();

public:
	void Initialize(float fov,float aspect);
	void Update();


	//アクセッサ
	//ビュー行列の取得
	DirectX::SimpleMath::Matrix GetViewMatrix() {
		return m_viewMatrix;
	}
	//プロジェクション行列の取得
	DirectX::SimpleMath::Matrix GetProjrctionMatrix() {
		return m_projrctionMatrix;
	}

	//注視点のアクセッサ(ゲッター・セッター)
	DirectX::SimpleMath::Vector3 GetTargetPsotion() {
		return m_target;
	}

	void SetTargetPsotion(DirectX::SimpleMath::Vector3 target) {
		m_target = target;
	}

};

