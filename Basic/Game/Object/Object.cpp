//.cpp
//�Q�[�����ɕK�v�Ȓl������Object�̊��N���X
//�y�h����zPlayer�ȂǃQ�[���Ŏ��Ԃ����N���X�y�`��̂��̐�ցz
//�쐬�ҁF�{�c�@�q�J��
//�쐬���F2021/05/26
//�X�V���F2021/05/27
//
#include "../../pch.h"
#include "Object.h"


Object::Object()
	:ModelObject()
	,m_velocity(0.f, 0.f, 0.f)
	,m_followPos(DirectX::SimpleMath::Vector3::Zero)
{
}


Object::~Object()
{
}

void Object::Move()
{
	DirectX::SimpleMath::Vector3 pos = GetPosition() + m_velocity;
	SetPosition(pos);
}
