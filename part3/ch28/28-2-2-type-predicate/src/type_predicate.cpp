/*
 * type_predicate.cpp
 *
 *  Created on: 2016/10/05
 *      Author: sasaki
 */

#include "copy.h"
#include "do_something.h"
#include "objholder.h"

#include <string>
#include <array>
#include <iostream>
using namespace std;


template<typename T>
constexpr bool Is_big()
{
	return 100<sizeof(T);
}

template<typename T>
using Obj_holder2 = Conditional<(Is_big<T>()), On_heap<T>, Scoped<T>>;

template<typename T>
void test_is_big()
{
	Obj_holder2<T> x;

	cout << "test_is_big() - typeid(x).name(): " << typeid(x).name()
			<< ", sizeof(T): " << sizeof(T) << endl;
}

// add main
int main()
{
	int is[] = { 1, 2, 3, 4 };
	int id[4];
	string ss[] = { "this", "is", "a", "string", "array" };
	string sd[5];

	::copy(id,is,4);	// not use std::copy()
	::copy(sd,ss,5);

	::copy2(id,is,4);
	::copy2(sd,ss,5);

	do_something<int>();
	do_something<string>();

	do_something2<int>();
	do_something2<string>();

	test_is_big<int>();
	test_is_big<array<int,100>>();
}
