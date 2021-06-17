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
#include "../Parameter.h"


Object::Object()
	: GameObject()
	, m_velocity(0.f, 0.f, 0.f)
	, m_acceleration(DirectX::SimpleMath::Vector3::Zero)
	, m_ground()
{
}


Object::~Object()
{
}


// 更新
void Object::Update(float elapsedTime)
{

}

// 描画
void Object::Render()
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
	m_acceleration = dir * (force / GetMass());

	m_velocity += m_acceleration;
}

void Object::AddSpeed(DirectX::SimpleMath::Vector3 speed)
{
	m_velocity = speed;
}

//摩擦力計算
void Object::Friction(Object* obj,float elapsedTime)
{
	// 地面に接地していないなら摩擦は発生しない
	if (m_ground.InValid())return;

	// 摩擦係数計算
	float friction = std::min(m_friction, obj->GetFriction());
	// 静摩擦係数の再現
	if (m_moving.InValid())friction *= 1.2f;

	/*/ 摩擦力計算/*/
	//F'＝μN : F' = 摩擦力[N], μ = 摩擦係数, N = 垂直抗力
	//N = Mg : M = 質量[kg]、g = 重力加速度[m/s2]
	float frictionForce = friction *(m_mass * Parameter::GRAVITY);
	
	// F = ma（F：力、m：質量、a：加速度）
	float vec = (frictionForce / m_mass) * elapsedTime;

	if (m_velocity.LengthSquared() > vec * vec) {
		vec = m_velocity.Length() - vec;
		m_velocity.Normalize();
		m_velocity *= vec;
	}
	else {
		m_velocity = DirectX::SimpleMath::Vector3::Zero;
	}


}
