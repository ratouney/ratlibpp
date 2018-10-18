/*
 * Hello there
 */

#include <vector>
#include <fstream>
#include "Error.hpp"

 namespace Rat::System {
 	using FileContent = std::vector<std::string>;

 	struct Error : public Rat::Error {
 		Error(std::string cause) {
 			_cause = cause;
 		}

 		void info() const {
			std::cout << _cause << std::endl;
 		}
 	};

 	class File {
		public:
 		File();
 		~File();

 		void read(std::string);
 		std::vector<std::string> getContent() const;

 		private:
 		std::string _path;
 		std::vector<std::string> _content;

 	};
 }