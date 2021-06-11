#include "../pch.h"
#include "SceneManager.h"

#include <cassert>

#include"Scenes\SceneBase.h"
#include <algorithm>
#include "../Common/Utilities.h"


SceneManager::SceneManager()
	: m_stateFactories()
	, m_states()
	, m_popCount(0)
	, m_nextSceneName()
{
}


SceneManager::~SceneManager()
{
}

//初期シーン設定
void SceneManager::SetStartState(const std::string & sceneName)
{
	RequestState(sceneName);
}

void SceneManager::Update(float elapsedTime)
{

	//スタックを消す要請が来たら
	if (m_popCount > 0) {
		//詰まれたスタックを消す
		for (int i = 0; i < m_popCount; i++) {
			m_states.back()->Finalize();
			m_states.pop_back();
		}
		m_popCount = 0;
	}

	//次のシーンが設定されていたら
	if (!m_nextSceneName.empty()) {
		ChangeState();
	}

	//エラーの確認
	assert(m_states.size() > 0 && "There is no active");
	m_states.back()->Update(elapsedTime);


	//並列処理を仕様とした名残り
	//for (const SceneStack& stackLine : m_lineStates) {
	//	stackLine.back()->Update();
	//}
}

void SceneManager::Render()
{
	//エラーの確認
	assert(m_states.size() > 0 && "There is no active state.");

	for (const SceneStatePtr& state : m_states) {
		state->Render();
	}

}

//スタックを消す要請をしてシーンをリクエスト
void SceneManager::RequestState(const std::string & sceneName)
{
	//エラーの確認
	assert(m_stateFactories.count(sceneName) == 1 && "A GameState with this name is not registered.");

	//削除するスタックのカウント
	m_popCount = m_states.size();
	m_nextSceneName = sceneName;
}

//次の要請するシーンの名を入れる
void SceneManager::PushState(const std::string & sceneName)
{
	m_nextSceneName = sceneName;

}

//現在シーンをけして前のシーンへ
void SceneManager::PopState(int count)
{
	//エラーの確認
	assert(count > 0 && "Count is invalid.");

	if (!m_nextSceneName.empty()) {
		m_nextSceneName.clear();
		count--;
	}

	//残っているスタックの計算
	m_popCount = Clamp<int>(m_popCount + count, 0, m_states.size() - 1);
}

//シーン切り替え
void SceneManager::ChangeState()
{
	m_states.push_back(m_stateFactories[m_nextSceneName]());
	m_states.back()->Initialize();

	//次のシーンを空にする
	m_nextSceneName.clear();
}
