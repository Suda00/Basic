#pragma once
//Sceneの基底クラス

class SceneBase
{
public:
	SceneBase() = default;

public:
	virtual ~SceneBase() = default;

public:
	//純粋仮想関数
	virtual void Initialize() = 0;	//初期化
	virtual void Update(float elapsedTime) = 0;		//更新
	virtual void Render() = 0;		//描画
	virtual void Finalize() = 0;	//終了
};

