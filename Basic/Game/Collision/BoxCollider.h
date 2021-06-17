// 箱の当たり判定
#pragma once
#include "Collider.h"

class BoxCollider :	public Collider
{
private:
	DirectX::SimpleMath::Vector3 m_size;
public:
	BoxCollider(GameObject* owner, const DirectX::SimpleMath::Vector3& size = DirectX::SimpleMath::Vector3(1.0f, 1.0f, 1.0f));
	~BoxCollider() = default;

	// 衝突判定
	bool IsCollided(const Collider*       collider) const override;
	bool IsCollided(const SphereCollider* collider) const override;
	bool IsCollided(const BoxCollider*    collider) const override;

	// サイズのセッターゲッター
	void SetSize(const DirectX::SimpleMath::Vector3& size);
	const DirectX::SimpleMath::Vector3& GetSize() const;

};

