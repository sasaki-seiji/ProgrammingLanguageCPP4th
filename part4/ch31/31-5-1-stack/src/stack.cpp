/*
 * stack.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

stack<char> s1;
stack<int,vector<int>> s2;

void f()
{
	stack<int> s;
	s.push(2);
	if (s.empty()) {
		// do not pop
	}
	else {
		cout << "top: " << s.top() << endl;
		s.pop();
		s.pop();
	}
}

void f(stack<char>& s)
{
	if (s.top()=='c') s.pop();
}

int main()
{
	f();

	s1.push('c'); s1.push('x'); s1.push('c');
	cout << "s1.top(): " << s1.top() << endl;
	f(s1);
	cout << "s1.top(): " << s1.top() << endl;
	f(s1);
	cout << "s1.top(): " << s1.top() << endl;
}

