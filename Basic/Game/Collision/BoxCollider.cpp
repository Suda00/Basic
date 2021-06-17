#include "../../pch.h"
#include "BoxCollider.h"

// コンストラクタ
BoxCollider::BoxCollider(GameObject* owner, const DirectX::SimpleMath::Vector3& size = DirectX::SimpleMath::Vector3(1.0f, 1.0f, 1.0f))
	: Collider(owner)
	, m_size(size)
{
}

// 衝突判定
bool BoxCollider::IsCollided(const Collider * collider) const
{
	return collider->IsCollided(this);
}

// 球と箱の衝突
bool BoxCollider::IsCollided(const SphereCollider * collider) const
{
	return false;
}

// 箱と箱の衝突
bool BoxCollider::IsCollided(const BoxCollider * collider) const
{
	return false;
}

// サイズのセッター
void BoxCollider::SetSize(const DirectX::SimpleMath::Vector3 & size)
{
	m_size = size;
}

// サイズのゲッター
const DirectX::SimpleMath::Vector3 & BoxCollider::GetSize() const
{
	return m_size;
}


