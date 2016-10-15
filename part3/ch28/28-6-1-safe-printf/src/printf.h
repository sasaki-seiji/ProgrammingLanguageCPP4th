/*
 * printf.h
 *
 *  Created on: 2016/10/15
 *      Author: sasaki
 */

#ifndef PRINTF_H_
#define PRINTF_H_

#include <iostream>
#include <stdexcept>

inline void vt_printf(const char* s)
{
	if (s==nullptr) return;

	while (*s) {
		if (*s=='%' && *++s!='%')
			throw std::runtime_error("invalid format: missing arguments");
		std::cout << *s++;
	}
}

template<typename T, typename... Args>
void vt_printf(const char* s, T value, Args... args)
{
	while (s && *s) {
		if (*s=='%' && *++s!='%') {
			std::cout << value;
			// 2016.10.16
			//return printf(++s, args...);
			vt_printf(*s?++s:s, args...);
			return ;
		}
		std::cout << *s++;
	}
	throw std::runtime_error("extra argments provided to printf");
}

#endif /* PRINTF_H_ */
