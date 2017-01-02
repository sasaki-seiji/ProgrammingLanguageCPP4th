/*
 * change_global_locale.cpp
 *
 *  Created on: 2017/01/02
 *      Author: sasaki
 */

#include <locale>
#include <iostream>
using namespace std;

void user_set_locale(const string& question)
{
	cout << question;
	string s;
	cin >> s;
	locale::global(locale{s});
}

void set_loc(locale& loc, const char* name)
try
{
	loc = locale(name);
}
catch (runtime_error&) {
	cerr << "locale \"" << name << "\" isn't defined\n";
}

void print_locale_names(const locale& my_loc)
{
	cout << "name of current global loale: " << locale().name() << '\n';
	cout << "name of classic C locale: " << locale::classic().name() << '\n';
	cout << "name of \"user's preferred locale\": " << locale("").name() << '\n';
	cout << "name of my locale: " << my_loc.name() << '\n';
}

int main()
{
	string mes = "enter new global locale name: ";
	user_set_locale(mes);

	locale my_loc;
	set_loc(my_loc, "da_DK.UTF-8");

	print_locale_names(my_loc);
}

