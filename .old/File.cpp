/*
 * General Kenobi ?
 */

#include "File.hpp"

Rat::System::File::File()
	:   _path("")
{
}

Rat::System::File::~File()
{
}

void Rat::System::File::read(std::string path)
{
	_path = path;

	std::ifstream file(path);

	if (!file)
		throw Rat::System::Error("Could not open file [" + path + "]");

	std::string line;

	while (getline(file, line)) {
		_content.push_back(line);
	}
}

std::vector<std::string> Rat::System::File::getContent() const
{
	return _content;
}
