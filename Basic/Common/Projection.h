#pragma once

#include <SimpleMath.h>

class Projection final 
{
private:
	DirectX::SimpleMath::Matrix m_matrix;

public:
	Projection() = default;

public:
	~Projection() = default;

public:
	//ゲッター・セッター
	const DirectX::SimpleMath::Matrix& GetMatrix() const;

	void SetPerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane);


};

inline const DirectX::SimpleMath::Matrix& Projection::GetMatrix() const
{
	return m_matrix;
}

/*
//引数　：fov
//引数　：aspectRatio
//引数　：nearPlane
//引数　：farPlane
*/
inline void Projection::SetPerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	m_matrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(fov, aspectRatio, nearPlane, farPlane);
}
