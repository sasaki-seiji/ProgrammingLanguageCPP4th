/*
 * iota.cpp
 *
 *  Created on: 2017/01/14
 *      Author: sasaki
 */


#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

void error(const string& mes)
{
	cerr << mes << endl;
	exit(1);
}

int main()
{
	vector<int> v(5);
	iota(v.begin(), v.end(), 50);
	vector<int> v2 {50,51,52,53,54};

	if (v!=v2)
		error("complain to your library vendor");
}
