/*
 * search.cpp
 *
 *  Created on: 2016/11/28
 *      Author: sasaki
 */


#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string quote {"Why wast time learning, when ignorance is instantaneous?"};

bool in_quote(const string& s)
{
	auto p = search(quote.begin(),quote.end(),s.begin(),s.end());
	return p!=quote.end();
}

void g()
{
	bool b1 = in_quote("learning");
	bool b2 = in_quote("lemming");

	cout << "b1: " << b1 << endl;
	cout << "b2: " << b2 << endl;
}

int main()
{
	g();
}
