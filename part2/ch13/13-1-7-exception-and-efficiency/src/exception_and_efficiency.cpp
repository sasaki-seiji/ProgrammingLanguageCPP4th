/*
 * exception_and_efficiency.cpp
 *
 *  Created on: 2017/03/11
 *      Author: sasaki
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void g(int);
void h(const string&);

struct Error { };

bool err_g = false;
bool err_h = false;

void f()
{
	cout << boolalpha;
	cout << "-- f() - err_g: " << err_g << ", err_h: " << err_h << "--\n";
	cout << "enter string: ";

	string buf;
	cin >> buf;

	g(1);
	h(buf);
}

void g(int x)
{
	cout << "-- g(" << x << ") --\n";
	if (err_g) throw Error{};
}

void h(const string& str)
{
	cout << "-- h(\"" << str << "\") --\n";
	if (err_h) throw Error{};
}

bool g2(int);
bool h2(const char*);
char* read_long_string();

bool f2()
{
	char* s = read_long_string();

	if (g2(1)) {
		if (h2(s)) {
			free(s);
			return true;
		}
		else {
			free(s);
			return false;
		}
	}
	else {
		free(s);
		return false;
	}
}

bool g2(int x)
{
	cout << "-- g2(" << x << ") --\n";
	return !err_g;
}

bool h2(const char* str)
{
	cout << "-- h2(\"" << str << "\") --\n";
	return !err_h;
}

char* read_long_string()
{
	const char* mes = "this is a long string";
	char* p = (char*)malloc(strlen(mes)+1);
	strcpy(p, mes);
	return p;
}

int main()
{
	f();

	try {
		err_g = true;
		f();
	}
	catch (const Error& e) {
		cout << "caught Error\n";
		err_g = false;
	}

	try {
		err_h = true;
		f();
	}
	catch (const Error& e) {
		cout << "caught Error\n";
		err_h = false;
	}

	int suc = f2();
	if (suc) cout << "f2() succeeded\n";
	else cout << "f2() failed\n";

	err_g = true;
	suc = f2();
	if (suc) cout << "f2() succeeded\n";
	else cout << "f2() failed\n";
	err_g = false;

	err_h = true;
	suc = f2();
	if (suc) cout << "f2() succeeded\n";
	else cout << "f2() failed\n";
	err_h = false;
}
