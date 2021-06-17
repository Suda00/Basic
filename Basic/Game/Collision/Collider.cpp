#include "../../pch.h"
#include "Collider.h"

#include "../Object/GameObject.h"


Collider::Collider(GameObject* owner)
	: m_owner(owner)
	, m_offset(DirectX::SimpleMath::Vector3::Zero)
{
	
}

bool Collider::IsCollided(const SphereCollider * collider) const
{
	return false;
}

bool Collider::IsCollided(const BoxCollider * collider) const
{
	return false;
}

void Collider::OnCollision(const Collider * object) const
{
	m_owner->OnCollision(object->m_owner);
}

const DirectX::SimpleMath::Vector3 Collider::GetPosition() const
{
	return m_owner->GetPosition() + m_offset;
}

const DirectX::SimpleMath::Vector3 Collider::GetOffset() const
{
	return m_offset;
}

void Collider::SetOffset(const DirectX::SimpleMath::Vector3 & offset)
{
	m_offset = offset;
}
