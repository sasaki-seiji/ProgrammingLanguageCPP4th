/*
 * increment_and_decrement.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <cstring>
#include <iostream>
using namespace std;

void cpy(char* p, const char* q)
{
	while (*p++ = *q++) ;
}

void cpy2(char*p, const char*  q)
{
	int length = strlen(q);
	for (int i = 0; i <= length; i++)
		p[i] = q[i];
}

void cpy3(char* p, const char* q)
{
	int i;
	for (i = 0; q[i]!=0; i++)
		p[i] = q[i];
	p[i] = 0;
}

void cpy4(char* p, const char* q)
{
	while (*q != 0) {
		*p = *q;
		p++;
		q++;
	}
	*p = 0;
}

void cpy5(char* p, const char* q)
{
	while (*q != 0) {
		*p++ = *q++;
	}
	*p = 0;
}

void cpy6(char* p, const char* q)
{
	while ((*p++ = *q++) != 0) { }
}

int main()
{
	char src[] = "this is a string to be copied";
	char dst[80], dst2[80], dst3[80], dst4[80], dst5[80], dst6[80]  ;

	cpy(dst, src);
	cout << "cpy: " << dst << '\n';
	cpy2(dst2, src);
	cout << "cpy2: " << dst2 << '\n';
	cpy3(dst3, src);
	cout << "cpy3: " << dst3 << '\n';
	cpy4(dst4, src);
	cout << "cpy4: " << dst4 << '\n';
	cpy5(dst5, src);
	cout << "cpy5: " << dst5 << '\n';
	cpy6(dst6, src);
	cout << "cpy6: " << dst6 << '\n';
}

