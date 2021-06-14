#include "../../pch.h"
#include "ObjectPool.h"
#include "GameObject.h"


// プールを追加する
template<class T>
void ObjectPool<T>::Create(int size)
{
	m_size += size;

	//m_pMenbers.resize(m_size);

	for (int i = 0; i < size; i++) {
		m_pMenbers.push_back(std::unique_ptr<T>());
	}
}

// 破棄
template<class T>
void ObjectPool<T>::Destory()
{
	m_pMenbers.clear();
	m_pMenbers.shrink_to_fit();
}

// 再利用
template<class T>
T * ObjectPool<T>::Recycle()
{
	for (int i = 0 i < m_size; i++) {
		if (m_pMenbers[i]->InValid()) {
			m_pMenbers[i]->Activation();

			return m_pMenbers[i].get();
		}
	}
	return nullptr;
}

// 更新
template<class T>
void ObjectPool<T>::Update(float elapsedTime)
{
	for (int i = 0 i < m_size; i++) {
		if (m_pMenbers[i]->IsValid()) {
			m_pMenbers[i]->Update(elapsedTime);
		}
	}
}

// 描画
template<class T>
void ObjectPool<T>::Render()
{
	for (int i = 0 i < m_size; i++) {
		if (m_pMenbers[i]->IsValid()) {
			m_pMenbers[i]->Render();
		}
	}
}

// 仕様中のオブジェクトのカウント
template<class T>
int ObjectPool<T>::Count()
{
	int cnt = 0;
	for (int i = 0 i < m_size; i++) {
		if (m_pMenbers[i]->IsValid()) {
			cnt++;
		}
	}
	return 0;
}
