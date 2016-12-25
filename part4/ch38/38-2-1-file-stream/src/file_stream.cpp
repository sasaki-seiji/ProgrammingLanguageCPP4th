/*
 * file_stream.cpp
 *
 *  Created on: 2016/12/24
 *      Author: sasaki
 */


#include <fstream>
#include <iostream>
using namespace std;

void error(const string& mes)
{
	cerr << mes << endl;
}

int main()
{
	ofstream ofs("target");
	if (!ofs)
		error("couldn't open 'target' for writing");
	fstream ifs;
	ifs.open("source", ios_base::in);
	if (!ifs)
		error("couldn't open 'source' for writing");
}
