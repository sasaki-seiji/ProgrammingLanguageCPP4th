/*
 * noexcept_operator.cpp
 *
 *  Created on: 2016/05/18
 *      Author: sasaki
 */

#include <type_traits>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
constexpr bool Is_pod()
{
	return std::is_pod<T>::value;
}

template<typename T>
void my_fct(T& x) noexcept(Is_pod<T>())
{
	T tmp {x};
	cout << "my_fct(): " << tmp << '\n';
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "[ ";
	for (auto& x : v)
		os << x << ", ";
	os << "]";
	return os;
}

template<typename T>
void f(T& x) noexcept(Is_pod<T>())
{
	cout << "f(" << x << ")\n";
}

template<typename T>
void call_f(vector<T>& v) noexcept(noexcept(f(v[0])))
{
	for (auto x : v)
		f(x);
}


int main()
{
	double	x = 12.3;
	vector<int> v {1,2,3};

	my_fct(x);
	my_fct(v);

	call_f(v);
	vector<string> vs {"this", "is", "string", "vector"};
	call_f(vs);
}
