#include "../../pch.h"
#include "FixCamera.h"


FixCamera::FixCamera()
{
}


FixCamera::~FixCamera()
{
}


void FixCamera::Initialize(float fov, float aspect)
{
	//ニアクリップ(近距離表示可能範囲)
	float nearPlane = 0.01f;
	//ファークリップ(遠距離表示可能範囲)
	float farPlane = 1000.0f;

	m_projrctionMatrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(
		fov,
		aspect,
		nearPlane,
		farPlane
	);

	//ビュー行列作成
	m_eye = DirectX::SimpleMath::Vector3(0.0f, 1.0f, 10.0f);
	m_target = DirectX::SimpleMath::Vector3(0.0f, 0.0f, 0.0f);
	m_up = DirectX::SimpleMath::Vector3(0.0f, 1.0f, 0.0f);

	m_viewMatrix = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye, m_target, m_up);

}

void FixCamera::Update()
{
	m_viewMatrix = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye, m_target, m_up);

}
