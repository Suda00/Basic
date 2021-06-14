#include "../../pch.h"
#include "FollowCamera.h"

#include "../../Game.h"
#include "../../Common/Utilities.h"



FollowCamera::FollowCamera()
	: m_posFollowSpeed(1.f)
	, m_rotFollowSpeed(1.f)
{
}


FollowCamera::~FollowCamera()
{
}

/*/------------------初期化関数------------------/*/
// 引数1 Object * target : カメラの追従するもの　 
// 引数2 float destance  : カメラ間の距離		  
// 引数3 float eyeHeight : 目線の高さ　 
// 引数4 float rot		 : 水平角度	　
// 引数5 float height	 : 上下角度	  
void FollowCamera::Initialize(Object * target, float distance, float height, DirectX::SimpleMath::Vector3 rotation)
{
	//ニアクリップ(近距離表示可能範囲)
	float nearPlane = 0.01f;
	//ファークリップ(遠距離表示可能範囲)
	float farPlane = 1000.0f;

	// 引数の代入
	m_targetObj = target;						// 追従対象
	m_targetDistance = m_distance = distance;	// カメラ間距離
	m_targetHeight = m_height = height;			// 視線の高さ
	m_targetRotation = m_rotation = rotation;	// カメラの回転角度

	m_up = DirectX::SimpleMath::Vector3(0, 1.0f, 0);


	//ターゲットを設定する
	DirectX::SimpleMath::Vector3 targetPos;

	if (m_targetObj == nullptr) targetPos = DirectX::SimpleMath::Vector3::Zero;
	else targetPos = m_targetObj->GetPosition() + m_up * m_targetHeight;


	// カメラ間の距離
	DirectX::SimpleMath::Vector3 offset = DirectX::SimpleMath::Vector3::Zero;
	offset.x +=  sin(DirectX::XMConvertToRadians(m_targetRotation.y)) * cos(DirectX::XMConvertToRadians(m_targetRotation.x)) * m_targetDistance;
	offset.z += -cos(DirectX::XMConvertToRadians(m_targetRotation.y)) * cos(DirectX::XMConvertToRadians(m_targetRotation.x)) * m_targetDistance;
	offset.y +=  sin(DirectX::XMConvertToRadians(m_targetRotation.x)) * m_targetDistance;

	// カメラ位置の設定
	m_eye = targetPos + offset;



	float aspect = static_cast<float>(Game::SCREEN_W) / static_cast<float>(Game::SCREEN_H);
	float fov = DirectX::XMConvertToRadians(45.0f);

	//ビュー行列初期化
	m_viewMatrix = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye, targetPos, m_up);
	// プロジェクション行列の設定
	m_projectionMatrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(fov, aspect, nearPlane, farPlane);
}

void FollowCamera::Update(float elapsedTime)
{

	// 追従速度
	float rotRate = Clamp(elapsedTime * 100.f / m_rotFollowSpeed, 0.f, 1.0f);
	float posRate = Clamp(elapsedTime * 100.f / m_posFollowSpeed, 0.f, 1.0f);

	// 移動した対象へ追従
	m_targetDistance = Leap(m_targetDistance, m_distance, posRate);
	m_targetRotation = DirectX::SimpleMath::Vector3::Lerp(m_targetRotation, m_rotation, rotRate);
	m_targetHeight = Leap(m_targetHeight, m_height, posRate);

	//ターゲットを設定する
	DirectX::SimpleMath::Vector3 targetPos;

	if (m_targetObj == nullptr) targetPos = DirectX::SimpleMath::Vector3::Zero;
	else targetPos = m_targetObj->GetPosition() + m_up * m_targetHeight;

	// カメラ間の距離
	DirectX::SimpleMath::Vector3 offset = DirectX::SimpleMath::Vector3::Zero;
	offset.x +=  sin(DirectX::XMConvertToRadians(m_targetRotation.y)) * cos(DirectX::XMConvertToRadians(m_targetRotation.x)) * m_targetDistance;
	offset.z += -cos(DirectX::XMConvertToRadians(m_targetRotation.y)) * cos(DirectX::XMConvertToRadians(m_targetRotation.x)) * m_targetDistance;
	offset.y +=  sin(DirectX::XMConvertToRadians(m_targetRotation.x)) * m_targetDistance;

	// カメラ位置の設定
	m_eye = targetPos + offset;


	m_viewMatrix = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye, targetPos, m_up);



}

// カメラ間距離の変更
void FollowCamera::ChengeDistance(float magnification)
{
	m_distance *= 1.f - magnification;
	m_distance = Clamp(m_distance, 0.01f, 1000.0f);
}

void FollowCamera::ChengeRotation()
{
}

/*
//名　　：スクリーン座標をワールド座標に変換する行列を作成する関数
//引数　：int screen_w　		スクリーンの幅
//引数　：int screen_h　		スクリーンの高さ
//返り値：invS * invP * invV	逆座標
*/
DirectX::SimpleMath::Matrix FollowCamera::CreateMatrix_Screen2World(int screen_w, int screen_h)
{
	int screen_x = screen_w;
	int screen_y = screen_h;
	if (Game::GetWindowMode()) {
		screen_x = static_cast<int>(static_cast<float>(screen_x) * Game::GetWindowMagnification().x);
		screen_y = static_cast<int>(static_cast<float>(screen_y) * Game::GetWindowMagnification().y);
	}

	// ビューポートスケーリング行列を作成
	DirectX::SimpleMath::Matrix viewport;
	viewport._11 = screen_x / 2.0f;
	viewport._22 = -screen_y / 2.0f;
	viewport._41 = screen_x / 2.0f;
	viewport._42 = screen_y / 2.0f;

	// 逆行列を作成
	DirectX::SimpleMath::Matrix invS = viewport.Invert();
	DirectX::SimpleMath::Matrix invP = m_projectionMatrix.Invert();
	DirectX::SimpleMath::Matrix invV = m_viewMatrix.Invert();

	// 『ビューポートスケーリング行列の逆行列』 × 『射影行列の逆行列』 × 『ビュー行列の逆行列』
	return invS * invP * invV;
}

