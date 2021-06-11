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

	void Initialize() override;	//初期化
	void Update(float elapsedTime) override;		//更新
	void Render() override;		//描画
	void Finalize() override;	//終了
};

