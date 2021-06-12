//.h
//ゲーム内に必要な値を持つObjectの基底クラス
//【派生先】Playerなどゲームで実態を持つクラス【描画のその先へ】
//作成者：須田　ヒカル
//作成日：2021/05/26
//更新日：2021/05/27
//
#pragma once
#include "ModelObject.h"


class Object:public ModelObject
{
private:
	DirectX::SimpleMath::Vector3 m_velocity;		//速度

	DirectX::SimpleMath::Vector3 m_acceleration;	//加速度

	int m_durability;								//耐久力:(HP)

	float m_weight;									//重量



public:
	Object();
	~Object();

public:

	void Initialize() override;	//初期化
	void Update(float elapsedTime) override;		//更新
	void Render() override;		//描画
	void Finalize() override;	//終了

	void Move();								//移動

	DirectX::SimpleMath::Vector3 GetFollowPosition() { return m_followPos; }

	void AddForce(float force, DirectX::SimpleMath::Quaternion angle);
	void AddSpeed(DirectX::SimpleMath::Vector3 speed);

	//重量のセッターゲッター
	void SetWeight(float weight) { m_weight = weight; }
	float GetWeight() { return m_weight; }

	// 移動ベクトルのゲッターセッター
	void SetVelocity(DirectX::SimpleMath::Vector3 velocity) { m_velocity = velocity; }
	DirectX::SimpleMath::Vector3 GetVelocity() { return m_velocity;	}

	// 耐久力のゲッター・セッター
	void SetDurability(int durability) { m_durability = durability; }
	int GetDurability() { return m_durability; }
	
};