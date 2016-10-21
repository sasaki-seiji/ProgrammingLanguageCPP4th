/*
 * user.cpp
 *
 *  Created on: 2016/09/08
 *      Author: sasaki
 */

#include "concept.h"
#include "String.h"
#include <string>
using namespace Estd;

static_assert(Ordered<std::string>(),"std::string is not Ordered");
static_assert(Ordered<String<char>>(),"String<char> is not Ordered");


void test_19_3_6_for_char();
void word_count();

int main()
{
	test_19_3_6_for_char();
	word_count();
}


