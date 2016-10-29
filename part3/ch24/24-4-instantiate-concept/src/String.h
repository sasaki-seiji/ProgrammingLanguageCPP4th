/*
 * String.h
 *
 *  Created on: 2016/08/17
 *      Author: sasaki
 */

#ifndef STRING_H_
#define STRING_H_

#include <stdexcept>
#include <iostream>
#include <utility>
#include <cstring>
#include "concept.h"

template<typename C>
class String {
	static_assert(Estd::Ordered<C>(), "String's character type is not ordered");
public:
	String();

	String(const C* p);

	String(const String&);
	String& operator=(const String&);

	String(String&& x);
	String& operator=(String&& x);

	~String() { if (short_max<sz) delete [] ptr; }

	// 2016.09.08 add
	void clear()
	{ if (short_max<sz) delete [] ptr; sz = 0; ptr = ch; ch[0] = C{}; }

	C& operator[](int n) { return ptr[n]; }
	C operator[](int n) const { return ptr[n]; }

	C& at(int n) { check(n); return ptr[n]; }
	C at(int n) const { check(n); return ptr[n]; }

	String& operator+=(C c);

	C* c_str() { return ptr; }
	const C* c_str() const { return ptr; }

	int size() const { return sz; }
	int capacity() const
		{ return (sz<=short_max) ? short_max : sz+space; }

private:

	static const int short_max = 15;
	int sz;
	C* ptr;
	union {
		int space;
		C ch[short_max+1];
	};

	void check(int n) const
	{
		if (n<0 || sz<=n)
			throw std::out_of_range("String::at()");
	}

	void copy_from(const String& x);
	void move_from(String&& x);
};


// template global operators

// input, output

template<typename C>
std::ostream& operator<<(std::ostream& out, const String<C>& s)
{
	static_assert(Estd::Streamable<C>(), "String's character not streamable");
	out << '"';
	for (int i=0; i!=s.size(); ++i)
		out << s[i];
	out << '"';
	return out;

}

template<typename C>
std::istream& operator>>(std::istream& in, String<C>& s)
{
	static_assert(Estd::Streamable<C>(), "String's character not streamable");

	s.clear();
	in >> std::ws;

	C ch;
	while(in.get(ch) && !isspace(ch))
		s += ch;
	return in;
}


// begin,end

template<typename C>
C* begin(String<C>& x)
{
	return x.c_str();
}

template<typename C>
C* end(String<C>& x)
{
	return x.c_str() + x.size();
}

template<typename C>
const C* begin(const String<C>& x)
{
	return x.c_str();
}

template<typename C>
const C* end(const String<C>& x)
{
	return x.c_str() + x.size();
}

// compare

template<typename C>
bool operator==(const String<C>& a, const String<C>& b)
{
	if (a.size()!=b.size())
		return false;
	for (int i = 0; i!=a.size(); ++i)
		if (a[i]!=b[i])
			return false;
	return true;
}

// 2016.09.09 add
template<typename C>
bool operator==(const String<C>& a, const C* b)
{
	return a == String<C>(b);
}

// 2016.09.09 add
template<typename C>
bool operator==(const C* a, const String<C>& b)
{
	return String<C>(a) == b;
}


template<typename C>
bool operator!=(const String<C>& a, const String<C>& b)
{
	return !(a==b);
}

// 2016.09.09 add
template<typename C>
bool operator!=(const String<C>& a, const C* b)
{
	return !(a==b);
}

//2016.09.09 add
template<typename C>
bool operator!=(const C* a, const String<C>& b)
{
	return !(a==b);
}

// 2016.10.22 change
template<typename C>
bool operator<(const String<C>& a, const String<C>& b)
{
	static_assert(Estd::Ordered<C>(),"String's character type not ordered");
	return std::lexicographical_compare(
			begin(a), end(a), begin(b), end(b));
}

// 2016.10.22 add
template<typename C>
bool operator<=(const String<C>& a, const String<C>& b)
{
	return a == b || a < b;
}

// 2016.10.22 add
template<typename C>
bool operator>(const String<C>& a, const String<C>& b)
{
	return b < a;
}

// 2016.10.22 add
template<typename C>
bool operator>=(const String<C>& a, const String<C>& b)
{
	return b <= a;
}

// add(+), concatinate(+=)

template<typename C>
String<C>& operator+=(String<C>& a, const String<C>& b)
{
	for (auto x : b)
		a += x;
	return a;
}

// 2016.09.09 add
template<typename C>
String<C>& operator+=(String<C>& s, const C* p)
{
	return s += String<C>(p);
}

template<typename C>
String<C> operator+(const String<C>& a, const String<C>& b)
{
	String<C> res {a};
	res += b;
	return res;
}

// 2016.09.09 add
template<typename C>
String<C> operator+(const String<C>& a, const C* b)
{
	return a + String<C>(b);
}

// 2016.09.09 add
template<typename C>
String<C> operator+(const C* a, const String<C>& b)
{
	return String<C>(a) + b;
}

// template member functions

template<typename C>
String<C>::String()
	: sz{0}, ptr{ch}
{
	ch[0] = 0;
}

template<typename C>
String<C>::String(const C* p)
{
	int len;
	for (len = 0; p[len]; ++len)
		;
	sz = len;
	if (sz <=short_max) {
		ptr = ch;
	}
	else {
		ptr = new C[sz+1];
		space = 0;
	}

	std::memcpy(ptr, p, sizeof(C)*(sz+1));
}

template<typename C>
String<C>::String(const String& x)
{
	copy_from(x);
}

template<typename C>
String<C>::String(String&& x)
{
	//move_from(x);
	move_from(std::move(x));
		// error: cannot bind 'String' lvalue to 'String&&'
}

template<typename C>
String<C>& String<C>::operator=(const String& x)
{
	if (this==&x) return *this;
	C* p = (short_max<sz) ? ptr : 0;
	copy_from(x);
	delete[] p;
	return *this;
}

template<typename C>
String<C>& String<C>::operator=(String&& x)
{
	if (this==&x) return *this;
	if (short_max < sz) delete[] ptr;
	//move_from(x);
	move_from(std::move(x));
		// error: cannot bind 'String' lvalue to 'String&&'
	return *this;
}

template<typename C>
C* expand(const C* ptr, int n)
{
	C* p = new C[n];
	//strcpy(p,ptr);
	memcpy(p, ptr, sizeof(C)*n);
	return p;
}


template<typename C>
void String<C>::copy_from(const String& x)
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

template<typename C>
void String<C>::move_from(String&& x)
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

template<typename C>
String<C>& String<C>::operator+=(C c)
{
	if (sz==short_max) {
		int n = sz+sz+2;
		ptr = expand(ptr,n);
		space = n-sz-2;
	}
	else if (short_max<sz) {
		if (space==0) {
			int n = sz+sz+2;
			C* p = expand(ptr, n);
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


#endif /* STRING_H_ */
