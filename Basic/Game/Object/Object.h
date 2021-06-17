//.h
//�Q�[�����ɕK�v�Ȓl������Object�̊��N���X
//�y�h����zPlayer�ȂǃQ�[���Ŏ��Ԃ����N���X�y�`��̂��̐�ցz
//�쐬�ҁF�{�c�@�q�J��
//�쐬���F2021/05/26
//�X�V���F2021/05/27
//
#pragma once
#include "GameObject.h"



class Object:public GameObject
{
private:
	Bool m_ground;
	Bool m_moving;			// �ړ�����

	DirectX::SimpleMath::Vector3 m_velocity;		//���x

	DirectX::SimpleMath::Vector3 m_acceleration;	//�����x

	int m_durability;								//�ϋv��:(HP)

	float m_mass;									//�d��

	float m_friction;	// ���C�W��


public:
	Object();
	~Object();

public:

	void Update(float elapsedTime) override;		//�X�V
	void Render() override;		//�`��

	void Move();								//�ړ�


	void AddForce(float force, DirectX::SimpleMath::Quaternion angle);
	void AddSpeed(DirectX::SimpleMath::Vector3 speed);

	void Friction(Object* obj,float elapsedTime);

	//�@�n�ʂɂ��Ă��邩(���点�Ă���̂�)
	Bool GetGround() { return m_ground; };

	Bool GetMoving() { return m_moving; }

	// ���C�W���̃Z�b�^�[�Q�b�^�[
	void SetFriction(float friction) { m_friction = friction; }
	float GetFriction() { return m_friction; }

	//�d�ʂ̃Z�b�^�[�Q�b�^�[
	void SetMass(float mass) { m_mass = mass; }
	float GetMass() { return m_mass; }

	// �ړ��x�N�g���̃Q�b�^�[�Z�b�^�[
	void SetVelocity(DirectX::SimpleMath::Vector3 velocity) { m_velocity = velocity; }
	DirectX::SimpleMath::Vector3 GetVelocity() { return m_velocity;	}

	// �ϋv�͂̃Q�b�^�[�E�Z�b�^�[
	void SetDurability(int durability) { m_durability = durability; }
	int GetDurability() { return m_durability; }
	
};