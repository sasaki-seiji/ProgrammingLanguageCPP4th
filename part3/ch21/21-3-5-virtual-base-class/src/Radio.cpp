/*
 * Radio.cpp
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#include "Radio.h"
#include <cstdio>
#include <fstream>
using namespace std;

void Radio::write()
{
	::remove(file_name.c_str());
	Transmitter::write();
	Receiver::write();
	ofstream ofs;
	ofs.open(file_name, ofstream::out | ofstream::app);
	ofs << "Radio" << '\n';
	ofs.close();
}

void Radio::read()
{
	// do nothing
}

