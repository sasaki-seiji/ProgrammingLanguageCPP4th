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

namespace Foundation_library_v2r11 {
	class set {
	public:
		set() { std::cout << "Foundation_library_v2r11::set()\n"; }
	};
	class String {
	public:
		String(const char* p) { std::cout << "Foundation_library_v2r11::String(" << p << ")\n"; }
	};
}

namespace Lib = Foundation_library_v2r11;

Lib::set s;
Lib::String s7 = "Sibelius";


int main()
{

}
