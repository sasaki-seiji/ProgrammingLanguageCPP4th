/*
 * binary_mode.cpp
 *
 *  Created on: 2016/12/26
 *      Author: sasaki
 */


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template<typename T>
char* as_bytes(T& i)
{
	//return static_cast<char*>(&i);
	return reinterpret_cast<char*>(&i);
}

void test()
{
	ifstream ifs("source", ios_base::binary);
	ofstream ofs("target", ios_base::binary);

	vector<int> v;

	for (int i; ifs.read(as_bytes(i), sizeof(i)); )
		v.push_back(i);

	for (auto x : v)
		cout << x << ", ";
	cout << endl;

	for (auto i : v)
		ofs.write(as_bytes(i), sizeof(i));
}

void prepare()
{
	ofstream ofs("source", ios_base::binary);

	vector<int> v {1,2,3,4,5,6,7,8,9};

	for (auto i : v)
		ofs.write(as_bytes(i), sizeof(i));
}

int main()
{
	prepare();
	test();
}
