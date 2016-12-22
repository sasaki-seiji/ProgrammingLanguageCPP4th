/*
 * regex_search.cpp
 *
 *  Created on: 2016/12/21
 *      Author: sasaki
 */


#include <regex>
#include <iostream>
using namespace std;

int main()
{
	regex pat {"[Ss]tro?u?v?p?stra?o?u?p?b?"};

	smatch m;
	for (string s; cin>>s; )
		if (regex_search(s,m,pat))
			if (m[0]!="stroustrup" && m[0]!="Stroustrup")
				cout << "Found: " << m[0] << '\n';
}
