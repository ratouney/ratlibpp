//
// Created by ratouney on 10/08/18.
//

#ifndef CLIENT_ERROR_HPP
#define CLIENT_ERROR_HPP

#include <iostream>
#include <exception>

namespace Rat {
struct Error : public std::exception {
	public:
		explicit Error(std::string);
		Error();

	const char *what() const throw();

	virtual void info() const;

	protected:
		std::string _cause;

};
}


#endif //CLIENT_ERROR_HPP
