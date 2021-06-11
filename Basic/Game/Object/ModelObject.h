//.h
//実体の行列に必要な値を持つObjectの基底クラス
//【派生先】ゲームに必要な値を持つクラスObjectクラス【又もや基底クラス！？】
//作成者：須田　ヒカル
//作成日：2021/05/26
//更新日：2021/05/26
//
#pragma once

#include <SimpleMath.h>
#include <string>

class ModelObject
{
private:
	DirectX::SimpleMath::Vector3 m_position;			//	位置
	DirectX::SimpleMath::Vector3 m_scale;				//	拡大率
	DirectX::SimpleMath::Quaternion m_quaternion;		//　回転

	std::string m_tag;									//　当たり判定用タグ

public:
	ModelObject(const std::string& tag = "GameObject");
	virtual ~ModelObject() = default;

public:
	//純粋仮想関数
	virtual void Initialize() = 0;	//初期化
	virtual void Update(float elapsedTime) = 0;		//更新
	virtual void Render() = 0;		//描画
	virtual void Finalize() = 0;	//終了


	const std::string& GetTag() const;
	const DirectX::SimpleMath::Vector3& GetPosition() const;
	const DirectX::SimpleMath::Vector3& GetScale() const;
	const DirectX::SimpleMath::Quaternion& GetQuaternion() const;

	void SetTag(const std::string& tag);
	void SetPosition(DirectX::SimpleMath::Vector3& position);
	void SetScale(DirectX::SimpleMath::Vector3& scale);
	void SetQuaternion(DirectX::SimpleMath::Quaternion& quaternion);

};

/* ゲッター関数 */
inline const std::string & ModelObject::GetTag() const
{
	return m_tag;
}

inline const DirectX::SimpleMath::Vector3 & ModelObject::GetPosition() const
{
	return m_position;
}

inline const DirectX::SimpleMath::Vector3 & ModelObject::GetScale() const
{
	return m_scale;
}

inline const DirectX::SimpleMath::Quaternion & ModelObject::GetQuaternion() const
{
	return m_quaternion;
}


/* セッター関数 */
inline void ModelObject::SetTag(const std::string & tag)
{
	m_tag = tag;
}

inline void ModelObject::SetPosition(DirectX::SimpleMath::Vector3 & position)
{
	m_position = position;
}

inline void ModelObject::SetScale(DirectX::SimpleMath::Vector3 & scale)
{
	m_scale = scale;
}

inline void ModelObject::SetQuaternion(DirectX::SimpleMath::Quaternion & quaternion)
{
	m_quaternion = quaternion;
}

