#pragma once
#include "SceneBase.h"

#include"SimpleMath.h"

class DebugCamera;
class GridFloor;


class GameScene :
	public SceneBase
{
private:
	std::unique_ptr<DebugCamera> m_debugCamera;

	std::unique_ptr<GridFloor>   m_gridFloor;


public:
	GameScene();
	virtual ~GameScene();

	void Initialize() override;	//初期化
	void Update(float elapsedTime) override;		//更新
	void Render() override;		//描画
	void Finalize() override;	//終了


};

