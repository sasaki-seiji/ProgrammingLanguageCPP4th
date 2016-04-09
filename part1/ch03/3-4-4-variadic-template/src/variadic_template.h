/*
 * variadic_template.h
 *
 *  Created on: 2016/03/30
 *      Author: sasaki
 */

#ifndef VARIADIC_TEMPLATE_H_
#define VARIADIC_TEMPLATE_H_

#include <iostream>

void f() {}

template<typename T>
void g(T x)
{
	std::cout << x << " ";
}

template<typename T, typename... Tail>
void f(T head, Tail... tail)
{
	g(head);
	f(tail...);
}

#endif /* VARIADIC_TEMPLATE_H_ */
