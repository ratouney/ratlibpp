//
// Created by ratouney on 14/10/18.
//

#include <Error.hpp>
#include <concept_check.hpp>
#include <iostream>
#include "File.hpp"

Rat::File::File()
	:	_path(std::string())
{
}

Rat::File::File(std::string path)
	:	_path(path)
{
	setPath(path);
}

void Rat::File::setPath(const std::string &given)
{
	_path = given;
}

const std::string &Rat::File::getPath() const
{
	return _path;
}

std::string Rat::File::getLine()
{
	std::string rd;

	if (!_if)
		throw Rat::Error("No valid file to be read from");
	getline(_if, rd);

	return rd;
}

void Rat::File::clear(bool all)
{
	if (all)
		_path.clear();
	_if.close();
	_content.clear();
}

void Rat::File::bufferize()
{
	clear();

	_if = std::ifstream(_path);
	if (!_if)
		throw Rat::Error("No valid file found at given path {" + _path + "}");

	std::string line;
	while (getline(_if, line)) {
		_content.push_back(line);
	}
}

FileContent Rat::File::getContent() const
{
	return _content;
}

std::string Rat::File::operator[](size_t idx)
{
	if (_path.empty())
		throw Rat::Error("No path given");
	if (!_if)
		throw Rat::Error("No file stream opened for path [" + _path + "]");
	if (idx > _content.size())
		throw Rat::Error("Index out of bounds");
	return _content[idx];
}

std::vector<std::string>::iterator Rat::File::begin()
{
	return _content.begin();
}

std::vector<std::string>::iterator Rat::File::end()
{
	return _content.end();
}
