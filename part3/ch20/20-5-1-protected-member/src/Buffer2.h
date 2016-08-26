/*
 * Buffer2.h
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */

#ifndef BUFFER2_H_
#define BUFFER2_H_

#include <iostream>

class Buffer2 {
protected:
	char a[128];
};

class Linked_buffer2 : public Buffer2 {

};

class Circular_buffer2 : public Buffer2 {
public:
	void f(Linked_buffer2* p)
	{
		std::cout << "Circular_buffer2::f()\n";
		a[0] = 0;
		//p->a[0] = 0;
			// error: 'char Buffer2::a [128]' is protected
	}
};

#endif /* BUFFER2_H_ */
