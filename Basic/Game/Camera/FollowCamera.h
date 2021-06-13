#pragma once
//#ifndef FOLLOW_CAMERA
//#define FOLLOW_CAMERA

#include <SimpleMath.h>
#include "../Object/Object.h"

class FollowCamera
{
private:
	// 追従対象のオブジェクト
	Object* m_targetObj;

	// カメラの移動の停止
	bool m_enableFixed;
	
	//ビュー行列
	DirectX::SimpleMath::Matrix m_viewMatrix;
	//射影行列
	DirectX::SimpleMath::Matrix m_projectionMatrix;


	//視点(カメラ位置)
	DirectX::SimpleMath::Vector3 m_eye;	

	//視線の高さ
	DirectX::SimpleMath::Vector3 m_up;
	// 目線の高さの倍率
	float m_height, m_targetHeight;

	// カメラ間の距離	
	float m_distance, m_targetDistance;

	// カメラの回転角度
	DirectX::SimpleMath::Vector3 m_rotation, m_targetRotation;

	// 位置追従速度と回転追従速度
	float m_posFollowSpeed;
	float m_rotFollowSpeed;

public:
	FollowCamera();
	~FollowCamera();

public:
	void Initialize(Object* target, float distance = 1.f, float height = 1.f, DirectX::SimpleMath::Vector3 rotation = DirectX::SimpleMath::Vector3::Zero);
	void Update(float elapsedTime);

	void ChengeDistance(float magnification);
	void ChengeRotation();

	//アクセッサ
	//ビュー行列の取得
	DirectX::SimpleMath::Matrix GetViewMatrix() {
		return m_viewMatrix;
	}
	//プロジェクション行列の取得
	DirectX::SimpleMath::Matrix GetProjectionMatrix() {
		return m_projectionMatrix;
	}


	DirectX::SimpleMath::Matrix FollowCamera::CreateMatrix_Screen2World(int screen_w, int screen_h);
};

//#endif // !FOLLOW_CAMERA
