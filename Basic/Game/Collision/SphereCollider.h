#pragma once
#include "Collider.h"

class SphereCollider :
	public Collider
{
private:
	float m_radius;		//半径


public:
	SphereCollider(GameObject* owner, float radius = 1.0f);
	~SphereCollider() = default;


	//衝突判定
	bool IsCollided(const Collider*       collider) const override;
	bool IsCollided(const SphereCollider* collider) const override;
	bool IsCollided(const BoxCollider*    collider) const override;

	// 半径のセッターゲッター
	float GetRadius() const;
	void  SetRadius(float radius);
};

