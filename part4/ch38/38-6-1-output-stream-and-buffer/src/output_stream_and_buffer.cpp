/*
 * output_stream_and_buffer.cpp
 *
 *  Created on: 2016/12/29
 *      Author: sasaki
 */


#include <iostream>
#include <fstream>
using namespace std;

void f(ofstream& fout)
{
	fout << "0123456789";
	fout.seekp(8);
	fout << '#';
	fout.seekp(-4,ios_base::cur);
	fout << '*';
}

int main()
{
	ofstream ofs{"output.txt"};
	f(ofs);
}
