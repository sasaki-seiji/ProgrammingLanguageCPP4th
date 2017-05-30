/*
 * tuple_util.h
 *
 *  Created on: 2017/05/30
 *      Author: sasaki
 */

#ifndef TUPLE_UTIL_H_
#define TUPLE_UTIL_H_

#include <tuple>
#include <iostream>

template<typename Head, typename... Tail>
Head& head(std::tuple<Head,Tail...>& t)
{
	return std::get<0>(t);
}
template<typename Head, typename... Tail>
const Head& head(const std::tuple<Head,Tail...>& t)
{
	return std::get<0>(t);
}

template<typename Head, typename... Tail>
std::tuple<Tail...>& tail(std::tuple<Head,Tail...>& t)
{
	return *reinterpret_cast<std::tuple<Tail...>*>(&t);
}
template<typename Head, typename... Tail>
const std::tuple<Tail...>& tail(const std::tuple<Head,Tail...>& t)
{
	return *reinterpret_cast<const std::tuple<Tail...>*>(&t);
}

template<size_t N>
struct print_tuple {
	template<typename... T>
	static typename std::enable_if<N<sizeof...(T)>::type
	print(std::ostream& os, const std::tuple<T...>& t)
	{
		os << ", " << std::get<N>(t);
		print_tuple<N+1>::print(os,t);
	}

	template<typename... T>
	static typename std::enable_if<!(N<sizeof...(T))>::type
	print(std::ostream& os, const std::tuple<T...>& t)
	{
	}
};

inline std::ostream& operator<<(std::ostream& os, const std::tuple<>&)
{
	return os << "{}";
}

template<typename T0, typename... T>
std::ostream& operator<<(std::ostream& os, const std::tuple<T0, T...>& t)
{
	os << '{' << std::get<0>(t);
	print_tuple<1>::print(os,t);
	return os << '}';
}

#endif /* TUPLE_UTIL_H_ */
