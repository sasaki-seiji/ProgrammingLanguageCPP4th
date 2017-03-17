/*
 * Test_element.h
 *
 *  Created on: 2017/03/14
 *      Author: sasaki
 */

#ifndef TEST_ELEMENT_H_
#define TEST_ELEMENT_H_


template<typename T>
class Test_element {
	int id;
	T val;

public:
	Test_element(const T& v = {});
	Test_element(const Test_element<T>&);
	Test_element& operator=(const Test_element<T>&);

	~Test_element();

	T value() const { return val; }
	void trace(const char*) const;

private:
	static bool verbose_flag;
	static int construct_count;

	static int default_construct_count;
	static bool default_construct_exception_enabled;
	static int default_construct_exception_count;

	static int copy_construct_count;
	static bool copy_construct_exception_enabled;
	static int copy_construct_exception_count;

	static int assign_count;
	static bool assign_exception_enabled;
	static int assign_exception_count;

	static int destruct_count;

public:
	static void verbose(bool onoff =true) { verbose_flag = onoff; }

	static void trigger_default_construct_exception(int after);
	static void trigger_copy_construct_exception(int after);
	static void trigger_assign_exception(int after);

	static void display_counters();
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Test_element<T>& e)
{
	return os << e.value();
}

template<typename T>
bool Test_element<T>::verbose_flag = false;

template<typename T>
int Test_element<T>::construct_count = 0;

template<typename T>
int Test_element<T>::default_construct_count = 0;
template<typename T>
bool Test_element<T>::default_construct_exception_enabled = false;
template<typename T>
int Test_element<T>::default_construct_exception_count = 0;

template<typename T>
int Test_element<T>::copy_construct_count = 0;
template<typename T>
bool Test_element<T>::copy_construct_exception_enabled = false;
template<typename T>
int Test_element<T>::copy_construct_exception_count = 0;

template<typename T>
int Test_element<T>::assign_count = 0;
template<typename T>
bool Test_element<T>::assign_exception_enabled = false;
template<typename T>
int Test_element<T>::assign_exception_count = 0;

template<typename T>
int Test_element<T>::destruct_count = 0;


template<typename T>
void Test_element<T>::trace(const char* mes) const
{
	cout << mes << "id = #" << id << ", val = " << val << endl;
}


template<typename T>
void Test_element<T>::display_counters()
{
	cout << "------------ counters ------------\n";
	cout << "(C) construct count = " << construct_count << endl;
	cout << "(C)   default construct count = " << default_construct_count << endl;
	cout << "(C)   copy construct count = " << copy_construct_count << endl;
	cout << "(C) assign count = " << assign_count <<endl;
	cout << "(C) destruct count = " << destruct_count << endl;
}


template<typename T>
Test_element<T>::Test_element(const T& v)
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

template<typename T>
Test_element<T>::Test_element(const Test_element& a)
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


template<typename T>
Test_element<T>& Test_element<T>::operator=(const Test_element& a)
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

template<typename T>
Test_element<T>::~Test_element()
{
	if (verbose_flag) trace("(T) destruct: ");

	++destruct_count;
}

template<typename T>
void Test_element<T>::trigger_default_construct_exception(int after)
{
	if (verbose_flag) cout << "(T) trigger_default_construct_exception(" << after << ")\n";
	default_construct_exception_count = default_construct_count + after;
	default_construct_exception_enabled = true;
}

template<typename T>
void Test_element<T>::trigger_copy_construct_exception(int after)
{
	if (verbose_flag) cout << "(T) trigger_copy_construct_exception(" << after << ")\n";
	copy_construct_exception_count = copy_construct_count + after;
	copy_construct_exception_enabled = true;
}

template<typename T>
void Test_element<T>::trigger_assign_exception(int after)
{
	if (verbose_flag) cout << "(T) trigger_assign_exception(" << after << ")\n";
	assign_exception_count = assign_count + after;
	assign_exception_enabled = true;
}

#endif /* TEST_ELEMENT_H_ */
