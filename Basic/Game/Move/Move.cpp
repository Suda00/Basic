//.h
//移動に関する計算を行うクラス
//作成者：須田　ヒカル
//作成日：2021/06/01
//更新日：2021/06/04
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

//加速
void Move::AddForce(float force, DirectX::SimpleMath::Quaternion angle)
{
	//方向
	DirectX::SimpleMath::Vector3 dir(0.f, 0.f, -1.f);

	dir = DirectX::SimpleMath::Vector3::Transform(dir, angle);

	// 運動の法則
	// F = ma（F：力、m：質量、a：加速度）
	m_acceleration = dir * (force / m_owner->GetWeight());

	m_velocity += m_acceleration;
}

//移動の更新
//※自身を中心とした回転のみ
void Move::Moving()
{
	//位置の更新
	m_owner->SetPosition(m_owner->GetPosition() + m_velocity);
}

//追従を解除する
void Move::ReleaseParent()
{
	//解除
	m_parent = nullptr;
}                                    

