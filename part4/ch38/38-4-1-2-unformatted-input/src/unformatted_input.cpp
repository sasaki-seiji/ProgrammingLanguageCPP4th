/*
 * unformatted_input.cpp
 *
 *  Created on: 2016/12/25
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

#define MAX_WORD	10
#define MAX_LINE	20

void f()
{
	char word[MAX_WORD][MAX_LINE];
	int i = 0;
	while (cin.getline(word[i++],MAX_LINE,'\n') && i<MAX_WORD)
		;

	for (int j=0; j<i; ++j)
		cout << word[j] << '\n';
}


int main()
{
	f();
}
