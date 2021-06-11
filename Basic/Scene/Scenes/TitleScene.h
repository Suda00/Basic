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

	void Initialize() override;	//‰Šú‰»
	void Update(float elapsedTime) override;		//XV
	void Render() override;		//•`‰æ
	void Finalize() override;	//I—¹
};

