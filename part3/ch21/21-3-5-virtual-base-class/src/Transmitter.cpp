/*
 * Transmitter.cpp
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#include "Transmitter.h"
#include <fstream>
using namespace std;

void Transmitter::write()
{
	ofstream ofs;
	ofs.open(file_name, ofstream::out | ofstream::app);
	ofs << "Transmitter" << '\n';
	ofs.close();
}

