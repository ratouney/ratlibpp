/*
** EPITECH PROJECT, 2018
** Ratlib++
** File description:
** Monitor
*/

#ifndef RATLIB_MONITOR_HPP_
#define RATLIB_MONITOR_HPP_

#include <utility>
#include <future>

namespace Rat {
    template<typename R>
    class Monitor {
    public:
        Monitor(std::promise<R> *prom)
                : _promise(prom), _shouldBeRunning(true) {

        }

        ~Monitor() = default;

        void setReturn(R rt) {
            if (_promise)
                _promise->set_value_at_thread_exit(rt);
        }

        R getReturn() {
            if (_promise)
                _promise->get_future().get();
        }

        void requestTerminate() {
            _shouldBeRunning = false;
        }

        void shouldBeRunning() {
            return _shouldBeRunning;
        }

    private:
        std::promise<R> *_promise;
        bool _shouldBeRunning;
    };
}

#endif RATLIB_MONITOR_HPP_
