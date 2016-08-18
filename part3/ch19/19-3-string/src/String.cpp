/*
 * String.cpp
 *
 *  Created on: 2016/08/17
 *      Author: sasaki
 */

#include "String.h"
#include <cstring>
using namespace std;

char* expand(const char* ptr, int n)
{
	char* p = new char[n];
	strcpy(p,ptr);
	return p;
}

void String::copy_from(const String& x)
{
	if (x.sz<short_max) {
		memcpy(this, &x, sizeof(x));
		ptr = ch;
	}
	else {
		ptr = expand(x.ptr, x.sz+1);
		sz = x.sz;
		space = 0;
	}
}

void String::move_from(String&& x)
{
	if (x.sz<=short_max) {
		memcpy(this, &x, sizeof(x));
		ptr = ch;
	}
	else {
		ptr = x.ptr;
		sz = x.sz;
		space = x.space;
		x.ptr = x.ch;
		x.sz = 0;
		x.ch[0] = 0;
	}
}

String::String()
	: sz{0}, ptr{ch}
{
	ch[0] = 0;
}

String::String(const char* p)
	:sz{strlen(p)},
	 ptr{(sz<=short_max) ? ch : new char[sz+1]},
	 space{0}
{
	strcpy(ptr,p);
}

String::String(const String& x)
{
	copy_from(x);
}

String::String(String&& x)
{
	//move_from(x);
	move_from(move(x));
		// error: cannot bind 'String' lvalue to 'String&&'
}

String& String::operator=(const String& x)
{
	if (this==&x) return *this;
	char* p = (short_max<sz) ? ptr : 0;
	copy_from(x);
	delete[] p;
	return *this;
}

String& String::operator=(String&& x)
{
	if (this==&x) return *this;
	if (short_max < sz) delete[] ptr;
	//move_from(x);
	move_from(move(x));
		// error: cannot bind 'String' lvalue to 'String&&'
	return *this;
}

String& String::operator+=(char c)
{
	if (sz==short_max) {
		int n = sz+sz+2;
		ptr = expand(ptr,n);
		space = n-sz-2;
	}
	else if (short_max<sz) {
		if (space==0) {
			int n = sz+sz+2;
			char* p = expand(ptr, n);
			delete[] ptr;
			ptr = p;
			space = n-sz-2;
		}
		else
			--space;
	}

	ptr[sz] = c;
	ptr[++sz] = 0;

	return *this;
}

ostream& operator<<(ostream& os, const String& s)
{
	return os << s.c_str();

}

istream& operator>>(istream& is, String& s)
{
	s = "";
	is >> ws;
	char ch = ' ';
	while(is.get(ch) && !isspace(ch))
		s += ch;
	return is;
}

bool operator==(const String& a, const String& b)
{
	if (a.size()!=b.size())
		return false;
	for (int i = 0; i!=a.size(); ++i)
		if (a[i]!=b[i])
			return false;
	return true;
}
bool operator!=(const String& a, const String& b)
{
	return !(a==b);
}

char* begin(String& x)
{
	return x.c_str();
}
char* end(String& x)
{
	return x.c_str() + x.size();
}
const char* begin(const String& x)
{
	return x.c_str();
}
const char* end(const String& x)
{
	return x.c_str() + x.size();
}

String& operator+=(String& a, const String& b)
{
	for (auto x : b)
		a += x;
	return a;
}
String operator+(const String& a, const String& b)
{
	String res {a};
	res += b;
	return res;
}

String operator"" _s(const char* p, size_t)
{
	return String{p};
}

