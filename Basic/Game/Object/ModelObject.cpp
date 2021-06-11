//.cpp
//モデル描画に必要な値を持つObjectの基底クラス
//【派生先】ゲームに必要な値を持つクラスObjectクラス【又もや基底クラス！？】
//作成者：須田　ヒカル
//作成日：2021/05/26
//更新日：2021/05/26
//
#include "../../pch.h"
#include "ModelObject.h"


ModelObject::ModelObject(const std::string& tag)
	: m_tag(tag)
	, m_position(0.0f, 0.0f, 0.0f)
	, m_quaternion(0.0f, 0.0f, 0.0f,0.f)
	, m_scale(1.0f, 1.0f, 1.0f)
{
}


