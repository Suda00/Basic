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

	// �^���̖@��
	// F = ma�iF�F�́Am�F���ʁAa�F�����x�j
	m_acceleration = dir * (force / m_owner->GetWeight());

	m_velocity += m_acceleration;
}

//�ړ��̍X�V
//�����g�𒆐S�Ƃ�����]�̂�
void Move::Moving()
{
	//�ʒu�̍X�V
	m_owner->SetPosition(m_owner->GetPosition() + m_velocity);
}

//�Ǐ]����������
void Move::ReleaseParent()
{
	//����
	m_parent = nullptr;
}                                    

