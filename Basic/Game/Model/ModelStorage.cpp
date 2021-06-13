#include "../../pch.h"
#include "ModelStorage.h"

#include <CommonStates.h>
#include <Effects.h>

#include "../../Common/GameContext.h"
#include "../../DeviceResources.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;

ModelStorage* ModelStorage::myInstance = nullptr;


ModelStorage::ModelStorage()
{
}


ModelStorage::~ModelStorage()
{
	ReleaseInstance();
}

//インスタンスの取得
ModelStorage * ModelStorage::GetInstance()
{
	if (myInstance == nullptr)
	{
		//	インスタンスが作られていなければ、新しいインスタンスを作成する
		myInstance = new ModelStorage();
	}

	//	作成されてたインスタンスを返す
	return myInstance;
}

//	この関数を呼んだ後、もう一度GetInstance関数を実行すれば、
//　データの作り直し（リセット）が可能
void ModelStorage::ReleaseInstance()
{
	if (myInstance != nullptr)
	{
		//	インスタンスが作成されていれば、削除を行う
		delete myInstance;
		myInstance = nullptr;
	}
}


//モデルの追加
void ModelStorage::AddModel(std::string name, wchar_t fileName)
{
	//デバイスの取得
	ID3D11Device* device = GameContext<DX::DeviceResources>::Get()->GetD3DDevice;

	// 配列登録
	m_pModel.insert(std::make_pair(name, std::make_unique<Model>()));


	// エフェクトファクトリの作成
	EffectFactory fx(device);
	// テクスチャの読み込みパス指定
	fx.SetDirectory(L"Resources/Models");

	// ファイルを指定してモデルデータ読み込み
	m_pModel[name] = DirectX::Model::CreateFromCMO(device, &fileName, fx);
}



void ModelStorage::DrawModel(std::string name,Matrix  world, Matrix view, Matrix projection)
{
	DX::DeviceResources*   deviceResources = GameContext<DX::DeviceResources>::Get();
	ID3D11Device*          device = deviceResources->GetD3DDevice();
	ID3D11DeviceContext*   deviceContext = deviceResources->GetD3DDeviceContext();
	CommonStates*		   states = GameContext<CommonStates>::Get();

	 m_pModel[name].get()->Draw(deviceContext, *states, world, view, projection);
}


