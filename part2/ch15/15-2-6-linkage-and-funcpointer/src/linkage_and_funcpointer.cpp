/*
 * linkage_and_funcpointer.cpp
 *
 *  Created on: 2016/07/10
 *      Author: sasaki
 */

#include <cstddef>	// for size_t

typedef int (*FT)(const void*, const void*);

extern "C" {
	typedef int (*CFT)(const void*, const void*);
	void qsort(void* p, size_t n, size_t sz, FT cmp);
}

void isort(void*p, size_t n, size_t sz, FT cmp);
void xsort(void* p, size_t n, size_t sz, CFT cmp);
extern "C" void ysort(void* p, size_t n, size_t sz, FT cmp);

int compare(const void*, const void*);
extern "C" int ccmp(const void*, const void*);

void f(char* v, int sz)
{
	qsort(v,sz,1,&compare);
	qsort(v,sz,1,&ccmp);

	isort(v,sz,1,&compare);
	isort(v,sz,1,&ccmp);
}

// define undef-func
#include <iostream>
using namespace std;

extern "C" {
	void qsort(void* p, size_t n, size_t sz, FT cmp)
	{
		cout << "extern \"C\" qsort()\n";
		cmp(p, p);
	}
	void ysort(void* p, size_t n, size_t sz, FT cmp)
	{
		cout << "extern \"C\" ysort()\n";
		cmp(p, p);
	}
	int ccmp(const void*, const void*){
		cout << "extern \"C\" ccmp()\n";
	}
}

void isort(void*p, size_t n, size_t sz, FT cmp)
{
	cout << "isort()\n";
	cmp(p, p);
}
void xsort(void* p, size_t n, size_t sz, CFT cmp)
{
	cout << "xsort()\n";
	cmp(p, p);
}
int compare(const void*, const void*)
{
	cout << "compare()\n";
}

// add main func
int main()
{
	char v[] = {'a', 'x', '1', 'b' };
	f(v, sizeof(v));
}
