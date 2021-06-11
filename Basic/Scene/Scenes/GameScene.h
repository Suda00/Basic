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

	void Initialize() override;	//������
	void Update(float elapsedTime) override;		//�X�V
	void Render() override;		//�`��
	void Finalize() override;	//�I��


};

