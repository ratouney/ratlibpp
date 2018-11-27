/*
 *
 * General Kenobi welcomes you
 *
 */

#include "Error.hpp"

Rat::Error::Error(std::string cause, std::string func, std::string file, size_t line) {
    _cause = cause;
    _func = func;
    _file = file;
    _line = line;
}

const char *Rat::Error::what() const throw() {
    return _cause.c_str();
}

void Rat::Error::info() const {
    std::cout << _cause << std::endl;
#ifdef DEBUG
    debugInfo();
#endif
}

void Rat::Error::debugInfo() const {
    std::cout << "Called by " << _func << " (in " << _file << ":" << _line << ")" << std::endl;
}

const std::string &Rat::Error::get_func() const {
    return _func;
}

const std::string &Rat::Error::get_file() const {
    return _file;
}

size_t Rat::Error::get_line() const {
    return _line;
}
