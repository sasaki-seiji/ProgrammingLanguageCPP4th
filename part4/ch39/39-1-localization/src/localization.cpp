/*
 * localization.cpp
 *
 *  Created on: 2016/12/31
 *      Author: sasaki
 */


#include <locale>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#include "Date.h"
using namespace Chrono;

void cpy(istream& is, ostream& os)
{
	Date d;
	double volume;

	while (is >> d >> volume) {
		os << d << ' ' << volume << '\n';
	}
}


void test_cpy()
{
	istringstream iss{"Apr 12 1999  1000.3"};
	iss.imbue(locale{"en_US.UTF-8"});
	cout.imbue(locale{"fr_FR.UTF-8"});
	cpy(iss, cout);

	istringstream iss2{"juil. 12 1950  10,3"};
	iss2.imbue(locale{"fr_FR.UTF-8"});
	cout.imbue(locale{"en_US.UTF-8"});
	cpy(iss2, cout);

	istringstream iss3{"avril 03 1970  123,4"};
	iss3.imbue(locale{"fr_FR.UTF-8"});
	cout.imbue(locale{"en_US.UTF-8"});
	cpy(iss3, cout);
}

void f(istream& fin, ostream& fout, istream& fin2, ostream& fout2)
{
	fin.imbue(locale{"en_US.UTF-8"});
	fout.imbue(locale{"fr_FR.UTF-8"});
	cpy(fin,fout);

	fin2.imbue(locale{"fr_FR.UTF-8"});
	fout2.imbue(locale{"en_US.UTF-8"});
	cpy(fin2,fout2);
}

int main()
{
	test_cpy();

	ifstream ifs("en_us.txt"), ifs2("fr_fr.txt");
	ofstream ofs("fr_fr.out"), ofs2("en_us.out");

	f(ifs, ofs, ifs2, ofs2);
}
