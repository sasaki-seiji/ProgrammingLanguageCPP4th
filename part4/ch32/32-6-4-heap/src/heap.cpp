/*
 * heap.cpp
 *
 *  Created on: 2016/12/02
 *      Author: sasaki
 */


#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s = "herewego"; 			cout << s << endl;
	make_heap(s.begin(), s.end());	cout << s << endl;
	pop_heap(s.begin(), s.end());	cout << s << endl;
	pop_heap(s.begin(), s.end()-1);	cout << s << endl;
	pop_heap(s.begin(), s.end()-2);	cout << s << endl;

	*(s.end()-3) = 'f';
	push_heap(s.begin(), s.end()-2);	cout << s << endl;
	*(s.end()-2) = 'x';
	push_heap(s.begin(), s.end()-1);	cout << s << endl;
	*(s.end()-1) = 'y';
	push_heap(s.begin(), s.end());		cout << s << endl;
	sort_heap(s.begin(), s.end());		cout << s << endl;
	reverse(s.begin(), s.end());		cout << s << endl;
}
