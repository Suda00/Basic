#include "../../pch.h"
#include "FollowCamera.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;

FollowCamera::FollowCamera()
{
}


FollowCamera::~FollowCamera()
{
}


void FollowCamera::Initialize(float fov, float aspect)
{
	//�j�A�N���b�v(�ߋ����\���\�͈�)
	float nearPlane = 0.01f;
	//�t�@�[�N���b�v(�������\���\�͈�)
	float farPlane = 1000.0f;

	//�����l�ݒ�
	m_target = DirectX::SimpleMath::Vector3(0.0f, 0.0f, 0.0f);
	m_refTargetPos = m_target;//�Q�ƒ����_������
	m_eye = DirectX::SimpleMath::Vector3(0.0f, 1.0f, 3.0f);
	m_refEyePos = m_eye;//�Q�Ǝ��_������
	DirectX::SimpleMath::Vector3 up(0, 1.0f, 0);

	//�r���[�s�񏉊���
	m_viewMatrix =
		DirectX::SimpleMath::Matrix::CreateLookAt(
			m_eye,
			m_target,
			up);

	m_projectionMatrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(
		DirectX::XMConvertToRadians(45.0f),
		800 / 600,
		nearPlane,
		farPlane);
	


	m_projectionMatrix = Matrix::CreatePerspectiveFieldOfView(
		fov,
		aspect,
		nearPlane,
		farPlane
	);



}

void FollowCamera::Update()
{
	//�Ǐ]���x�F�P�{
	m_eye += (m_refEyePos - m_eye) * 1.0f;
	m_target += (m_refTargetPos - m_target) * 1.f;

	m_viewMatrix = Matrix::CreateLookAt(m_eye, m_target, m_up);

}

/*
//���@�@�F�X�N���[�����W�����[���h���W�ɕϊ�����s����쐬����֐�
//�����@�Fint screen_w�@		�X�N���[���̕�
//�����@�Fint screen_h�@		�X�N���[���̍���
//�Ԃ�l�FinvS * invP * invV	�t���W
*/
Matrix FollowCamera::CreateMatrix_Screen2World(int screen_w, int screen_h)
{
	// �r���[�|�[�g�X�P�[�����O�s����쐬
	Matrix viewport;
	viewport._11 = screen_w / 2.0f;
	viewport._22 = -screen_h / 2.0f;
	viewport._41 = screen_w / 2.0f;
	viewport._42 = screen_h / 2.0f;

	// �t�s����쐬
	Matrix invS = viewport.Invert();
	Matrix invP = m_projectionMatrix.Invert();
	Matrix invV = m_viewMatrix.Invert();

	// �w�r���[�|�[�g�X�P�[�����O�s��̋t�s��x �~ �w�ˉe�s��̋t�s��x �~ �w�r���[�s��̋t�s��x
	return invS * invP * invV;
}

