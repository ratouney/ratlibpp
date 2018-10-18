//
// Created by ratouney on 10/08/18.
//

#include "Error.hpp"

Rat::Error::Error()
{
	_cause = std::string("Unknown");
}


Rat::Error::Error(std::string cause)
	:	_cause(cause)
{
}

const char *Rat::Error::what() const throw()
{
	return _cause.c_str();
}

void Rat::Error::info() const {
	std::cout << _cause << std::endl;
}