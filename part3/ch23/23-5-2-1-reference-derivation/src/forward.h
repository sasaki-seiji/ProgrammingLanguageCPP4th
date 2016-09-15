/*
 * forward.cpp
 *
 *  Created on: 2016/09/15
 *      Author: sasaki
 */


#include <type_traits>
#include <memory>
#include <iostream>
using namespace std;


template<typename T>
T&& my_forward(typename remove_reference<T>::type& t)
{
	cout << "my_forward(typename remove_reference<"
			<< typeid(T).name() << ">::type&)\n";
	return static_cast<T&&>(t);
}

template<typename T>
T&& my_forward(typename remove_reference<T>::type&& t)
{
	cout << "my_forward(typename remove_reference<"
			<< typeid(T).name() << ">::type&&)\n";
	return static_cast<T&&>(t);
}

template<typename TT, typename A>
unique_ptr<TT> make_unique(int i, A&& a)
{
	return unique_ptr<TT>{new TT{i, my_forward<A>(a)}};
}
