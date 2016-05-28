/*
 * namespace_composition.cpp
 *
 *  Created on: 2016/05/26
 *      Author: sasaki
 */

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

namespace His_string {
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
}

namespace Her_vector {
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
	// ...
}

namespace My_lib {
	using namespace His_string;
	using namespace Her_vector;
	void my_fct(String& s);
}

void f()
{
	My_lib::String s = "Byron";
	// ...
}

using namespace My_lib;

void g(Vector<String>& vs)
{
	my_fct(vs[5]);
}

int main()
{
	f();
	Vector<String> vs {"this", "is", "a", "some", "meaningless", "string" };
	g(vs);

	fill('x');
}

// defines

#if 0
void My_lib::fill(char c)
{

}
#endif
	// 'void His_string::fill(char)' should have been declared inside 'My_lib'

void His_string::fill(char c)
{
	std::cout << "His_string::fill(" << c << ")\n";
}

void My_lib::my_fct(String& s)
{
	std::cout << "My_lib::my_fct(\"" << s << "\")\n";
}
