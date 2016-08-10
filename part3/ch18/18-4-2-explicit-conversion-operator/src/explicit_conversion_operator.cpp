/*
 * explicit_conversion_operator.cpp
 *
 *  Created on: 2016/08/10
 *      Author: sasaki
 */

#include <memory>
#include <iostream>
using namespace std;

class Invalid_unique_ptr { } ;
class Record { };

void use(unique_ptr<Record> p, unique_ptr<int> q)
{
	if (!p)
		throw Invalid_unique_ptr{};

	//bool b = p;
		// error: cannot convert 'std::unique_ptr<Record>' to 'bool' in initialization
	//int x = p+q;
		// error: no match for 'operator+' (operand types are 'std::unique_ptr<Record>' and 'std::unique_ptr<int>')

	bool bp {p};
	cout << "bp: " << bp << '\n';
	bool bq {q};
	cout << "bq: " << bq << '\n';
}

// add main

int main()
{
	Record* prec = new Record;

	use(unique_ptr<Record>{prec}, unique_ptr<int>{nullptr});
}
