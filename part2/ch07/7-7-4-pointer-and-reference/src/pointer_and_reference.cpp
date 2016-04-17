/*
 * pointer_and_reference.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

void fp(char* p)
{
	while (*p)
		cout << *p++;
}

void fr(char& r)
{
	while (r)
		cout << r++;
}

void fr2(char& r)
{
	char* p = &r;
	while (*p)
		cout << *p++;
}

template<typename T>
class Proxy {
	T& m;
public:
	Proxy(T& mm) :m {mm} { }
};

template<typename T>
class Handle {
	T* m;
public:
	Handle(T* mm) :m{mm} { }
	void rebind(T* mm) { m = mm; }
};

struct Matrix { };

Matrix operator+(const Matrix& a, const Matrix& b) { return a; }
//Matrix operator-(const Matrix*, const Matrix*);
	// 'Matrix operator-(const Matrix*, const Matrix*)' must have an argument of class or enumerated type

Matrix y, z;
Matrix x = y+z;
//Matrix x2 = &y-&z;
	// conversion from 'long long int' to non-scalar type 'Matrix' requested

string s1 = "College Station";
string s2 = "Manhattan";

//string& a1[] = {s1, s2};
	// declaration of 'a1' as array of references
string* a2[] = {&s1, &s2};

//vector<string&> v1 = {s1, s2};
vector<string*> v2 = {&s1, &s2};

char* ident(char* p) { return p; }
char& r { *ident(nullptr) };

int main()
{
	char s[] = { 'a', 'b', 'c', '\0' };

	cout << "\nfp(&s[0]):\n";
	fp(&s[0]);

	cout << "\nfr(s[0]):\n";
	fr(s[0]);

	cout << "\nfr2(s[0]):\n";
	s[0] = 'a'; // fr(s[0]) changes s[0] !!!
	fr2(s[0]);

	int	x = 10, y = 20;
	Proxy<int> proxy {x};
	Handle<int> handle {&x};
	handle.rebind(&y);

	//cout << "r = " << r << '\n';
	// crash!!!
}

