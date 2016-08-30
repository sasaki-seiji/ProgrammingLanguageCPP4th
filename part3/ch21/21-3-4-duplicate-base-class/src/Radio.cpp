/*
 * Radio.cpp
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#include "Radio.h"
#include <iostream>
using namespace std;

string Radio::get_file()
{
	cout << "Radio::get_file()\n";
	return "some-file-name";
}

void Radio::read()
{
	cout << "Radio::read()\n";
}

void Radio::write()
{
	Transmitter::write();
	Receiver::write();
	cout << "Radio::write() own treatment\n";
}

