#pragma once
#include "SceneBase.h"

class TitleScene :
	public SceneBase
{
private:


public:
	TitleScene();

public:
	virtual ~TitleScene();

	void Initialize() override;	//������
	void Update(float elapsedTime) override;		//�X�V
	void Render() override;		//�`��
	void Finalize() override;	//�I��
};

