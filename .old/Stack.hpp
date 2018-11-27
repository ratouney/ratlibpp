/*
 *  Hello there
 */

#include <vector>
#include <limits>
#include "Error.hpp"

namespace Rat::Data {
	struct Error : public Rat::Error {
		Error(std::string cause) {
			_cause = cause;
		}

		void info() const {
			std::cout << _cause << std::endl;
		}
	};

 	template <typename T>
 	class Stack {
 		public:
 			Stack() {};
 			~Stack() {};

 			void push(T val)
			{
				_sta.push_back(val);
			}

			T pop()
			{
 				if (_sta.size() == 0)
					throw Rat::Data::Error("Cannot pop an empty stack");

 				T temp;

 				temp = _sta.back();
 				_sta.pop_back();

 				return temp;
 			}

 			bool assert(T given, bool crash = true) const
			{
				if (_sta.size() == 0)
					throw Rat::Data::Error("Cannot assert on empty stack");

				if (crash) {
					if (_sta.back() != given)
						throw Rat::Data::Error("No match on assert");
				}

				return _sta.back() == given;
			}

 			void clear()
			{
				_sta.clear();
			}

 			void dup()
			{
				if (_sta.size() == 0)
					throw Rat::Data::Error("Cannot dup an empty stack");
				T temp;

				temp = _sta.back();
				push(temp);
			}

 			void swap()
			{
				if (_sta.size() <= 1)
					throw Rat::Data::Error("Swap requires 2 values in stack");
 				T one;
 				T alpha;

 				one = pop();
 				alpha = pop();
 				push(one);
 				push(alpha);
 			}

 			void dump(int max = -1)
			{
				int s = _sta.size() - 1;
				size_t i = 0;

				while (s >= 0)
				{
					std::cout << i << "|" << _sta[s] <<
						std::endl;
					s--;
					if (max != -1) {
						if (i >= max)
							break;
						i++;
					}
				}
 			}

 			size_t size() const
			{
				return _sta.size();
			}

 			T operator[](size_t idx)
			{
				if (idx > _sta.size())
					throw Rat::Data::Error("Out of bounds");
 				return _sta[idx];
 			}

 		private:
 			std::vector<T> _sta;


 	};
 }