//.cpp
//���f���`��ɕK�v�Ȓl������Object�̊��N���X
//�y�h����z�Q�[���ɕK�v�Ȓl�����N���XObject�N���X�y��������N���X�I�H�z
//�쐬�ҁF�{�c�@�q�J��
//�쐬���F2021/05/26
//�X�V���F2021/05/26
//
#include "../../pch.h"
#include "ModelObject.h"


ModelObject::ModelObject(const std::string& tag)
	: m_tag(tag)
	, m_position(0.0f, 0.0f, 0.0f)
	, m_quaternion(0.0f, 0.0f, 0.0f,0.f)
	, m_scale(1.0f, 1.0f, 1.0f)
{
}


