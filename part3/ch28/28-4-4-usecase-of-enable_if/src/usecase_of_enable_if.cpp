/*
 * usecase_of_enable_if.cpp
 *
 *  Created on: 2016/10/08
 *      Author: sasaki
 */

#include <type_traits>
#include <iostream>

struct substitution_failure { };

template<typename T>
struct substitution_succeeded : std::true_type
{ };

template<>
struct substitution_succeeded<substitution_failure> : std::false_type
{ };

int f(int i);

template<typename T>
struct get_f_result {
private:
	template<typename X>
		static auto check(X const& x) -> decltype(f(x));
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_f : substitution_succeeded<typename get_f_result<T>::type>
{ };

template<typename T>
constexpr bool Has_f()
{
	return has_f<T>::value;
}

template<bool B, typename T=void>
using Enable_if = typename std::enable_if<B,T>::type;


template<typename T>
class X {
public:
	template<typename U=T>
	Enable_if<Has_f<U>()> use_f(const U& t)
	{
		f(t);
	}
};

int f(int i)
{
	std::cout << "f(int)\n";
	return i;
}

// add main

int main()
{
	X<int> xi;
	std::cout << Has_f<int>() << '\n';
	xi.use_f(10);

	X<std::string> xs;
	//xs.use_f("string");
		// error: no matching function for call to 'X<std::__cxx11::basic_string<char> >::use_f(const char [7])'
	std::cout << Has_f<std::string>() << '\n';
}
