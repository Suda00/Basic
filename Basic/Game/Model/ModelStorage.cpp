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

//�C���X�^���X�̎擾
ModelStorage * ModelStorage::GetInstance()
{
	if (myInstance == nullptr)
	{
		//	�C���X�^���X������Ă��Ȃ���΁A�V�����C���X�^���X���쐬����
		myInstance = new ModelStorage();
	}

	//	�쐬����Ă��C���X�^���X��Ԃ�
	return myInstance;
}

//	���̊֐����Ă񂾌�A������xGetInstance�֐������s����΁A
//�@�f�[�^�̍�蒼���i���Z�b�g�j���\
void ModelStorage::ReleaseInstance()
{
	if (myInstance != nullptr)
	{
		//	�C���X�^���X���쐬����Ă���΁A�폜���s��
		delete myInstance;
		myInstance = nullptr;
	}
}


//���f���̒ǉ�
void ModelStorage::AddModel(std::string name, wchar_t fileName)
{
	//�f�o�C�X�̎擾
	ID3D11Device*          device = GameContext<DX::DeviceResources>::Get()->GetD3DDevice;

	// �z��o�^
	m_pModel.insert(std::make_pair(name, std::make_unique<Model>()));


	// �G�t�F�N�g�t�@�N�g���̍쐬
	EffectFactory fx(device);
	// �e�N�X�`���̓ǂݍ��݃p�X�w��
	fx.SetDirectory(L"Resources/Models");

	// �t�@�C�����w�肵�ă��f���f�[�^�ǂݍ���
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


