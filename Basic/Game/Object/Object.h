//.h
//�Q�[�����ɕK�v�Ȓl������Object�̊��N���X
//�y�h����zPlayer�ȂǃQ�[���Ŏ��Ԃ����N���X�y�`��̂��̐�ցz
//�쐬�ҁF�{�c�@�q�J��
//�쐬���F2021/05/26
//�X�V���F2021/05/27
//
#pragma once
#include "ModelObject.h"


class Object:public ModelObject
{
private:
	DirectX::SimpleMath::Vector3 m_followPos;	//��{��pos�Ɠ����F�Ǐ]���镨������ꍇ�̈ʒu

	DirectX::SimpleMath::Vector3 m_velocity;	//�ړ��p�����x�N�g��

	int m_durability;							//�ϋv��:(HP)

	float m_weight;								//�d��



public:
	Object();
	~Object();

public:
	void Move();								//�ړ�

	DirectX::SimpleMath::Vector3 GetFollowPosition() { return m_followPos; }

	float GetWeight() { return m_weight; }

	// �ړ��x�N�g���̃Q�b�^�[�Z�b�^�[
	void SetVelocity(DirectX::SimpleMath::Vector3 velocity) { m_velocity = velocity; }
	DirectX::SimpleMath::Vector3 GetVelocity() { return m_velocity;	}
	
};