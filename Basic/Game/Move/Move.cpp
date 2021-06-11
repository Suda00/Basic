//.h
//�ړ��Ɋւ���v�Z���s���N���X
//�쐬�ҁF�{�c�@�q�J��
//�쐬���F2021/06/01
//�X�V���F2021/06/04
//
#include "../../pch.h"
#include "Move.h"


Move::Move(float maxSpeed,Object* owner, Object* parent)
	: MAX_SPEED(maxSpeed)
	, m_owner(owner)
	, m_parent(parent)
	, m_targetAngle(0.f)
	, m_acceleration(DirectX::SimpleMath::Vector3::Zero)
{
}


Move::~Move()
{
}

void Move::Initialize()
{

	
}

void Move::Update(float elapsedTime)
{
}

//����
void Move::AddForce(float force, DirectX::SimpleMath::Quaternion angle)
{
	//����
	DirectX::SimpleMath::Vector3 dir(0.f, 0.f, -1.f);

	dir = DirectX::SimpleMath::Vector3::Transform(dir, angle);

	//F = ma�iF�F�́Am�F���ʁAa�F�����x�j
	m_acceleration = dir * (force / m_owner->GetWeight());

	m_velocity += m_acceleration;
}

//�ړ��̍X�V
//�����g�𒆐S�Ƃ�����]�̂�
void Move::Moving()
{
	//��]�p�̍X�V
	DirectX::SimpleMath::Vector3 axisY(0.0f,1.0f,0.0f);
	DirectX::SimpleMath::Quaternion targetRot = DirectX::SimpleMath::Quaternion::CreateFromAxisAngle(axisY, m_targetAngle);
	//��]���
	DirectX::SimpleMath::Quaternion retRot = DirectX::SimpleMath::Quaternion::Slerp(m_owner->GetQuaternion(), targetRot, 0.1f);

	//�|�W�V�����̍X�V
	DirectX::SimpleMath::Vector3 pos(DirectX::SimpleMath::Vector3::Zero);

	//�Ǐ]���镨������Ȃ�
	if (m_parent != nullptr) {
		//�ʒu��Ǐ]���镨�ɍ��킹��
		pos = m_parent->GetPosition() + m_owner->GetFollowPosition();

		//�e�̉�]��������
		retRot *= m_parent->GetQuaternion();

	}
	//�Ȃ��Ȃ�
	else {
		//���x�̕����ړ�
		pos = m_owner->GetPosition() + m_velocity;
	}

	//�ʒu����]�ɍ��킹��
	pos = DirectX::SimpleMath::Vector3::Transform(pos, retRot);

	//��](���])�̍X�V
	m_owner->SetQuaternion(retRot);
	//�ʒu�̍X�V
	m_owner->SetPosition(pos);

}

//�Ǐ]����������
void Move::ReleaseParent()
{
	//����
	m_parent = nullptr;
}                                    

