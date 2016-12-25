/*
 * formatted_input.cpp
 *
 *  Created on: 2016/12/25
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

template<typename T1, typename T2>
void read_pair(T1& x, T2& y)
{
	char c1, c2, c3;
	cin >> c1 >> x >> c2 >> y >> c3;
	if (c1!='{' || c2!=',' || c3!='}') {
		cin.setstate(ios_base::badbit);
		throw runtime_error("bad read of pair");
	}
}

void read_integers()
{
	for (int i; cin>>i && 0<i; )
		cout << i << '\n';
}

int main()
{
	try {
		int x, y;
		read_pair(x,y);
		cout << "x: " << x << ", y: " << y << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
	}

	read_integers();
}
