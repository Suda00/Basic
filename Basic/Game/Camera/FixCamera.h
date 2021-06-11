#pragma once


#include <SimpleMath.h>

class FixCamera
{
private:
	//�r���[�s��
	DirectX::SimpleMath::Matrix m_viewMatrix;
	//�ˉe�s��
	DirectX::SimpleMath::Matrix m_projrctionMatrix;
	//���_
	DirectX::SimpleMath::Vector3 m_eye;
	//�����_
	DirectX::SimpleMath::Vector3 m_target;
	//�x�N�g��
	DirectX::SimpleMath::Vector3 m_up;


public:
	FixCamera();
	~FixCamera();

public:
	void Initialize(float fov,float aspect);
	void Update();


	//�A�N�Z�b�T
	//�r���[�s��̎擾
	DirectX::SimpleMath::Matrix GetViewMatrix() {
		return m_viewMatrix;
	}
	//�v���W�F�N�V�����s��̎擾
	DirectX::SimpleMath::Matrix GetProjrctionMatrix() {
		return m_projrctionMatrix;
	}

	//�����_�̃A�N�Z�b�T(�Q�b�^�[�E�Z�b�^�[)
	DirectX::SimpleMath::Vector3 GetTargetPsotion() {
		return m_target;
	}

	void SetTargetPsotion(DirectX::SimpleMath::Vector3 target) {
		m_target = target;
	}

};

