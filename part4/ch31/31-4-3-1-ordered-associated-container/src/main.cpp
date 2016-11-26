/*
 * main.cpp
 *
 *  Created on: 2016/11/26
 *      Author: sasaki
 */



void test_map_constructor();
void test_map_insert();
void test_map_emplace();
void test_multimap_equal_range();

void read_test();

int main()
{
	test_map_constructor();
	test_map_insert();
	test_map_emplace();
	test_multimap_equal_range();

	read_test();
}
