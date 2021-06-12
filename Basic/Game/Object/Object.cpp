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
	, m_velocity(0.f, 0.f, 0.f)
	, m_acceleration(DirectX::SimpleMath::Vector3::Zero)
{
}


Object::~Object()
{
}

void Object::Initialize()
{
}

void Object::Update(float elapsedTime)
{
	m_velocity = DirectX::SimpleMath::Vector3::Zero;
}

void Object::Render()
{
	DX::DeviceResources* deviceResources = GameContext::Get<DX::DeviceResources>();
	Camera* camera = gameWindow->GetCamera();

	if (!gameWindow || !m_model || !m_displayFlag) return;

	// ���[���h�s����쐬
	DirectX::SimpleMath::Matrix world = DirectX::SimpleMath::Matrix::CreateTranslation(m_pos);

	// ���f���̕`��
	m_model->Draw(deviceResources->GetD3DDeviceContext(), *GameContext::Get<DirectX::CommonStates>()
		, world, camera->GetViewMatrix(), camera->GetProjectionMatrix());

}

void Object::Finalize()
{
}

void Object::Move()
{
	DirectX::SimpleMath::Vector3 pos = GetPosition() + m_velocity;
	SetPosition(pos);
}

void Object::AddForce(float force, DirectX::SimpleMath::Quaternion angle)
{
	//����
	DirectX::SimpleMath::Vector3 dir(0.f, 0.f, -1.f);

	dir = DirectX::SimpleMath::Vector3::Transform(dir, angle);

	// �^���̖@��
	// F = ma�iF�F�́Am�F���ʁAa�F�����x�j
	m_acceleration = dir * (force / GetWeight());

	m_velocity += m_acceleration;
}

void Object::AddSpeed(DirectX::SimpleMath::Vector3 speed)
{
}
