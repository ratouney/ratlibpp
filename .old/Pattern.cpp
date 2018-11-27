//
// Created by ratouney on 30/08/18.
//

#include "Pattern.hpp"

Rat::Regex::Pattern::Pattern()
{
}

Rat::Regex::Pattern::Pattern(std::string pattern)
	:	_pat(std::regex(pattern))
{
}

Rat::Regex::Pattern::~Pattern()
{
}

void Rat::Regex::Pattern::pattern(std::string pattern)
{
	_pat = std::regex(pattern);
}

std::vector<std::string> Rat::Regex::Pattern::match(std::string input)
{
	std::vector<std::string> matches;

	if (std::regex_match(input, _sm, _pat)) {
		for (size_t i = 0; i < _sm.size(); i++) {
			matches.push_back(_sm[i].str());
		}
	}
	return matches;
}

std::string Rat::Regex::Pattern::replace(std::string input, std::string rep)
{
	std::string out;

	out = std::regex_replace(input, _pat, rep);

	return out;
}

std::smatch Rat::Regex::Pattern::raw_match(std::string input)
{
	std::regex_match(input, _sm, _pat);

	return _sm;
}

bool Rat::Regex::Pattern::simpleMatch(std::string input)
{
	return std::regex_match(input, _sm, _pat);
}

