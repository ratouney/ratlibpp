/*
 * Hello there
 */

#include <vector>
#include <algorithm>
#include <array>
#include <functional>
#include "Error.hpp"

#ifndef ENTITY_CONFIG_
	#define ENTITY_CONFIG_

	#define ENTITY_ADD_UNIQUE true
	#define ENTITY_ADD_SORT false
	#define ENTITY_REMOVE_SINGLE true

#endif /* !ENTITY_CONFIG_ */

namespace Rat::Game {
	struct EntityError : public Rat::Error {
		public:
		EntityError(std::string cause, int id = -1, std::string name = "~None") {
			_cause = cause;
			_id = id;
			_name = name;
		}
		~EntityError() {};

		void info() const {
			std::cout << "[\e[31mERROR\e[0m] - " << _cause  << std::endl;
			std::cout << "Id {" << _id << "} | Name {" << _name << "}"  << std::endl;
		}

		private:
			int _id;
			std::string _name;
	};

 	class Entity {
 		public:
 		virtual ~Entity() = default;

 		size_t getId() const {
 			return _id;
 		}

 		std::string getName() const {
 			return _name;
 		}

 		void setName(const std::string &name) {
 			_name = name;
 		}

 		bool operator<(const Entity &other) const {
 			return (_id < other.getId());
 		}

 		bool operator>(const Entity &other) const {
 			return (_id > other.getId());
 		}

		protected:

 		size_t _id;
 		std::string _name;

 	};

	std::ostream &operator<<(std::ostream &os, const Entity &e) {
		os << "[Entity : ";
		os << e.getId();
		os << "]";
		return os;
	}

 	class EntityGroup {
 		public:
 		virtual ~EntityGroup() = default;


 		std::vector<Entity>::iterator begin() {
 			return _v.begin();
 		}

		std::vector<Entity>::iterator end() {
			return _v.end();
		}

 		Entity &getId(size_t given) {
 			for (auto &i : _v) {
 				if (i.getId() == given) {
 					return i;
 				}
 			}
 			throw EntityError("Id not found", (int)given);
 		}

 		void add(const Entity &given, bool uniqueId = ENTITY_ADD_UNIQUE, bool unshuffle = ENTITY_ADD_SORT) {
 			if (uniqueId) {
				for (auto &i : _v) {
					if (given.getId() == i.getId())
						throw EntityError("Unique ID exists", given.getId(), given.getName());
				}
 			}
 			_v.push_back(given);
 			if (unshuffle)
 				sort();
 		}

 		size_t removeById(size_t given, bool single = ENTITY_REMOVE_SINGLE) {
 			size_t success = 0;

 			for (size_t i = 0; i < _v.size(); i++) {
 				if (_v[i].getId() == given) {
 					if (single && success == 1)
 						return success;
 					_v.erase(_v.begin() + i);
 					success++;
 					i--;
 				}
 			}
 			return success;
 		}

 		size_t size() const {
 			return _v.size();
 		}

 		void sort() {
 			std::sort(_v.begin(), _v.end());
 		}

		void reverse();

 		Entity &operator[](size_t idx) {
 			return _v.at(idx);
 		}

 		bool empty() const {
 			return _v.empty();
 		}

 		void clear() {
 			_v.clear();
 		}

 		std::vector<Entity> &expose() {
 			return _v;
 		}

 		protected:
 			std::vector<Entity> _v;
 	};

	std::ostream &operator<<(std::ostream &os, EntityGroup &eg) {
		size_t s = eg.size();
		os << "[EntityGroup|" << s << "e]" << std::endl;
		for (size_t i = 0; i < s; i++) {
			std::cout << "-> " << eg[i] << std::endl;
		}
		return os;
	}
 }