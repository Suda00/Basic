#pragma once
#include"SceneBase.h"

class PauseScene :
	public SceneBase
{
private:


public:
	PauseScene();

public:
	virtual ~PauseScene();

	void Initialize() override;	//������
	void Update(float elapsedTime) override;		//�X�V
	void Render() override;		//�`��
	void Finalize() override;	//�I��
};

