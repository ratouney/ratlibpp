/*
** EPITECH PROJECT, 2018
** client
** File description:
** Segment
*/

#include <iostream>
#include <thread>
#include <future>
#include <exception>
#include "ReturnBlock.hpp"
#include "Error.hpp"

#ifndef SEGMENT_HPP_
	#define SEGMENT_HPP_

namespace Rat::Thread {
	template<typename R>
	class Segment {
		public:
		Segment(const std::string &name = "") : _name(name), _promise(nullptr), _thread(nullptr)
		{
		}

		~Segment()
		{
			if (_thread)
				delete (_thread);
			if (_promise)
				delete (_promise);
		};

		template<class Function, class... Args>
		void run(Function &&func, Args &&... args)
		{
			_promise = new std::promise<R>();
			_future = _promise->get_future();
			// auto = ReturnBlock<R>
			_rtb = new ReturnBlock<R>(_promise);
			_thread = new std::thread(func, _rtb, args...);
		};

		R await()
		{
			if (_thread == nullptr)
				throw Error("Thread is not initialized");

			_thread->join();
			return _future.get();
		}

		void stop()
		{
			_thread->detach();
			delete(_thread);
		}

		std::thread *getThread() const
		{
			return _thread;
		}

		std::string getName() const
		{
			return _name;
		}

		private:
		std::promise<R> *_promise;
		std::future<R> _future;
		std::string _name;
		std::thread *_thread;
		ReturnBlock<R> *_rtb;
	};
}

#endif /* !SEGMENT_HPP_ */
