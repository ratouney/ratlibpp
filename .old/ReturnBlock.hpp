/*
** EPITECH PROJECT, 2018
** client
** File description:
** ReturnBlock
*/

#include <iostream>
#include <thread>
#include <future>

#ifndef RETURNBLOCK_HPP_
	#define RETURNBLOCK_HPP_

namespace Rat::Thread {
	template<typename R>
	class ReturnBlock {
	    public:
		ReturnBlock(std::promise<R> *prom)
			:	_promise(nullptr),
				_exitReason(std::string("")),
				_exitRequest(false)
		{
			if (prom)
				_promise = prom;
		}
		~ReturnBlock();

		void overwrite(std::promise<R> *given)
		{
			_promise = given;
		}

		std::promise<R> *expose() const
		{
			return _promise;
		}

		void set(R rt)
		{
			if (_promise)
				_promise->set_value_at_thread_exit(rt);
		}

	    private:
		std::promise<R> *_promise;

		std::string _exitReason;
		std::string _exitRequest;
	};
};

#endif /* !RETURNBLOCK_HPP_ */
