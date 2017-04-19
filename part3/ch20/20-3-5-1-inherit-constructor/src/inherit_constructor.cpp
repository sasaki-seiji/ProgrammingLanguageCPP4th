/*
 * inherit_constructor.cpp
 *
 *  Created on: 2016/08/23
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
#include <string>

template<typename T>
struct Vector : std::vector<T> {
	using size_type = typename std::vector<T>::size_type;
	T& operator[](size_type i) { return this->at(i); }
	const T& operator[](size_type i) const { return this->at(i); }
};

template<typename T>
struct Vector2 : std::vector<T> {
	using size_type = typename std::vector<T>::size_type;
	using std::vector<T>::vector;
	T& operator[](size_type i) { return this->at(i); }
	const T& operator[](size_type i) const { return this->at(i); }
};

struct B1 {
	B1(int) { }
};

struct D1 : B1 {
	using B1::B1;
	std::string s;
	int x;
};

struct D2 : B1 {
	using B1::B1;
	std::string s;
	int x {0};
};

void test()
{
	std::cout << "-- test() --\n";

	D1 d {6};
	//D1 e;
		// error: use of deleted function 'D1::D1()'

	std::cout << "d.s = \"" << d.s << "\"\n";
	std::cout << "d.x = " << d.x << '\n';

	D2 d2 {6};
	std::cout << "d2.s = \"" << d2.s << "\"\n";
	std::cout << "d2.x = " << d2.x << '\n';

}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& v2)
{
	os << "[ ";
	for (auto x : v2)
		os << x << ' ';
	os << "]";
	return os;
}

int main()
{
	//Vector<int> v { 1, 2, 3, 5, 8 };
		// error: no matching function for call to 'Vector<int>::Vector(<brace-enclosed initializer list>)'

	Vector2<int> v2 { 1, 2, 3, 5, 8 };
	std::cout << "v2 = " << v2 << '\n';

	v2[3] = 100;
	std::cout << "v2[3]=100; v2 = " << v2 << '\n';

	try {
		v2[5] = 10;
		std::cout << "done v2[5] = 10\n";
	}
	catch (std::exception& e) {
		std::cout << "caught: " << e.what() << '\n';
	}

	test();
}
