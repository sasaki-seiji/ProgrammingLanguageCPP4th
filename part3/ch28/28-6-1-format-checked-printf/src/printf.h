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
#include "concept.h"

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
		if (*s=='%') {
			switch (*++s) {
			case '%':
				// 2016.10.16 bug-fix
				//break;
				std::cout << *s++;
				continue;
			case 's':
				if (!Estd::Is_C_style_string<T>()&& !Estd::Is_string<T>())
					throw std::runtime_error("Bad printf() format");
				break;
			case 'd':
				if (!Estd::Is_integral<T>()) throw std::runtime_error("Bad printf() format");
				break;
			case 'g':
				if (!Estd::Is_floating_point<T>()) throw std::runtime_error("Bad printf() format");
				break;
			}
			std::cout << value;
			return vt_printf(*s?++s:s, args...);
		}
		std::cout << *s++;
	}
	throw std::runtime_error("extra argments provided to printf");
}

#endif /* PRINTF_H_ */
