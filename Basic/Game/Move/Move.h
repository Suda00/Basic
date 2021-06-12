//.h
//�ړ��Ɋւ���v�Z���s���N���X
//�쐬�ҁF�{�c�@�q�J��
//�쐬���F2021/06/01
//�X�V���F2021/06/04
//
#pragma once
#include"../Object/Object.h"

class Move
{
private:
	static const float GRAVITY;

	const float MAX_SPEED;		//�ő呬�x

private:
	Object *m_owner;		// �ړ��ɕK�v�ȕϐ��̎�����
	Object *m_parent;		// �e�q�֌W�ɂ���I�u�W�F�N�g

	DirectX::SimpleMath::Vector3 m_velocity;	//�ړ��p�����x�N�g��

	DirectX::SimpleMath::Vector3 m_acceleration;		//������

	float m_targetAngle;		//��]�p

public:
	Move(float maxSpeed, Object* owner, Object* parent = nullptr);
	~Move();

	void Initialize();
	void Update(float elapsedTime);

	void AddForce(float force, DirectX::SimpleMath::Quaternion angle);
	void Transform(DirectX::SimpleMath::Vector3 velocity);

	void Moving();
	void ReleaseParent();
	void SetParent(Object * parent);
};

//�e�̐ݒ�
inline void Move::SetParent(Object * parent)
{
	m_parent = parent;
}
