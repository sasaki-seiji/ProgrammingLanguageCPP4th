/*
 * num_put.cpp
 *
 *  Created on: 2017/01/03
 *      Author: sasaki
 */


#include <sstream>
#include "Double.h"
using namespace std;

int main()
{
	Double d {12345.6789};
	cout << d << endl;

	ostringstream oss;
	oss << d;
	cout << oss.str() << endl;

	ostringstream oss2;
	oss2.imbue(locale("da_DK.UTF-8"));
	oss2 << d;
	cout << oss2.str() << endl;
}
