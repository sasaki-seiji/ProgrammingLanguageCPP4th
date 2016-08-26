/*
 * user.cpp
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */


#include "Buffer.h"
#include "Circularbuffer.h"
#include "Buffer2.h"
#include <iostream>
using namespace std;

int main()
{
	Circular_buffer buf(10);

	for (int i = 0 ; i < 10; ++i)
		buf[i] = 'a' + i;

	char *new_buf = new char[20];
	buf.reallocate(new_buf, 20);

	for (int i = 10; i < 20; ++i)
		buf[i] = '0' + (i-10);

	for (int i = 0; i < 20; ++i)
		cout << buf[i] << ' ';
	cout << '\n';

	Circular_buffer2 cbuf2;
	Linked_buffer2 rbuf2;
	cbuf2.f(&rbuf2);
}
