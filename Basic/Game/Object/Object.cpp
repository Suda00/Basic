//.cpp
//ゲーム内に必要な値を持つObjectの基底クラス
//【派生先】Playerなどゲームで実態を持つクラス【描画のその先へ】
//作成者：須田　ヒカル
//作成日：2021/05/26
//更新日：2021/05/27
//
#include "../../pch.h"
#include "Object.h"

#include <CommonStates.h>
#include "../../Common/GameContext.h"
#include "../../DeviceResources.h"
#include "../Camera/FollowCamera.h"


Object::Object()
	: GameObject()
	, m_velocity(0.f, 0.f, 0.f)
	, m_acceleration(DirectX::SimpleMath::Vector3::Zero)
{
}


Object::~Object()
{
}

// 初期化
void Object::Initialize()
{
}

// 更新
void Object::Update(float elapsedTime)
{
	m_velocity = DirectX::SimpleMath::Vector3::Zero;
}

// 描画
void Object::Render()
{
}

// 終了
void Object::Finalize()
{
}

// 移動
void Object::Move()
{
	DirectX::SimpleMath::Vector3 pos = GetPosition() + m_velocity;
	SetPosition(pos);
}

// 加速
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
	m_velocity = speed;
}
