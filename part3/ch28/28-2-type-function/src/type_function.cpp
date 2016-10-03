/*
 * type_function.cpp
 *
 *  Created on: 2016/10/03
 *      Author: sasaki
 */

#include <type_traits>
#include <typeinfo>
#include <iostream>
using namespace std;

enum class Axis : char { x, y, z };
enum Flags { off, x=1, y=x<<1, z=x<<2, t=x<<3 };

typename std::underlying_type<Axis>::type v1;
typename std::underlying_type<Flags>::type v2;

template<typename T, int N>
struct Array_type {
	using type = T;
	static const int dim = N;
};

using Array = Array_type<int,3>;

Array::type xx;
constexpr int s = Array::dim;

// 28.3.1.3

template<unsigned N, typename... Cases>
struct select;

template<unsigned N, typename T, typename... Cases>
struct select<N,T,Cases...> : select<N-1,Cases...> {
};

template<typename T, typename... Cases>
struct select<0,T,Cases...> {
	using type = T;
};

template<unsigned N, typename... Cases>
using Select = typename select<N,Cases...>::type;


template<int N>
struct Integer {
	using Error = void;
	//using type = Select<N,Error,signed char,short,Error,int,Error,Error,Error,long>;
	using type = Select<N,Error,signed char,short,Error,int,Error,Error,Error,long long>;
};

typename Integer<4>::type i4 = 8;
typename Integer<1>::type i1 = 9;
typename Integer<8>::type i8 = 10;

int main()
{
	if (is_polymorphic<int>::value) cout << "Big surprise!";

	cout << "typeid(v1).name(): " << typeid(v1).name()
			<< ", sizeof(v1): " << sizeof(v1) <<  '\n';
	cout << "typeid(v2).name(): " << typeid(v2).name()
			<< ", sizeof(v2): " << sizeof(v2) <<'\n';

	cout << "typeid(xx).name(): " << typeid(xx).name()
			<< ", sizeof(xx): " << sizeof(xx) << '\n';
	cout << "s: " << s << '\n';

	cout << "typeid(i4).name(): " << typeid(i4).name()
			<< ", sizeof(i4): " << sizeof(i4) << '\n';
	cout << "typeid(i1).name(): " << typeid(i1).name()
			<< ", sizeof(i1): " << sizeof(i1) << '\n';
	cout << "typeid(i8).name(): " << typeid(i8).name()
			<< ", sizeof(i8): " << sizeof(i8) << '\n';
}


