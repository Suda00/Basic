//.h
//���̂̍s��ɕK�v�Ȓl������Object�̊��N���X
//�y�h����z�Q�[���ɕK�v�Ȓl�����N���XObject�N���X�y��������N���X�I�H�z
//�쐬�ҁF�{�c�@�q�J��
//�쐬���F2021/05/26
//�X�V���F2021/05/26
//
#pragma once

#include <SimpleMath.h>
#include <string>

class ModelObject
{
private:
	DirectX::SimpleMath::Vector3 m_position;			//	�ʒu
	DirectX::SimpleMath::Vector3 m_scale;				//	�g�嗦
	DirectX::SimpleMath::Quaternion m_quaternion;		//�@��]

	std::string m_tag;									//�@�����蔻��p�^�O

public:
	ModelObject(const std::string& tag = "GameObject");
	virtual ~ModelObject() = default;

public:
	//�������z�֐�
	virtual void Initialize() = 0;	//������
	virtual void Update(float elapsedTime) = 0;		//�X�V
	virtual void Render() = 0;		//�`��
	virtual void Finalize() = 0;	//�I��


	const std::string& GetTag() const;
	const DirectX::SimpleMath::Vector3& GetPosition() const;
	const DirectX::SimpleMath::Vector3& GetScale() const;
	const DirectX::SimpleMath::Quaternion& GetQuaternion() const;

	void SetTag(const std::string& tag);
	void SetPosition(DirectX::SimpleMath::Vector3& position);
	void SetScale(DirectX::SimpleMath::Vector3& scale);
	void SetQuaternion(DirectX::SimpleMath::Quaternion& quaternion);

};

/* �Q�b�^�[�֐� */
inline const std::string & ModelObject::GetTag() const
{
	return m_tag;
}

inline const DirectX::SimpleMath::Vector3 & ModelObject::GetPosition() const
{
	return m_position;
}

inline const DirectX::SimpleMath::Vector3 & ModelObject::GetScale() const
{
	return m_scale;
}

inline const DirectX::SimpleMath::Quaternion & ModelObject::GetQuaternion() const
{
	return m_quaternion;
}


/* �Z�b�^�[�֐� */
inline void ModelObject::SetTag(const std::string & tag)
{
	m_tag = tag;
}

inline void ModelObject::SetPosition(DirectX::SimpleMath::Vector3 & position)
{
	m_position = position;
}

inline void ModelObject::SetScale(DirectX::SimpleMath::Vector3 & scale)
{
	m_scale = scale;
}

inline void ModelObject::SetQuaternion(DirectX::SimpleMath::Quaternion & quaternion)
{
	m_quaternion = quaternion;
}

