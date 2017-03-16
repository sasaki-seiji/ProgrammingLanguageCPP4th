/*
 * Test_element.cpp
 *
 *  Created on: 2017/03/14
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

#include "Test_element.h"

bool Test_element::verbose_flag = false;
int Test_element::construct_count = 0;

int Test_element::default_construct_count = 0;
bool Test_element::default_construct_exception_enabled = false;
int Test_element::default_construct_exception_count = 0;

int Test_element::copy_construct_count = 0;
bool Test_element::copy_construct_exception_enabled = false;
int Test_element::copy_construct_exception_count = 0;

int Test_element::assign_count = 0;
bool Test_element::assign_exception_enabled = false;
int Test_element::assign_exception_count = 0;

int Test_element::destruct_count = 0;

Test_element::Test_element(int v)
	: id{construct_count}, val{v}
{
	if (verbose_flag) trace("(T) default construct: ");

	if (default_construct_exception_enabled)
		if (default_construct_exception_count == default_construct_count) {
			default_construct_exception_enabled = false;
			if (verbose_flag) trace("(T) fire default construct error: ");
			throw runtime_error("default construct fail");
		}

	++default_construct_count;
	++construct_count;
}

Test_element::Test_element(const Test_element& a)
	: id{construct_count}, val{a.val}
{
	if (verbose_flag) trace("(T) copy construct: ");

	if (copy_construct_exception_enabled)
		if (copy_construct_exception_count == copy_construct_count) {
			copy_construct_exception_enabled = false;
			if (verbose_flag) trace("(T) fire copy construct error: ");
			throw runtime_error("copy construct fail");
		}

	++copy_construct_count;
	++construct_count;
}

Test_element& Test_element::operator=(const Test_element& a)
{
	if (verbose_flag) {
		a.trace("(T) assign from: ");
		trace("(T) assign to: ");
	}

	if (assign_exception_enabled)
		if (assign_exception_count == assign_count) {
			assign_exception_enabled = false;
			if (verbose_flag) trace("(T) fire assign error: ");
			throw runtime_error("assign fail");
		}

	val = a.val;
	++assign_count;

	return *this;
}

Test_element::~Test_element()
{
	if (verbose_flag) trace("(T) destruct: ");

	++destruct_count;
}

void Test_element::trace(const char* mes) const
{
	cout << mes << "id = #" << id << ", val = " << val << endl;
}

void Test_element::display_counters()
{
	cout << "------------ counters ------------\n";
	cout << "(C) construct count = " << construct_count << endl;
	cout << "(C)   default construct count = " << default_construct_count << endl;
	cout << "(C)   copy construct count = " << copy_construct_count << endl;
	cout << "(C) assign count = " << assign_count <<endl;
	cout << "(C) destruct count = " << destruct_count << endl;

}

void Test_element::trigger_default_construct_exception(int after)
{
	if (verbose_flag) cout << "(T) trigger_default_construct_exception(" << after << ")\n";
	default_construct_exception_count = default_construct_count + after;
	default_construct_exception_enabled = true;
}

void Test_element::trigger_copy_construct_exception(int after)
{
	if (verbose_flag) cout << "(T) trigger_copy_construct_exception(" << after << ")\n";
	copy_construct_exception_count = copy_construct_count + after;
	copy_construct_exception_enabled = true;
}

void Test_element::trigger_assign_exception(int after)
{
	if (verbose_flag) cout << "(T) trigger_assign_exception(" << after << ")\n";
	assign_exception_count = assign_count + after;
	assign_exception_enabled = true;
}
