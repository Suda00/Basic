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
	//�j�A�N���b�v(�ߋ����\���\�͈�)
	float nearPlane = 0.01f;
	//�t�@�[�N���b�v(�������\���\�͈�)
	float farPlane = 1000.0f;

	m_projrctionMatrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(
		fov,
		aspect,
		nearPlane,
		farPlane
	);

	//�r���[�s��쐬
	m_eye = DirectX::SimpleMath::Vector3(0.0f, 1.0f, 10.0f);
	m_target = DirectX::SimpleMath::Vector3(0.0f, 0.0f, 0.0f);
	m_up = DirectX::SimpleMath::Vector3(0.0f, 1.0f, 0.0f);

	m_viewMatrix = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye, m_target, m_up);

}

void FixCamera::Update()
{
	m_viewMatrix = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye, m_target, m_up);

}
