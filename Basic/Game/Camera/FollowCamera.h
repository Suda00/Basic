#pragma once
//#ifndef FOLLOW_CAMERA
//#define FOLLOW_CAMERA

#include <SimpleMath.h>
#include "../Object/Object.h"

class FollowCamera
{
private:
	// �Ǐ]�Ώۂ̃I�u�W�F�N�g
	Object* m_targetObj;

	// �J�����̈ړ��̒�~
	bool m_enableFixed;
	
	//�r���[�s��
	DirectX::SimpleMath::Matrix m_viewMatrix;
	//�ˉe�s��
	DirectX::SimpleMath::Matrix m_projectionMatrix;


	//���_(�J�����ʒu)
	DirectX::SimpleMath::Vector3 m_eye;	

	//�����̍���
	DirectX::SimpleMath::Vector3 m_up;
	// �ڐ��̍����̔{��
	float m_height, m_targetHeight;

	// �J�����Ԃ̋���	
	float m_distance, m_targetDistance;

	// �J�����̉�]�p�x
	DirectX::SimpleMath::Vector3 m_rotation, m_targetRotation;

	// �ʒu�Ǐ]���x�Ɖ�]�Ǐ]���x
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

	//�A�N�Z�b�T
	//�r���[�s��̎擾
	DirectX::SimpleMath::Matrix GetViewMatrix() {
		return m_viewMatrix;
	}
	//�v���W�F�N�V�����s��̎擾
	DirectX::SimpleMath::Matrix GetProjectionMatrix() {
		return m_projectionMatrix;
	}


	DirectX::SimpleMath::Matrix FollowCamera::CreateMatrix_Screen2World(int screen_w, int screen_h);
};

//#endif // !FOLLOW_CAMERA
