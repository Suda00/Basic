//.h
//移動に関する計算を行うクラス
//作成者：須田　ヒカル
//作成日：2021/06/01
//更新日：2021/06/04
//
#pragma once
#include"../Object/Object.h"

class Move
{
private:
	static const float GRAVITY;

	const float MAX_SPEED;		//最大速度

private:
	Object *m_owner;		// 移動に必要な変数の持ち主
	Object *m_parent;		// 親子関係にあるオブジェクト

	DirectX::SimpleMath::Vector3 m_velocity;	//移動用方向ベクトル

	DirectX::SimpleMath::Vector3 m_acceleration;		//加速力

	float m_targetAngle;		//回転角

public:
	Move(float maxSpeed, Object* owner, Object* parent = nullptr);
	~Move();

	void Initialize();
	void Update(float elapsedTime);

	void AddForce(float force, DirectX::SimpleMath::Quaternion angle);
	void Transform(DirectX::SimpleMath::Vector3 velocity);

	void Moving();
	void ReleaseParent();
	void SetParent(Object * parent);
};

//親の設定
inline void Move::SetParent(Object * parent)
{
	m_parent = parent;
}
