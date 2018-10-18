//
// Created by ratouney on 04/09/18.
//

#include "Parser.hpp"

Rat::String::Parser::Parser()
	:	_commentSeparator(std::string("#")), _leftTrim(std::regex
	("^\\s[\\s]+")), _trim(std::regex("\\s[\\s]+"))
{
}

Rat::String::Parser::~Parser()
{
}

void Rat::String::Parser::commentSeparator(std::string sep)
{
	_commentSeparator = sep;
}

std::string Rat::String::Parser::purgeComment(std::string input, std::string
*comment)
{
	std::string out;
	size_t pos;

	pos = input.find(_commentSeparator);

	if (pos == std::string::npos) {
		out = input;
	} else {
		out = input.substr(0, pos);
		if (comment) {
			*comment = input.substr(pos + _commentSeparator.size
				());
		}
	}

	return out;
}

std::string Rat::String::Parser::trim(std::string input, bool left, bool right)
{
	std::string out;

	out = input;
	if (left) {
		out = std::regex_replace(out, _leftTrim, "");
	}
	if (right) {
		size_t i = out.size() - 1;
		while (out[i] == ' ' || out[i] == '\t') {
			i--;
		}
		out = out.substr(0, i + 1);
	}
	out = std::regex_replace(out, _trim, " ");
	return out;
}

