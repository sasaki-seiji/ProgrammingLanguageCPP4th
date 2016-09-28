/*
 * convert_template.cpp
 *
 *  Created on: 2016/09/28
 *      Author: sasaki
 */

#include "shape.h"

template<typename T>
class Ptr {
	T* p;
public:
	Ptr(T* pp) :p{pp} { }	// shared
	Ptr(const Ptr& ptr) { p = ptr.p; }	// shared
	template<typename T2>
		explicit operator Ptr<T2>();

	T* operator->() { return p; }
};

template<typename T>
	template<typename T2>
		Ptr<T>::operator Ptr<T2>()
		{
			return Ptr<T2>(p);
		}


void f(Ptr<Circle> pc)
{
	Ptr<Shape> ps {pc};
	//Ptr<Circle> pc2 {ps};
		// error: invalid conversion from 'Shape*' to 'Circle*' [-fpermissive]

	ps->draw();
}

// add main

int main()
{
	Point pt {1,2};
	Circle circle{pt,3};
	Ptr<Circle> pc{&circle};
	f(pc);
}
