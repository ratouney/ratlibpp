#include <iostream>
#include <zconf.h>
#include <File.hpp>
#include "Error.hpp"
#include "Regex.hpp"

int main(int argc, char **argv)
{
	try {
		Rat::File f;

		f.bufferize();
		
		for (auto &line : f) {
			std::cout << line << std::endl;
		}


	} catch (Rat::Error &e) {
		e.info();
	}

	return 0;
}