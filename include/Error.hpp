/*
 *
 * Hello there, welcome to Ratlib
 *
 */

#include <exception>
#include <string>

/*
 * Use like a regular exception but give a string as argument
 *
 * > throw Rat::Error("Hello there");
 *
 */

namespace Rat {
	class Error : public std::exception {
		public:

		// Created from a string that contains the error message
		explicit Error(const std::string &given = "Say what ?");
		~Error() = default;

		// Function called at runtime when an exception is not caught
		const char *what() const noexcept override;

		// Custom function that can be called to retrieve the error in a Try/Catch loop
		void print() const;

		// Return the contained string
		const std::string &getString() const;

		private:
			std::string _msg;
	};
}