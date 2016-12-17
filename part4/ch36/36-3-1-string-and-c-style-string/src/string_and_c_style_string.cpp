/*
 * string_and_c_style_string.cpp
 *
 *  Created on: 2016/12/17
 *      Author: sasaki
 */


#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// concatenate

string address(const string& identifier, const string& domain)
{
	return identifier + '@' + domain;
}

void test()
{
	string t = address("bs", "somewhere");
	cout << t << '\n';
}

char* address(const char* identifier, const char* domain)
{
	int iden_len = strlen(identifier);
	int dom_len = strlen(domain);
	char* addr = (char*)malloc(iden_len+dom_len+2);
	strcpy(addr,identifier);
	addr[iden_len] = '@';
	strcpy(addr+iden_len+1,domain);
	return addr;
}

void test2()
{
	char* t = address("bs", "somewhere");
	printf("%s\n",t);
	free(t);
}

// compare

void insanity()
{
	cout << "insanity\n";
	exit(1);
}

void test3()
{
	string s1 = "Ring";
	if (s1!="Ring") insanity();
	if (s1<"Opera") cout << "check";
	string s2 = address(s1,"Valkyrie");
	cout << s2 << '\n';

	char s3[] = "Ring";
	if (strcmp(s3,"Ring")!=0) insanity();
	if (strcmp(s3,"Opera")<0) cout << "check";
	char* s4 = address(s3,"Valkyrie");
	printf("%s\n", s4);
	free(s4);
}

// sort

static int compare_cstring(const void* a, const void* b)
{
	const char* ps1 = *(const char**)a;
	const char* ps2 = *(const char**)b;
	return strcmp(ps1, ps2);
}

void test4()
{
	vector<string> vs = {"Grieg", "Williams", "Bach", "Handel"};
	sort(vs.begin(),vs.end());
	for (auto b = vs.begin(); b != vs.end(); ++b)
		cout << *b << ", ";
	cout << endl;

	const char* as[] = {"Grieg", "Williams", "Bach", "Handel"};
#if 0	// terrible
	qsort(as, sizeof(*as), sizeof(as)/sizeof(*as),
			(int(*)(const void*,const void*))strcmp);
#else
	qsort(as, sizeof(as)/sizeof(*as),sizeof(*as), compare_cstring);
#endif
	for (size_t i=0; i < sizeof(as)/sizeof(*as); ++i)
		cout << as[i] << ", ";
	cout << endl;
}

// main

int main()
{
	test();
	test2();
	test3();
	test4();
}
