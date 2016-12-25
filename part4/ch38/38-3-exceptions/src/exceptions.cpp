/*
 * exceptions.cpp
 *
 *  Created on: 2016/12/25
 *      Author: sasaki
 */


#include <iostream>
#include <sstream>
using namespace std;

struct Io_guard {
	istream& s;
	ios_base::iostate old_e;

	Io_guard(istream& ss, ios_base::iostate e) :s{ss}
	{
		old_e = s.exceptions();
		s.exceptions(old_e | e);
	}
	~Io_guard() { s.exceptions(old_e); }
};

void use(istream& is)
try
{
	Io_guard guard(is, ios_base::badbit);

	for (string s; is>>s; )
		cout << s << endl;

	is.setstate(ios_base::badbit);
}
catch (ios_base::failure& e)
{
	cerr << "ios_base::bad_bit - " << e.what() << endl;
}

int main()
{
	use(cin);
	istringstream iss("this is a istringstream");
	use(iss);
}
