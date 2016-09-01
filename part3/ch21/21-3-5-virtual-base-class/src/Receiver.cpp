/*
 * Receiver.cpp
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#include "Receiver.h"
#include <fstream>
using namespace std;

void Receiver::write()
{
	ofstream ofs;
	ofs.open(file_name, ofstream::out | ofstream::app);
	ofs << "Receiver" << '\n';
	ofs.close();
}

