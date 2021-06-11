#pragma once
/*渡されたクラスのポインタを記録するクラス*/
//制作者:

#include<cassert>
#include<memory>


template<typename Context>
class GameContext final
{
private:
	static Context* s_context;

public:
	//静的メンバに登録
	static void Register(const std::unique_ptr<Context>& context) {
		s_context = context.get();
	}

	static Context* Get()
	{
		//エラー確認
		assert(s_context && "The context has not been registered.");

		return s_context;
	}
};

template<typename Context>
Context* GameContext<Context>::s_context = nullptr;