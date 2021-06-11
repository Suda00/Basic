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

	void Initialize() override;	//‰Šú‰»
	void Update(float elapsedTime) override;		//XV
	void Render() override;		//•`‰æ
	void Finalize() override;	//I—¹
};

