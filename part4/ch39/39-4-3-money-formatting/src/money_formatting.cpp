/*
 * money_formatting.cpp
 *
 *  Created on: 2017/01/04
 *      Author: sasaki
 */


#include "Money.h"
using namespace std;

void f(long int i)
{
	cout << "Value= " << i << " amount= " << Money{i} << '\n';
}

int main()
{
	long long i = -123456789;
	cout << "default:     ";
	f(i);

	locale loc_my_money {locale(), new My_money_io};
	cout << "My_money_io: ";
	cout.imbue(loc_my_money);
	f(i);

	locale loc_en{"en_US.UTF-8"};
	cout << "en_US.UTF-8: ";
	cout.imbue(loc_en);
	f(i);

	locale loc_jp{""};
	cout << "preferred:   ";
	cout.imbue(loc_jp);
	f(i);

	locale loc_fr{"fr_FR.UTF-8"};
	cout << "fr_FR.UTF-8: ";
	cout.imbue(loc_fr);
	f(i);
}

