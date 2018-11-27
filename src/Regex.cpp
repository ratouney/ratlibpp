//
// Created by ratouney on 27/11/18.
//

#include "Regex.hpp"

Rat::Regex::Regex()
{
}

Rat::Regex::Regex(std::string pattern)
        :	_pat(std::regex(pattern))
{
}

Rat::Regex::~Regex()
{
}

void Rat::Regex::setPattern(std::string pattern)
{
    _pat = std::regex(pattern);
}

std::vector<std::string> Rat::Regex::match(std::string input)
{
    std::vector<std::string> matches;

    if (std::regex_match(input, _sm, _pat)) {
        for (size_t i = 0; i < _sm.size(); i++) {
            matches.push_back(_sm[i].str());
        }
    }
    return matches;
}

std::string Rat::Regex::replace(std::string input, std::string rep)
{
    std::string out;

    out = std::regex_replace(input, _pat, rep);

    return out;
}

std::smatch Rat::Regex::raw_match(std::string input)
{
    std::regex_match(input, _sm, _pat);

    return _sm;
}

bool Rat::Regex::simpleMatch(std::string input)
{
    return std::regex_match(input, _sm, _pat);
}

