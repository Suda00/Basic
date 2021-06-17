//.h
//ゲーム内に必要な値を持つObjectの基底クラス
//【派生先】Playerなどゲームで実態を持つクラス【描画のその先へ】
//作成者：須田　ヒカル
//作成日：2021/05/26
//更新日：2021/05/27
//
#pragma once
#include "GameObject.h"



class Object:public GameObject
{
private:
	Bool m_ground;
	Bool m_moving;			// 移動中か

	DirectX::SimpleMath::Vector3 m_velocity;		//速度

	DirectX::SimpleMath::Vector3 m_acceleration;	//加速度

	int m_durability;								//耐久力:(HP)

	float m_mass;									//重量

	float m_friction;	// 摩擦係数


public:
	Object();
	~Object();

public:

	void Update(float elapsedTime) override;		//更新
	void Render() override;		//描画

	void Move();								//移動


	void AddForce(float force, DirectX::SimpleMath::Quaternion angle);
	void AddSpeed(DirectX::SimpleMath::Vector3 speed);

	void Friction(Object* obj,float elapsedTime);

	//　地面についているか(滑らせているのか)
	Bool GetGround() { return m_ground; };

	Bool GetMoving() { return m_moving; }

	// 摩擦係数のセッターゲッター
	void SetFriction(float friction) { m_friction = friction; }
	float GetFriction() { return m_friction; }

	//重量のセッターゲッター
	void SetMass(float mass) { m_mass = mass; }
	float GetMass() { return m_mass; }

	// 移動ベクトルのゲッターセッター
	void SetVelocity(DirectX::SimpleMath::Vector3 velocity) { m_velocity = velocity; }
	DirectX::SimpleMath::Vector3 GetVelocity() { return m_velocity;	}

	// 耐久力のゲッター・セッター
	void SetDurability(int durability) { m_durability = durability; }
	int GetDurability() { return m_durability; }
	
};