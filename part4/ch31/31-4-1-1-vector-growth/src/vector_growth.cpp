/*
 * vector_growth.cpp
 *
 *  Created on: 2016/11/26
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;


void read_word()
{
	vector<char> chars;
	constexpr int max = 20000;
	chars.reserve(max);
	vector<char*> words;

	bool in_word = false;
	for (char c; cin.get(c); ) {
		if (isalpha(c)) {
			if (!in_word) {
				in_word = true;
				chars.push_back(0);
				chars.push_back(c);
				words.push_back(&chars.back());
			}
			else
				chars.push_back(c);
		}
		else
			in_word = false;
	}
#if 0 // bug - example: abc012[NL][EOF]
	if (in_word)
		chars.push_back(0);
#else
	chars.push_back(0);
#endif

	if (max < chars.size()) {
		cerr << "overflow" << endl;
	}

	for (auto x : words)
		cout << x << endl;
}

int main()
{
	read_word();
}
