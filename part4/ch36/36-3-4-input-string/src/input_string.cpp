/*
 * input_string.cpp
 *
 *  Created on: 2016/12/18
 *      Author: sasaki
 */


#include <string>
#include <vector>
#include <iostream>
using namespace std;

void successive_input()
{
	cout << "-- successive_input() --\n";
	cout << "enter first_name and second_name: " << flush;
	string first_name;
	string second_name;
	cin >> first_name >> second_name;
	cout << "first_name: " << first_name << ", second_name: " << second_name << endl << flush;
}

void echo_lines()
{
	cout << "-- echo_lines() --\n" << flush;

	vector<string> lines;
	for (string s; getline(cin,s);)
		lines.push_back(s);

	for (auto& x : lines)
		cout << x << endl;
}

int main()
{
	successive_input();
	echo_lines();
}
