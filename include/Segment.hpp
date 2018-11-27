/*
** EPITECH PROJECT, 2018
** Ratlib++
** File description:
** Segment
*/

#ifndef RATLIB_SEGMENT_HPP_
#define RATLIB_SEGMENT_HPP_

#include <utility>
#include <string>
#include <future>

#include "Monitor.hpp"
#include "Error.hpp"

namespace Rat {
    template<typename R>
    class Segment {
    public:
        Segment(std::string name)
                : _name(std::move(name)) {

        };

        ~Segment()
        {
            delete(_promise);
            delete(_thread);
            delete(_monitor);
        };

        template<class Function, class... Args>
        void run(Function &&func, Args &&... args) {
            _promise = new std::promise<R>();
            _future = _promise->get_future();

            _monitor = Monitor<R>(_promise);

            _thread = new std::thread(func, _monitor, args...);
        }

        R await() {
            if (!_thread)
                throw Error("No thread is not running");

            _thread->join();

            return _future.get();
        }

        bool isRunning()
        {
            auto status = _future.wait_for(std::chrono::seconds(0));

            return !(status == std::future_status::ready);
        }

        std::promise<R> *getPromise() const {
            return _promise;
        }

        const std::future<R> &getFuture() const {
            return _future;
        }

        std::thread *getThread() const {
            return _thread;
        }

        const std::string &getName() const {
            return _name;
        }

        Monitor<R> *getMonitor() const {
            return _monitor;
        }

    private:
        std::promise<R> *_promise;
        std::future<R> _future;
        std::thread *_thread;
        std::string _name;

        Monitor<R> *_monitor;
    };
}

#endif /* !RATLIB_SEGMENT_HPP_ */
