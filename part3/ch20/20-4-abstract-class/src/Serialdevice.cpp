/*
 * Serialdevice.cpp
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#include "Serialdevice.h"

#include <iostream>
using namespace std;

Serial_device::Serial_device(int u)
	: unit{u}
{
}

int Serial_device::open(int opt)
{
	cout << "Serial_device::open(" << opt << ")\n";
	return 0;
}
int Serial_device::close(int opt)
{
	cout << "Serial_device::close(" << opt << ")\n";
	return 0;
}
int Serial_device::read(char* p, int n)
{
	cout << "Serial_device::read(" << (void*)p << "," << n << ")\n";
	return 0;
}
int Serial_device::write(const char* p, int n)
{
	cout << "Serial_device::write(" << (const void*)p << "," << n << ")\n";
	return 0;
}
int Serial_device::ioctl(int ...)
{
	cout << "Serial_device::ioctl()\n";
	return 0;
}

Serial_device::~Serial_device() {
}

