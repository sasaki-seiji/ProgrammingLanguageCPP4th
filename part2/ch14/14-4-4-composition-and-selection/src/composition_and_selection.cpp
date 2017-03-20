/*
 * composition_and_selection.cpp
 *
 *  Created on: 2016/05/27
 *      Author: sasaki
 */

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

namespace His_lib {
	class String {
		std::string	s;
	public:
		String(const char* p) :s{p}
			{ std::cout << "His_lib::String::String(\"" << p << "\")\n"; }
		std::string& str() { return s; }
		const std::string& str() const { return s; }
	};
	String operator+(const String&, const String&);
	void fill(char);
	// ..
	std::ostream& operator<<(std::ostream& os, const String& s) {
		return os << s.str();
	}

	template<typename T>
	class Vector {
	public:
		Vector() { std::cout << "His_lib::Vector::Vector()\n"; }
	};
}

namespace Her_lib {
	template<typename T>
	class Vector {
		std::vector<T> v;
	public:
		Vector(std::initializer_list<T>list) : v{list}
			{ std::cout << "Her_lib::Vector<T>::Vector<initializer_list>()\n" ;}
		T& operator[](size_t i)
			{ 	std::cout << "Her_lib::Vector<T>::operator[]("<< i << ")\n";
				return v[i];
			}
	};

	class String {
	public:
		String() { std::cout << "Her_lib::String::String()\n"; }
	};
	// ...
}

namespace My_lib {
	using namespace His_lib;
	using namespace Her_lib;

	using His_lib::String;
	using Her_lib::Vector;

	template<typename T>
	class List { };

	using Her_string = Her_lib::String;
	template<typename T>
		using His_vec = His_lib::Vector<T>;
}


int main()
{
	My_lib::String s = "this is a string";

	std::cout << "s: " << s << '\n';

	My_lib::Vector<My_lib::String> v {"this", "is", "a", "string"};
	std::cout << "v[2]: " << v[2] << '\n';

	My_lib::Her_string hs;
	My_lib::His_vec<int> hv;
}


