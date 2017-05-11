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
#include <cctype>
#include <cwctype>

template<typename C>
class String {
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
	void move_from(String& x);
};


// internal functions

// 2017.05.11 change
template<typename C>
C* expand(const C* ptr, int old_sz, int new_sz)
{
	C* p = new C[new_sz];
	memcpy(p, ptr, sizeof(C)*old_sz);
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
		ptr = expand(x.ptr, x.sz+1, x.sz+1);
		sz = x.sz;
		space = 0;
	}
}

template<typename C>
void String<C>::move_from(String& x)
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
	move_from(x);
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
	move_from(x);
	return *this;
}

template<typename C>
String<C>& String<C>::operator+=(C c)
{
	if (sz==short_max) {
		int n = sz+sz+2;
		ptr = expand(ptr,sz+1,n);
		space = n-sz-2;
	}
	else if (short_max<sz) {
		if (space==0) {
			int n = sz+sz+2;
			C* p = expand(ptr, sz+1, n);
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


// template global operators

template<typename C>
std::basic_ostream<C>& operator<<(std::basic_ostream<C>& os, const String<C>& s)
{
	return os << s.c_str();

}



// 2017.05.11 change, but does not work for wcin

template<typename C>
bool temp_isspace(C ch);

inline bool temp_isspace(char ch)
{
	return isspace(ch);
}

inline bool temp_isspace(wchar_t ch)
{
	return iswspace(ch);
}

template<typename C>
std::basic_istream<C>& operator>>(std::basic_istream<C>& is, String<C>& s)
{
	s.clear();
	is >> std::ws;
	C ch;
	while(is.get(ch) && !temp_isspace(ch))
		s += ch;
	return is;
}


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

template<typename C>
bool operator<(const String<C>& a, const String<C>& b)
{
	int sz1 = a.size();
	int sz2 = b.size();
	int i,j;

	for (i=j=0; i<sz1 && j<sz2; ++i, ++j) {
		if (a[i] < b[i])
			return true;
		else if (a[i] > b[j])
			return false;
	}

	return i < j;

}

#if 0 // 2016.09.08 delete user defined literal
template<typename C>
String<C> operator"" _s(const char* p, size_t)
{
	return String<C>{p};
}
#endif



#endif /* STRING_H_ */
