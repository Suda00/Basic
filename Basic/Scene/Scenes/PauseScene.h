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

	void Initialize() override;	//初期化
	void Update(float elapsedTime) override;		//更新
	void Render() override;		//描画
	void Finalize() override;	//終了
};

