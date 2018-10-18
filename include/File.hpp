//
// Created by ratouney on 14/10/18.
//

#ifndef RAT_FILE_HPP
#define RAT_FILE_HPP

#include <fstream>
#include <vector>

using FileContent = std::vector<std::string>;

namespace Rat {
	class File {
		public:
		File();
		File(std::string);
		~File() = default;

		void setPath(const std::string &);
		const std::string &getPath() const;

		std::string getLine();
		FileContent getContent() const;


		void bufferize();
		void clear(bool = false);

		std::string operator[](size_t);
		std::vector<std::string>::iterator begin();
		std::vector<std::string>::iterator end();

		private:
		std::string _path;
		std::ifstream _if;
		FileContent _content;
	};
}

#endif //RAT_FILE_HPP
