/*
 * objholder.h
 *
 *  Created on: 2016/10/03
 *      Author: sasaki
 */

#ifndef OBJHOLDER_H_
#define OBJHOLDER_H_

#include <string>

constexpr int on_stack_max = sizeof(std::string);

template<typename T>
struct On_heap {
	On_heap() :p(new T) { }
	~On_heap() { delete p; }

	T& operator*() { return *p; }
	T* operator->() { return p; }

	On_heap(const On_heap&) = delete;
	On_heap& operator=(const On_heap&) = delete;

private:
	T* p;
};

template<typename T>
struct Scoped {
	Scoped() { }

	T& operator*() { return x; }
	T* operator->() { return &x; }

	Scoped(const Scoped&) = delete;
	Scoped& operator=(const Scoped&) = delete;

private:
	T x;
};

template<bool C, typename T, typename F>
using Conditional = typename std::conditional<C,T,F>::type;

template<typename T>
struct Obj_holder {
	using type = Conditional<(sizeof(T)<=on_stack_max),Scoped<T>,On_heap<T>>;
};

template<typename T>
using Holder = typename Obj_holder<T>::type;

#endif /* OBJHOLDER_H_ */
