#pragma once

#include <memory>
#include <list>
#include <functional>
#include <unordered_map>

class SceneBase;

class SceneManager final
{
private:
	//名前変換
	//シーンのユニークポインター
	using SceneStatePtr	 = std::unique_ptr<SceneBase>;	
	//シーンのスタック用リスト
	using SceneStack	 = std::list<SceneStatePtr>;
	//スタックする場所を増やす
	//using SceneLineStack = std::list<SceneStack>;

	using SceneFactory   = std::function<SceneStatePtr()>;
	//シーン事態を保存するマップ
	using GameStateFactoryList = std::unordered_map<std::string, SceneFactory>;


private:
	GameStateFactoryList m_stateFactories;	//シーンの名前とポインタ用変数
	SceneStack			 m_states;			//シーンの状態管理用変数
	//SceneLineStack		 m_lineStates;		//シーンの状態管理
	int					 m_popCount;		//いくつ消すスタックがあるか数える変数
	std::string			 m_nextSceneName;	//次のシーンの名前入れ

private:
	//入れられたシーンクラスをユニークポインターにする関数
	template<typename Scene>
	static SceneStatePtr CreateState();

public:
	SceneManager();
	~SceneManager();

public:
	//ファクトリーに登録
	template<typename Scene>
	void RegisterState(const std::string& sceneName);
	//RegisterState
	void SetStartState(const std::string& sceneName);

	void Update(float elapsedTime);
	void Render();

	//スタックを消す要請をしてシーンをリクエスト
	void RequestState(const std::string& sceneName);
	//次の要請するシーンの名を入れる:前のステートは止まる
	void PushState(const std::string& sceneName);
	//次の要請するシーン名を入れる：一つ前のシーンも動く
	void LineState(const std::string& sceneName);
	//現在シーンをけして前のシーンへ
	void PopState(int count = 1);

private:
	//シーン切り替え
	void ChangeState();
};


//入れられたシーンクラスをユニークポインターにする関数
template<typename Scene>
SceneManager::SceneStatePtr SceneManager::CreateState()
{
	return std::make_unique<Scene>();
}


//ファクトリーに登録
template<typename Scene>
void SceneManager::RegisterState(const std::string& stateName)
{
	// 1. 静的メンバ関数
	m_stateFactories.insert(std::make_pair(stateName, CreateState<Scene>));

	// 2. ラムダ式
	//m_stateFactories.insert(std::make_pair(stateName, [](){ return std::make_unique<State>(); }));
}