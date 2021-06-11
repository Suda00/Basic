//.cpp
//ゲーム内に必要な値を持つObjectの基底クラス
//【派生先】Playerなどゲームで実態を持つクラス【描画のその先へ】
//作成者：須田　ヒカル
//作成日：2021/05/26
//更新日：2021/05/27
//
#include "../../pch.h"
#include "Object.h"


Object::Object()
	:ModelObject()
	,m_velocity(0.f, 0.f, 0.f)
	,m_followPos(DirectX::SimpleMath::Vector3::Zero)
{
}


Object::~Object()
{
}

void Object::Move()
{
	DirectX::SimpleMath::Vector3 pos = GetPosition() + m_velocity;
	SetPosition(pos);
}
