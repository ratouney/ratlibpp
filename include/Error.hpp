/*
** EPITECH PROJECT, 2018
** RatLib++
** File description:
** Error
*/

/*
** Use like a regular exception but give a string as argument
**
** > throw Rat::Error("Hello there");
**
*/

#ifndef RATLIBPP_ERROR_
#define RATLIBPP_ERROR_

#include <iostream>
#include <exception>
#include <string>

namespace Rat {
    struct Error : public std::exception {
    public:
        Error(std::string cause, std::string func = "unknown", std::string file = "unknown", size_t line = 0);
        Error() = default;

        const char *what() const throw();
        void info() const;
        void debugInfo() const;

        const std::string &get_func() const;
        const std::string &get_file() const;
        size_t get_line() const;

    protected:
        std::string _cause;
        std::string _func;
        std::string _file;
        size_t _line;
    };
} // namespace Rat

#endif /* !RATLIBPP_ERROR_ */