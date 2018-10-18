//
// Created by ratouney on 30/08/18.
//

#include <regex>
#include <iostream>
#include "Error.hpp"

#ifndef SAMPLE_REGEX_HPP
#define SAMPLE_REGEX_HPP

namespace Rat {
	namespace Regex {
		enum Type {
			REGEX_MATCH,
			REGEX_REPLACE,
			MISSING
		};

		class Pattern {
			public:
			Pattern();
			Pattern(std::string);
			~Pattern();

			void pattern(std::string);
			std::string getPattern() const;

			std::vector<std::string> match(std::string);
			std::string replace(std::string, std::string);

			std::smatch raw_match(std::string);
			bool simpleMatch(std::string);

			private:
			std::regex _pat;
			std::smatch _sm;
		};

		struct Error : public Rat::Error {
			Error(const std::string &cause, const std::string &input =
			"", Type
			type = MISSING, Pattern *ptr = nullptr) {
				_cause = cause;
				_input = input;
				_type = type;
				_ptr = ptr;
			}

			void info() const {
				std::cout << "Tried running" << std::endl;
				std::cout << "-> " << _input << std::endl;
				std::cout << "Type : ";
				switch(_type) {
				case Rat::Regex::Type::REGEX_MATCH:
					std::cout << "RegexMatch";
					break;
				case Rat::Regex::Type::REGEX_REPLACE:
					std::cout << "RegexReplace";
					break;
				case Rat::Regex::Type::MISSING:
					std::cout << "Missing";
					break;
				default:
					std::cout << "Unknown";
					break;
				}
				std::cout << std::endl;
			}

			private:
			std::string _input;
			Rat::Regex::Type _type;
			Pattern *_ptr;
		};
	}


}

#endif //SAMPLE_REGEX_HPP
