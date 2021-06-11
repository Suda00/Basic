#pragma once
//Scene�̊��N���X

class SceneBase
{
public:
	SceneBase() = default;

public:
	virtual ~SceneBase() = default;

public:
	//�������z�֐�
	virtual void Initialize() = 0;	//������
	virtual void Update(float elapsedTime) = 0;		//�X�V
	virtual void Render() = 0;		//�`��
	virtual void Finalize() = 0;	//�I��
};

