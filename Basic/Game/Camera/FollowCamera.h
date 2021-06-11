#pragma once
//#ifndef FOLLOW_CAMERA
//#define FOLLOW_CAMERA

#include <SimpleMath.h>

class FollowCamera
{
private:
	//�r���[�s��
	DirectX::SimpleMath::Matrix m_viewMatrix;
	//�ˉe�s��
	DirectX::SimpleMath::Matrix m_projectionMatrix;
	//���_
	DirectX::SimpleMath::Vector3 m_eye;
	//�����_
	DirectX::SimpleMath::Vector3 m_target;
	//�x�N�g��
	DirectX::SimpleMath::Vector3 m_up;

	// �Q�Ǝ��_
	DirectX::SimpleMath::Vector3 m_refEyePos;

	// �Q�ƒ����_
	DirectX::SimpleMath::Vector3 m_refTargetPos;



public:
	FollowCamera();
	~FollowCamera();

public:
	void Initialize(float fov, float aspect);
	void Update();


	//�A�N�Z�b�T
	//�r���[�s��̎擾
	DirectX::SimpleMath::Matrix GetViewMatrix() {
		return m_viewMatrix;
	}
	//�v���W�F�N�V�����s��̎擾
	DirectX::SimpleMath::Matrix GetProjectionMatrix() {
		return m_projectionMatrix;
	}


	//�J�����̍��W�E�����_�̃A�N�Z�b�T(�Q�b�^�[�E�Z�b�^�[)
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

	//�Q�Ǝ��_�E�Q�ƒ����_�̃A�N�Z�b�T(�Q�b�^�[�E�Z�b�^�[)
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
