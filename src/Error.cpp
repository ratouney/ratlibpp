/*
 *
 * General Kenobi welcomes you
 *
 */

#include <iostream>
#include "Error.hpp"

Rat::Error::Error(const std::string &given)
	:	_msg(given)
{
}

const char *Rat::Error::what() const noexcept
{
	return _msg.c_str();
}

void Rat::Error::print() const
{
	std::cout << "[\e[31mRat.Error\e[0m : " << _msg << "]" << std::endl;
}

const std::string &Rat::Error::getString() const
{
	return _msg;
}

