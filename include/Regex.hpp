//
// Created by ratouney on 27/11/18.
//

#ifndef RAT_REGEX_H
#define RAT_REGEX_H

#include <iostream>
#include <regex>
#include <vector>

namespace Rat {
    class Regex {
    public:
        Regex();
        Regex(std::string);
        ~Regex();

        void setPattern(std::string);

        std::string getPattern() const;

        std::vector <std::string> match(std::string);

        std::string replace(std::string, std::string);

        std::smatch raw_match(std::string);

        bool simpleMatch(std::string);

    private:
        std::regex _pat;
        std::smatch _sm;
    };

}

#endif //RAT_REGEX_H
