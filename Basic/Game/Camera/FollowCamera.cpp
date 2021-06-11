#include "../../pch.h"
#include "FollowCamera.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;

FollowCamera::FollowCamera()
{
}


FollowCamera::~FollowCamera()
{
}


void FollowCamera::Initialize(float fov, float aspect)
{
	//ニアクリップ(近距離表示可能範囲)
	float nearPlane = 0.01f;
	//ファークリップ(遠距離表示可能範囲)
	float farPlane = 1000.0f;

	//初期値設定
	m_target = DirectX::SimpleMath::Vector3(0.0f, 0.0f, 0.0f);
	m_refTargetPos = m_target;//参照注視点初期化
	m_eye = DirectX::SimpleMath::Vector3(0.0f, 1.0f, 3.0f);
	m_refEyePos = m_eye;//参照視点初期化
	DirectX::SimpleMath::Vector3 up(0, 1.0f, 0);

	//ビュー行列初期化
	m_viewMatrix =
		DirectX::SimpleMath::Matrix::CreateLookAt(
			m_eye,
			m_target,
			up);

	m_projectionMatrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(
		DirectX::XMConvertToRadians(45.0f),
		800 / 600,
		nearPlane,
		farPlane);
	


	m_projectionMatrix = Matrix::CreatePerspectiveFieldOfView(
		fov,
		aspect,
		nearPlane,
		farPlane
	);



}

void FollowCamera::Update()
{
	//追従速度：１倍
	m_eye += (m_refEyePos - m_eye) * 1.0f;
	m_target += (m_refTargetPos - m_target) * 1.f;

	m_viewMatrix = Matrix::CreateLookAt(m_eye, m_target, m_up);

}

/*
//名　　：スクリーン座標をワールド座標に変換する行列を作成する関数
//引数　：int screen_w　		スクリーンの幅
//引数　：int screen_h　		スクリーンの高さ
//返り値：invS * invP * invV	逆座標
*/
Matrix FollowCamera::CreateMatrix_Screen2World(int screen_w, int screen_h)
{
	// ビューポートスケーリング行列を作成
	Matrix viewport;
	viewport._11 = screen_w / 2.0f;
	viewport._22 = -screen_h / 2.0f;
	viewport._41 = screen_w / 2.0f;
	viewport._42 = screen_h / 2.0f;

	// 逆行列を作成
	Matrix invS = viewport.Invert();
	Matrix invP = m_projectionMatrix.Invert();
	Matrix invV = m_viewMatrix.Invert();

	// 『ビューポートスケーリング行列の逆行列』 × 『射影行列の逆行列』 × 『ビュー行列の逆行列』
	return invS * invP * invV;
}

