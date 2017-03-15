/*
 * Test_element.h
 *
 *  Created on: 2017/03/14
 *      Author: sasaki
 */

#ifndef TEST_ELEMENT_H_
#define TEST_ELEMENT_H_


class Test_element {
	int id;
	int val;

public:
	Test_element(int v = 0);
	Test_element(const Test_element&);

	~Test_element();

	void trace(const char*);

private:
	static bool verbose_flag;
	static int construct_count;

	static int default_construct_count;
	static int default_construct_exception_enabled;
	static int default_construct_exception_count;

	static int copy_construct_count;
	static int copy_construct_exception_enabled;
	static int copy_construct_exception_count;

	static int destruct_count;

public:
	static void verbose(bool onoff =true) { verbose_flag = onoff; }

	static void trigger_default_construct_exception(int after);
	static void trigger_copy_construct_exception(int after);

	static void display_counters();
};


#endif /* TEST_ELEMENT_H_ */
