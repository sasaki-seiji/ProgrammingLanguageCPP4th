/*
 * namespace_alias.cpp
 *
 *  Created on: 2016/05/26
 *      Author: sasaki
 */

#include <iostream>

namespace A {
	class String {
	public:
		String(const char* p) { std::cout << "A::String(" << p << ")\n"; }
	};
}

A::String s1 = "Grieg";
A::String s2 = "Nielsen";

namespace American_Telephone_and_Telegram {
	class String {
	public:
		String(const char* p) { std::cout << "American_Telephone_and_Telegram::String(" << p << ")\n"; }
	};
}

American_Telephone_and_Telegram::String s3 = "Grieg";
American_Telephone_and_Telegram::String s4 = "Nielsen";

namespace ATT = American_Telephone_and_Telegram;

ATT::String s5 = "Grieg";
ATT::String s6 = "Nielsen";

int main()
{

}
