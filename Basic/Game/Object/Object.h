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
	DirectX::SimpleMath::Vector3 m_followPos;	//基本はposと同じ：追従する物がある場合の位置

	DirectX::SimpleMath::Vector3 m_velocity;	//移動用方向ベクトル

	int m_durability;							//耐久力:(HP)

	float m_weight;								//重量



public:
	Object();
	~Object();

public:
	void Move();								//移動

	DirectX::SimpleMath::Vector3 GetFollowPosition() { return m_followPos; }

	float GetWeight() { return m_weight; }

	// 移動ベクトルのゲッターセッター
	void SetVelocity(DirectX::SimpleMath::Vector3 velocity) { m_velocity = velocity; }
	DirectX::SimpleMath::Vector3 GetVelocity() { return m_velocity;	}
	
};