//
// Created by ratouney on 04/09/18.
//

#ifndef TESTER_PARSER_HPP
#define TESTER_PARSER_HPP

#include <string>
#include <regex>

namespace Rat::String {
	class Parser {
		public:
			Parser();
			~Parser();

			void commentSeparator(std::string);
			std::string purgeComment(std::string, std::string * =
				nullptr);


			std::string trim(std::string, bool left = true, bool
				right = true);

		private:
			std::string _commentSeparator;

			std::regex _leftTrim;
			std::regex _trim;

	};
}

#endif //TESTER_PARSER_HPP
