//.cpp
//ゲーム内に必要な値を持つObjectの基底クラス
//【派生先】Playerなどゲームで実態を持つクラス【描画のその先へ】
//作成者：須田　ヒカル
//作成日：2021/05/26
//更新日：2021/05/27
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

	// ワールド行列を作成
	DirectX::SimpleMath::Matrix world = DirectX::SimpleMath::Matrix::CreateTranslation(m_pos);

	// モデルの描画
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
	//方向
	DirectX::SimpleMath::Vector3 dir(0.f, 0.f, -1.f);

	dir = DirectX::SimpleMath::Vector3::Transform(dir, angle);

	// 運動の法則
	// F = ma（F：力、m：質量、a：加速度）
	m_acceleration = dir * (force / GetWeight());

	m_velocity += m_acceleration;
}

void Object::AddSpeed(DirectX::SimpleMath::Vector3 speed)
{
}
