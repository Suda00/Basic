#include "../../pch.h"

#include "SphereCollider.h"
#include "../Object/GameObject.h"


// コンストラクタ
SphereCollider::SphereCollider(GameObject* owner, float radius)
	: Collider(owner)
	, m_radius(radius)
{
}

// 衝突判定
bool SphereCollider::IsCollided(const Collider* collider) const
{
	return collider->IsCollided(this);
}

// 球と球の判定
bool SphereCollider::IsCollided(const SphereCollider* collider) const
{
	return false;
}

// 球と箱の判定
bool SphereCollider::IsCollided(const BoxCollider* collider) const
{
	return false;
}


void SphereCollider::SetRadius(float radius)
{
	m_radius = radius;
}


float SphereCollider::GetRadius() const
{
	return m_radius;
}
