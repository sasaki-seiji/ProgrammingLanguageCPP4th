/*
 * messages.cpp
 *
 *  Created on: 2017/01/06
 *      Author: sasaki
 */

#include <iostream>
#include "My_messages.h"
using namespace std;

string message_directory = "messages/";

void test()
{
	if (!has_facet<My_messages>(locale())) {
		cerr << "no messages facet found in " << locale().name() << '\n';
		exit(1);
	}

	const messages<char>& m = use_facet<My_messages>(locale());
	extern string message_directory;

	auto cat = m.open(message_directory,locale());
	if (cat<0) {
		cerr << "no catalog found\n";
		exit(1);
	}

	cout << m.get(cat,0,0,"Missed again!") << endl;
	cout << m.get(cat,1,2,"Missed again!") << endl;
	cout << m.get(cat,1,3,"Missed again!") << endl;
	cout << m.get(cat,3,0,"Missed again!") << endl;

}

int main()
{
	locale loc(locale(),new My_messages);
	locale::global(loc);

	test();
}
