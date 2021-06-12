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
	DirectX::SimpleMath::Vector3 m_velocity;		//���x

	DirectX::SimpleMath::Vector3 m_acceleration;	//�����x

	int m_durability;								//�ϋv��:(HP)

	float m_weight;									//�d��



public:
	Object();
	~Object();

public:

	void Initialize() override;	//������
	void Update(float elapsedTime) override;		//�X�V
	void Render() override;		//�`��
	void Finalize() override;	//�I��

	void Move();								//�ړ�

	DirectX::SimpleMath::Vector3 GetFollowPosition() { return m_followPos; }

	void AddForce(float force, DirectX::SimpleMath::Quaternion angle);
	void AddSpeed(DirectX::SimpleMath::Vector3 speed);

	//�d�ʂ̃Z�b�^�[�Q�b�^�[
	void SetWeight(float weight) { m_weight = weight; }
	float GetWeight() { return m_weight; }

	// �ړ��x�N�g���̃Q�b�^�[�Z�b�^�[
	void SetVelocity(DirectX::SimpleMath::Vector3 velocity) { m_velocity = velocity; }
	DirectX::SimpleMath::Vector3 GetVelocity() { return m_velocity;	}

	// �ϋv�͂̃Q�b�^�[�E�Z�b�^�[
	void SetDurability(int durability) { m_durability = durability; }
	int GetDurability() { return m_durability; }
	
};