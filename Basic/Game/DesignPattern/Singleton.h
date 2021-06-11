#pragma once
#include <memory>

template<class T>
class Singleton
{
private:
	static std::unique_ptr<T> s_Instance;

private:
	static T* GetInstance() {	
		if (s_Instance == nullptr)
		{
			//	�C���X�^���X������Ă��Ȃ���΁A�V�����C���X�^���X���쐬����
			s_Instance = std::make_unique<T>();
		}
	
		//	�쐬����Ă��C���X�^���X��Ԃ�
		return myInstance;
	};

public:
	Singleton(const Singleton &) = delete;
	Singleton& operator=(const Singleton &) = delete;
	Singleton(Singleton &&) = delete;
	Singleton& operator=(Singleton &&) = delete;
};

