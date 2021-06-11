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
			//	インスタンスが作られていなければ、新しいインスタンスを作成する
			s_Instance = std::make_unique<T>();
		}
	
		//	作成されてたインスタンスを返す
		return myInstance;
	};

public:
	Singleton(const Singleton &) = delete;
	Singleton& operator=(const Singleton &) = delete;
	Singleton(Singleton &&) = delete;
	Singleton& operator=(Singleton &&) = delete;
};

