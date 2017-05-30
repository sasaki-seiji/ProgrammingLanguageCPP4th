/*
 * my_tuple_util.h
 *
 *  Created on: 2017/05/30
 *      Author: sasaki
 */

#ifndef MY_TUPLE_UTIL_H_
#define MY_TUPLE_UTIL_H_

#include <iostream>

template<typename Head, typename... Tail>
Head& head(my_tuple<Head,Tail...>& t)
{
	return my_get<0>(t);
}
template<typename Head, typename... Tail>
const Head& head(const my_tuple<Head,Tail...>& t)
{
	return my_get<0>(t);
}

template<typename Head, typename... Tail>
my_tuple<Tail...>& tail(my_tuple<Head,Tail...>& t)
{
	return *reinterpret_cast<my_tuple<Tail...>*>(&t);
}
template<typename Head, typename... Tail>
const my_tuple<Tail...>& tail(const my_tuple<Head,Tail...>& t)
{
	return *reinterpret_cast<const my_tuple<Tail...>*>(&t);
}

template<size_t N>
struct print_tuple {
	template<typename... T>
	static typename std::enable_if<N<sizeof...(T)>::type
	print(std::ostream& os, const my_tuple<T...>& t)
	{
		os << ", " << my_get<N>(t);
		print_tuple<N+1>::print(os,t);
	}

	template<typename... T>
	static typename std::enable_if<!(N<sizeof...(T))>::type
	print(std::ostream& os, const my_tuple<T...>& t)
	{
	}
};

inline std::ostream& operator<<(std::ostream& os, const my_tuple<>&)
{
	return os << "{}";
}

template<typename T0, typename... T>
std::ostream& operator<<(std::ostream& os, const my_tuple<T0, T...>& t)
{
	os << '{' << my_get<0>(t);
	print_tuple<1>::print(os,t);
	return os << '}';
}



#endif /* MY_TUPLE_UTIL_H_ */
