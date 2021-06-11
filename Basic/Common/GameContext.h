#pragma once
/*�n���ꂽ�N���X�̃|�C���^���L�^����N���X*/
//�����:

#include<cassert>
#include<memory>


template<typename Context>
class GameContext final
{
private:
	static Context* s_context;

public:
	//�ÓI�����o�ɓo�^
	static void Register(const std::unique_ptr<Context>& context) {
		s_context = context.get();
	}

	static Context* Get()
	{
		//�G���[�m�F
		assert(s_context && "The context has not been registered.");

		return s_context;
	}
};

template<typename Context>
Context* GameContext<Context>::s_context = nullptr;