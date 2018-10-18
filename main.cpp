#include <iostream>
#include <zconf.h>
#include <File.hpp>
#include "Error.hpp"

int main(int argc, char **argv)
{
	try {
		Rat::File f;

		f.setPath("./CMakeFiles");
		f.bufferize();
		
		for (auto &line : f) {
			std::cout << line << std::endl;
		}


	} catch (Rat::Error &e) {
		e.print();
	}

	return 0;
}