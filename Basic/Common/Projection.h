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
	//�Q�b�^�[�E�Z�b�^�[
	const DirectX::SimpleMath::Matrix& GetMatrix() const;

	void SetPerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane);


};

inline const DirectX::SimpleMath::Matrix& Projection::GetMatrix() const
{
	return m_matrix;
}

/*
//�����@�Ffov
//�����@�FaspectRatio
//�����@�FnearPlane
//�����@�FfarPlane
*/
inline void Projection::SetPerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	m_matrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(fov, aspectRatio, nearPlane, farPlane);
}
