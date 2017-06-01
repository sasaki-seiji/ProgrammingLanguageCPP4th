/*
 * my_tuple.h
 *
 *  Created on: 2017/05/30
 *      Author: sasaki
 */

#ifndef MY_TUPLE_H_
#define MY_TUPLE_H_

#include "select.h"
#include "type_converter.h"
using namespace Estd;


template<typename Ret, int N> struct getNth;
template<typename... Values> class my_tuple;

template<> class my_tuple<> { };

template<typename Head, typename... Tail>
class my_tuple<Head, Tail...> : private my_tuple<Tail...> {
	typedef my_tuple<Tail...> inherited;
	template<typename Ret, int N>
		friend struct getNth;
public:
	constexpr my_tuple() { }

	my_tuple(const Head& h, const Tail&... t)
		: inherited(t...), m_head(h) { }

	template<typename... VValues>
	my_tuple(const my_tuple<VValues...>& other)
		: inherited(other.tail()), m_head(other.head()) { }

	template<typename... VValues>
	my_tuple& operator=(const my_tuple<VValues...>& other)
	{
		m_head = other.head();
		tail() = other.tail();
		return *this;
	}

protected:
	Head m_head;

private:
	Head& head() { return m_head; }
	const Head& head() const { return m_head; }

	inherited& tail() { return *this; }
	const inherited& tail() const { return *this; }
};


template<typename Ret, int N>
struct getNth {
	template<typename T>
	static Ret& get(T& t)
	{
		return getNth<Ret,N-1>::get(t.tail());
	}
	template<typename T>
	static const Ret& get(const T& t)
	{
		return getNth<Ret,N-1>::get(t.tail());
	}
};

template<typename Ret>
struct getNth<Ret,0> {
	template<typename T>
	static Ret& get(T& t)
	{
		return t.head();
	}
	template<typename T>
	static const Ret& get(const T& t)
	{
		return t.head();
	}
};

template<int N, typename... T>
Select<N, T...>& my_get(my_tuple<T...>& t)
{
	return getNth<Select<N, T...>, N>::get(t);
}

template<int N, typename... T>
const Select<N, T...>& my_get(const my_tuple<T...>& t)
{
	return getNth<Select<N, T...>, N>::get(t);
}

#if 1
template<typename... Types>
my_tuple<Decay<Types>...> my_make_tuple(Types&&... t)
{
	return my_tuple<Decay<Types>...>(t...);
}
#else
template<typename... Types>
my_tuple<Types...> my_make_tuple(Types&&... t)
{
	return my_tuple<Types...>(t...);
}
#endif
#endif /* MY_TUPLE_H_ */
