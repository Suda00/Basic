#pragma once
#include <vector>

// ※注：GameObjectを継承したクラスでないとエラーがおきる
template <class T>
class ObjectPool
{
private:
	// pool配列
	std::vector<std::unique_ptr<T>> m_pMenbers;
	int m_size;

public:
	ObjectPool() {};
	virtual ~ObjectPool() {};

	void Create(int size);

	void Destory();
	
	virtual T* Recycle();

	virtual void Update(float elapsedTime);

	virtual void Render();

	int Count();
};

