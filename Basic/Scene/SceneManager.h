#pragma once

#include <memory>
#include <list>
#include <functional>
#include <unordered_map>

class SceneBase;

class SceneManager final
{
private:
	//���O�ϊ�
	//�V�[���̃��j�[�N�|�C���^�[
	using SceneStatePtr	 = std::unique_ptr<SceneBase>;	
	//�V�[���̃X�^�b�N�p���X�g
	using SceneStack	 = std::list<SceneStatePtr>;
	//�X�^�b�N����ꏊ�𑝂₷
	//using SceneLineStack = std::list<SceneStack>;

	using SceneFactory   = std::function<SceneStatePtr()>;
	//�V�[�����Ԃ�ۑ�����}�b�v
	using GameStateFactoryList = std::unordered_map<std::string, SceneFactory>;


private:
	GameStateFactoryList m_stateFactories;	//�V�[���̖��O�ƃ|�C���^�p�ϐ�
	SceneStack			 m_states;			//�V�[���̏�ԊǗ��p�ϐ�
	//SceneLineStack		 m_lineStates;		//�V�[���̏�ԊǗ�
	int					 m_popCount;		//���������X�^�b�N�����邩������ϐ�
	std::string			 m_nextSceneName;	//���̃V�[���̖��O����

private:
	//�����ꂽ�V�[���N���X�����j�[�N�|�C���^�[�ɂ���֐�
	template<typename Scene>
	static SceneStatePtr CreateState();

public:
	SceneManager();
	~SceneManager();

public:
	//�t�@�N�g���[�ɓo�^
	template<typename Scene>
	void RegisterState(const std::string& sceneName);
	//RegisterState
	void SetStartState(const std::string& sceneName);

	void Update(float elapsedTime);
	void Render();

	//�X�^�b�N�������v�������ăV�[�������N�G�X�g
	void RequestState(const std::string& sceneName);
	//���̗v������V�[���̖�������:�O�̃X�e�[�g�͎~�܂�
	void PushState(const std::string& sceneName);
	//���̗v������V�[����������F��O�̃V�[��������
	void LineState(const std::string& sceneName);
	//���݃V�[���������đO�̃V�[����
	void PopState(int count = 1);

private:
	//�V�[���؂�ւ�
	void ChangeState();
};


//�����ꂽ�V�[���N���X�����j�[�N�|�C���^�[�ɂ���֐�
template<typename Scene>
SceneManager::SceneStatePtr SceneManager::CreateState()
{
	return std::make_unique<Scene>();
}


//�t�@�N�g���[�ɓo�^
template<typename Scene>
void SceneManager::RegisterState(const std::string& stateName)
{
	// 1. �ÓI�����o�֐�
	m_stateFactories.insert(std::make_pair(stateName, CreateState<Scene>));

	// 2. �����_��
	//m_stateFactories.insert(std::make_pair(stateName, [](){ return std::make_unique<State>(); }));
}