/*
 * move_and_forward.cpp
 *
 *  Created on: 2016/12/17
 *      Author: sasaki
 */


#include <utility>
#include <iostream>
using namespace std;

void test_move()
{
	cout << "-- test_move() --\n";

	string s1 = "original string";
	string s2 = move(s1);
	string s3 = move("temporary");

	cout << "s1: " << s1 << endl;
	cout << "s2 - move(s1): " << s2 << endl;
	cout << "s3 - move(\"temporary\"): " << s3 << endl;
}

void test_forward()
{
	cout << "-- test_forward() --\n";

	int i = 7;

	//int j = forward(i);
		// error: no matching function for call to 'forward(int&)'
	int j = forward<int&>(i);
	//int k = forward(7);
		// error: no matching function for call to 'forward(int)'
	int k = forward<int>(7);

	cout << "i: " << i << endl;
	cout << "j - forward<int&>(i): " << j << endl;
	cout << "k - forward<int>(i): " << k << endl;

	string s1 = "original string";
	string s2 = forward<string&>(s1);
	string s3 = forward<string>("temporary");

	cout << "s1: " << s1 << endl;
	cout << "s2 - forward<string&>(s1): " << s2 << endl;
	cout << "s3 - forward<string>(\"temporary\"): " << s3 << endl;
}

int main()
{
	test_move();
	test_forward();
}
