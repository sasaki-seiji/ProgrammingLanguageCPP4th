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
			{ std::cout << "His_string::String::String(" << p << ")\n"; }
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
	class Vector { };
}

namespace Her_lib {
	template<typename T>
	class Vector {
		std::vector<T> v;
	public:
		Vector(std::initializer_list<T>list) : v{list}
			{ std::cout << "Her_vector::Vector<T>::Vector<initializer_list>()\n" ;}
		T& operator[](size_t i)
			{ 	std::cout << "Her_vector::Vector<T>::operator[]("<< i << ")\n";
				return v[i];
			}
	};

	class String { };
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

using namespace std;
using namespace My_lib;

int main()
{
	//String s = "this is a string";
		// 'String' is ambiguous '
		// Candidates are:
	 	 // String(const His_lib::String &)
	 	 // String(const char *)
	 	 // String(const His_lib::String &)
	 	 // String(const char *)
	 	 // String()
	 	 // String(const Her_lib::String &)
	My_lib::String s = "this is a string";

	cout << "s: " << s << '\n';

	My_lib::Vector<My_lib::String> v {"this", "is", "a", "string"};
	cout << "v[2]: " << v[2] << '\n';

	Her_string hs;
	His_vec<int> hv;
}


