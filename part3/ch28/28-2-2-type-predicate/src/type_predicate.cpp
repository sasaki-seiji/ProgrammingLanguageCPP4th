/*
 * type_predicate.cpp
 *
 *  Created on: 2016/10/05
 *      Author: sasaki
 */

#include <type_traits>
#include <cstring>
#include <string>
#include <array>
#include <iostream>
#include <typeinfo>
using namespace std;

#include "objholder.h"

template<typename T>
void copy(T* p, const T* q, int n)
{
	if (is_pod<T>::value) {
		cout << "::copy - is_pod\n";
		memcpy(p,q,n*sizeof(T));
	}
	else {
		cout << "::copy - not is_pod\n";
		for (int i=0; i!=n; ++i)
			p[i] = q[i];
	}
}

template<typename T>
void copy2(T* p, const T* q, int n)
{
	if (is_pod<T>()) {
		cout << "::copy2 - is_pod\n";
		memcpy(p,q,n*sizeof(T));
	}
	else {
		cout << "::copy2 - not is_pod\n";
		for (int i=0; i!=n; ++i)
			p[i] = q[i];
	}
}

template<bool B, typename T, typename F>
using Conditional = typename conditional<B,T,F>::type;

template<typename T>
void do_something()
{
	Conditional<(is_pod<T>()),On_heap<T>,Scoped<T>> x;

	cout << "do_something1 - typeid(x).name(): " << typeid(x).name() << '\n';
}

template<typename T>
constexpr bool Is_pod()
{
	return std::is_pod<T>::value;
}

template<typename T>
void do_something2()
{
	Conditional<Is_pod<T>(),On_heap<T>,Scoped<T>> x;

	cout << "do_something2 - typeid(x).name(): " << typeid(x).name() << '\n';
}

template<typename T>
constexpr bool Is_big()
{
	return 100<sizeof(T);
}

template<typename T>
using Obj_holder2 = Conditional<(Is_big<T>()), On_heap<T>, Scoped<T>>;

template<typename T>
void do_something3()
{
	Obj_holder2<T> x;

	cout << "do_something3 - typeid(x).name(): " << typeid(x).name() << '\n';
}

// add main
int main()
{
	int is[] = { 1, 2, 3, 4 };
	int id[4];
	string ss[] = { "this", "is", "a", "string", "array" };
	string sd[5];

	::copy(id,is,4);
	::copy(sd,ss,5);

	::copy2(id,is,4);
	::copy2(sd,ss,5);

	do_something<int>();
	do_something<string>();

	do_something2<int>();
	do_something2<string>();

	do_something3<int>();
	do_something3<array<string,100>>();
}
