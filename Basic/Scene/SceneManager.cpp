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

//�����V�[���ݒ�
void SceneManager::SetStartState(const std::string & sceneName)
{
	RequestState(sceneName);
}

void SceneManager::Update(float elapsedTime)
{

	//�X�^�b�N�������v����������
	if (m_popCount > 0) {
		//�l�܂ꂽ�X�^�b�N������
		for (int i = 0; i < m_popCount; i++) {
			m_states.back()->Finalize();
			m_states.pop_back();
		}
		m_popCount = 0;
	}

	//���̃V�[�����ݒ肳��Ă�����
	if (!m_nextSceneName.empty()) {
		ChangeState();
	}

	//�G���[�̊m�F
	assert(m_states.size() > 0 && "There is no active");
	m_states.back()->Update(elapsedTime);


	//���񏈗����d�l�Ƃ������c��
	//for (const SceneStack& stackLine : m_lineStates) {
	//	stackLine.back()->Update();
	//}
}

void SceneManager::Render()
{
	//�G���[�̊m�F
	assert(m_states.size() > 0 && "There is no active state.");

	for (const SceneStatePtr& state : m_states) {
		state->Render();
	}

}

//�X�^�b�N�������v�������ăV�[�������N�G�X�g
void SceneManager::RequestState(const std::string & sceneName)
{
	//�G���[�̊m�F
	assert(m_stateFactories.count(sceneName) == 1 && "A GameState with this name is not registered.");

	//�폜����X�^�b�N�̃J�E���g
	m_popCount = m_states.size();
	m_nextSceneName = sceneName;
}

//���̗v������V�[���̖�������
void SceneManager::PushState(const std::string & sceneName)
{
	m_nextSceneName = sceneName;

}

//���݃V�[���������đO�̃V�[����
void SceneManager::PopState(int count)
{
	//�G���[�̊m�F
	assert(count > 0 && "Count is invalid.");

	if (!m_nextSceneName.empty()) {
		m_nextSceneName.clear();
		count--;
	}

	//�c���Ă���X�^�b�N�̌v�Z
	m_popCount = Clamp<int>(m_popCount + count, 0, m_states.size() - 1);
}

//�V�[���؂�ւ�
void SceneManager::ChangeState()
{
	m_states.push_back(m_stateFactories[m_nextSceneName]());
	m_states.back()->Initialize();

	//���̃V�[������ɂ���
	m_nextSceneName.clear();
}
