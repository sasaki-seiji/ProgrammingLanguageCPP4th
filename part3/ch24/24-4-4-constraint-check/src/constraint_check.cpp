/*
 * constraint_check.cpp
 *
 *  Created on: 2016/10/25
 *      Author: sasaki
 */

#include "concept.h"
using namespace Estd;

#include <iterator>
#include <forward_list>
#include <list>
#include <vector>
#include <string>
#include <complex>
#include <array>
#include <memory>

#include <typeinfo>
#include <iostream>
using std::cout;

struct Base { };
struct Derived : public Base { };

struct Call_i {
	int operator()(int x) { return x; }
};

void test_input_iterator()
{
	cout << "--- test for Input_iterator ---\n";
	cout << "Input_iterator<std::istream_iterator<char>>(): "
			<< Input_iterator<std::istream_iterator<char>>() << '\n';
	cout << "Input_iterator<std::ostream_iterator<char>>(): "
			<< Input_iterator<std::ostream_iterator<char>>() << '\n';
	cout << "Input_iterator<std::forward_list<int>::const_iterator>(): "
			<< Input_iterator<std::forward_list<int>::const_iterator>() << '\n';
	cout << "Input_iterator<std::forward_list<int>::iterator>(): "
			<< Input_iterator<std::forward_list<int>::iterator>() << '\n';
	cout << "Input_iterator<std::list<int>::const_iterator>(): "
			<< Input_iterator<std::list<int>::const_iterator>() << '\n';
	cout << "Input_iterator<std::list<int>::iterator>(): "
			<< Input_iterator<std::list<int>::iterator>() << '\n';
	cout << "Input_iterator<std::vector<std::string>::const_iterator>(): "
			<< Input_iterator<std::vector<std::string>::const_iterator>() << '\n';
	cout << "Input_iterator<std::vector<std::string>::iterator>(): "
			<< Input_iterator<std::vector<std::string>::iterator>() << '\n';
	cout << "Input_iterator<const int*>(): "
			<< Input_iterator<const int*>() << '\n';
	cout << "Input_iterator<int*>(): "
			<< Input_iterator<int*>() << '\n';
	cout << "Input_iterator<int>(): "
			<< Input_iterator<int>() << '\n';
}

void test_output_iterator()
{
	cout << "--- test for Output_iterator ---\n";
#if 0 // debug
	cout << "Common_iterator<std::ostream_iterator<char>>(): " << Common_iterator<std::ostream_iterator<char>>() << '\n';
	cout << "Has_value_type<std::ostream_iterator<char>>(): " << Has_value_type<std::ostream_iterator<char>>() << '\n';
	cout << "Has_iterator_category<std::ostream_iterator<char>>(): " << Has_iterator_category<std::ostream_iterator<char>>() << '\n';
	cout << "Default_constructible<std::ostream_iterator<char>>(): " << Default_constructible<std::ostream_iterator<char>>() << '\n';
	cout << "Has_pre_increment<std::ostream_iterator<char>>(): " << Has_pre_increment<std::ostream_iterator<char>>() << '\n';
	cout << "Assignable<Dereference_result<std::ostream_iterator<char>>,char>(): " << Assignable<Dereference_result<std::ostream_iterator<char>>,char>() << '\n';
	cout << "typeid(Dereference_result<std::ostream_iterator<char>>).name(): " << typeid(Dereference_result<std::ostream_iterator<char>>).name() << '\n';
	cout << "Has_dereference<std::ostream_iterator<char>>(): " << Has_dereference<std::ostream_iterator<char>>() << '\n';
#endif
	cout << "Output_iterator<std::istream_iterator<char>,char>(): "
			<< Output_iterator<std::istream_iterator<char>,char>() << '\n';
	cout << "Output_iterator<std::ostream_iterator<char>,char>(): "
			<< Output_iterator<std::ostream_iterator<char>,char>() << '\n';
	cout << "Output_iterator<std::forward_list<int>::const_iterator,int>(): "
			<< Output_iterator<std::forward_list<int>::const_iterator,int>() << '\n';
	cout << "Output_iterator<std::forward_list<int>::iterator,int>(): "
			<< Output_iterator<std::forward_list<int>::iterator,int>() << '\n';
	cout << "Output_iterator<std::list<int>::const_iterator,int>(): "
			<< Output_iterator<std::list<int>::const_iterator,int>() << '\n';
	cout << "Output_iterator<std::list<int>::iterator,int>(): "
			<< Output_iterator<std::list<int>::iterator,int>() << '\n';
	cout << "Output_iterator<std::vector<std::string>::const_iterator,std::string>(): "
			<< Output_iterator<std::vector<std::string>::const_iterator,std::string>() << '\n';
	cout << "Output_iterator<std::vector<std::string>::iterator,std::string>(): "
			<< Output_iterator<std::vector<std::string>::iterator,std::string>() << '\n';
	cout << "Output_iterator<const int*>(): "
			<< Output_iterator<const int*, int>() << '\n';
	cout << "Output_iterator<int*, int>(): "
			<< Output_iterator<int*, int>() << '\n';
	cout << "Output_iterator<int, int>(): "
			<< Output_iterator<int, int>() << '\n';
}

void test_forward_const_iterator()
{
	cout << "--- test for Forward_const_iterator ---\n";
	cout << "Forward_const_iterator<std::istream_iterator<char>>(): "
			<< Forward_const_iterator<std::istream_iterator<char>>() << '\n';
	cout << "Forward_const_iterator<std::ostream_iterator<char>>(): "
			<< Forward_const_iterator<std::ostream_iterator<char>>() << '\n';
	cout << "Forward_const_iterator<std::forward_list<int>::const_iterator>(): "
			<< Forward_const_iterator<std::forward_list<int>::const_iterator>() << '\n';
	cout << "Forward_const_iterator<std::forward_list<int>::iterator>(): "
			<< Forward_const_iterator<std::forward_list<int>::iterator>() << '\n';
	cout << "Forward_const_iterator<std::list<int>::const_iterator>(): "
			<< Forward_const_iterator<std::list<int>::const_iterator>() << '\n';
	cout << "Forward_const_iterator<std::list<int>::iterator>(): "
			<< Forward_const_iterator<std::list<int>::iterator>() << '\n';
	cout << "Forward_const_iterator<std::vector<std::string>::const_iterator>(): "
			<< Forward_const_iterator<std::vector<std::string>::const_iterator>() << '\n';
	cout << "Forward_const_iterator<std::vector<std::string>::iterator>(): "
			<< Forward_const_iterator<std::vector<std::string>::iterator>() << '\n';
	cout << "Forward_const_iterator<const int*>(): "
			<< Forward_const_iterator<const int*>() << '\n';
	cout << "Forward_const_iterator<int*>(): "
			<< Forward_const_iterator<int*>() << '\n';
	cout << "Forward_const_iterator<int>(): "
			<< Forward_const_iterator<int>() << '\n';
}

void test_forward_iterator()
{
	cout << "--- test for Forward_iterator ---\n";
	cout << "Forward_iterator<std::istream_iterator<char>>(): "
			<< Forward_iterator<std::istream_iterator<char>>() << '\n';
	cout << "Forward_iterator<std::ostream_iterator<char>>(): "
			<< Forward_iterator<std::ostream_iterator<char>>() << '\n';
	cout << "Forward_iterator<std::forward_list<int>::const_iterator>(): "
			<< Forward_iterator<std::forward_list<int>::const_iterator>() << '\n';
	cout << "Forward_iterator<std::forward_list<int>::iterator>(): "
			<< Forward_iterator<std::forward_list<int>::iterator>() << '\n';
	cout << "Forward_iterator<std::list<int>::const_iterator>(): "
			<< Forward_iterator<std::list<int>::const_iterator>() << '\n';
	cout << "Forward_iterator<std::list<int>::iterator>(): "
			<< Forward_iterator<std::list<int>::iterator>() << '\n';
	cout << "Forward_iterator<std::vector<std::string>::const_iterator>(): "
			<< Forward_iterator<std::vector<std::string>::const_iterator>() << '\n';
	cout << "Forward_iterator<std::vector<std::string>::iterator>(): "
			<< Forward_iterator<std::vector<std::string>::iterator>() << '\n';
	cout << "Forward_iterator<const int*>(): "
			<< Forward_iterator<const int*>() << '\n';
	cout << "Forward_iterator<int*>(): "
			<< Forward_iterator<int*>() << '\n';
	cout << "Forward_iterator<int>(): "
			<< Forward_iterator<int>() << '\n';
}

void test_bidirectional_const_iterator()
{
	cout << "--- test for Bidirectional_const_iterator ---\n";
	cout << "Bidirectional_const_iterator<std::istream_iterator<char>>(): "
			<< Bidirectional_const_iterator<std::istream_iterator<char>>() << '\n';
	cout << "Bidirectional_const_iterator<std::ostream_iterator<char>>(): "
			<< Bidirectional_const_iterator<std::ostream_iterator<char>>() << '\n';
	cout << "Bidirectional_const_iterator<std::forward_list<int>::const_iterator>(): "
			<< Bidirectional_const_iterator<std::forward_list<int>::const_iterator>() << '\n';
	cout << "Bidirectional_const_iterator<std::forward_list<int>::iterator>(): "
			<< Bidirectional_const_iterator<std::forward_list<int>::iterator>() << '\n';
	cout << "Bidirectional_const_iterator<std::list<int>::const_iterator>(): "
			<< Bidirectional_const_iterator<std::list<int>::const_iterator>() << '\n';
	cout << "Bidirectional_const_iterator<std::list<int>::iterator>(): "
			<< Bidirectional_const_iterator<std::list<int>::iterator>() << '\n';
	cout << "Bidirectional_const_iterator<std::vector<std::string>::const_iterator>(): "
			<< Bidirectional_const_iterator<std::vector<std::string>::const_iterator>() << '\n';
	cout << "Bidirectional_const_iterator<std::vector<std::string>::iterator>(): "
			<< Bidirectional_const_iterator<std::vector<std::string>::iterator>() << '\n';
	cout << "Bidirectional_const_iterator<const int*>(): "
			<< Bidirectional_const_iterator<const int*>() << '\n';
	cout << "Bidirectional_const_iterator<int*>(): "
			<< Bidirectional_const_iterator<int*>() << '\n';
	cout << "Bidirectional_const_iterator<int>(): "
			<< Bidirectional_const_iterator<int>() << '\n';
}

void test_bidirectional_iterator()
{
	cout << "--- test for Bidirectional_iterator ---\n";
	cout << "Bidirectional_iterator<std::istream_iterator<char>>(): "
			<< Bidirectional_iterator<std::istream_iterator<char>>() << '\n';
	cout << "Bidirectional_iterator<std::ostream_iterator<char>>(): "
			<< Bidirectional_iterator<std::ostream_iterator<char>>() << '\n';
	cout << "Bidirectional_iterator<std::forward_list<int>::const_iterator>(): "
			<< Bidirectional_iterator<std::forward_list<int>::const_iterator>() << '\n';
	cout << "Bidirectional_iterator<std::forward_list<int>::iterator>(): "
			<< Bidirectional_iterator<std::forward_list<int>::iterator>() << '\n';
	cout << "Bidirectional_iterator<std::list<int>::const_iterator>(): "
			<< Bidirectional_iterator<std::list<int>::const_iterator>() << '\n';
	cout << "Bidirectional_iterator<std::list<int>::iterator>(): "
			<< Bidirectional_iterator<std::list<int>::iterator>() << '\n';
	cout << "Bidirectional_iterator<std::vector<std::string>::const_iterator>(): "
			<< Bidirectional_iterator<std::vector<std::string>::const_iterator>() << '\n';
	cout << "Bidirectional_iterator<std::vector<std::string>::iterator>(): "
			<< Bidirectional_iterator<std::vector<std::string>::iterator>() << '\n';
	cout << "Bidirectional_iterator<const int*>(): "
			<< Bidirectional_iterator<const int*>() << '\n';
	cout << "Bidirectional_iterator<int*>(): "
			<< Bidirectional_iterator<int*>() << '\n';
	cout << "Bidirectional_iterator<int>(): "
			<< Bidirectional_iterator<int>() << '\n';
}

void test_random_access_const_iterator()
{
	cout << "--- test for Random_access_const_iterator ---\n";
	cout << "Random_access_const_iterator<std::istream_iterator<char>>(): "
			<< Random_access_const_iterator<std::istream_iterator<char>>() << '\n';
	cout << "Random_access_const_iterator<std::ostream_iterator<char>>(): "
			<< Random_access_const_iterator<std::ostream_iterator<char>>() << '\n';
	cout << "Random_access_const_iterator<std::forward_list<int>::const_iterator>(): "
			<< Random_access_const_iterator<std::forward_list<int>::const_iterator>() << '\n';
	cout << "Random_access_const_iterator<std::forward_list<int>::iterator>(): "
			<< Random_access_const_iterator<std::forward_list<int>::iterator>() << '\n';
	cout << "Random_access_const_iterator<std::list<int>::const_iterator>(): "
			<< Random_access_const_iterator<std::list<int>::const_iterator>() << '\n';
	cout << "Random_access_const_iterator<std::list<int>::iterator>(): "
			<< Random_access_const_iterator<std::list<int>::iterator>() << '\n';
	cout << "Random_access_const_iterator<std::vector<std::string>::const_iterator>(): "
			<< Random_access_const_iterator<std::vector<std::string>::const_iterator>() << '\n';
	cout << "Random_access_const_iterator<std::vector<std::string>::iterator>(): "
			<< Random_access_const_iterator<std::vector<std::string>::iterator>() << '\n';
	cout << "Random_access_const_iterator<const int*>(): "
			<< Random_access_const_iterator<const int*>() << '\n';
	cout << "Random_access_const_iterator<int*>(): "
			<< Random_access_const_iterator<int*>() << '\n';
	cout << "Random_access_const_iterator<int>(): "
			<< Random_access_const_iterator<int>() << '\n';
}

void test_random_access_iterator()
{
	cout << "--- test for Random_access_iterator ---\n";
	cout << "Random_access_iterator<std::istream_iterator<char>>(): "
			<< Random_access_iterator<std::istream_iterator<char>>() << '\n';
	cout << "Random_access_iterator<std::ostream_iterator<char>>(): "
			<< Random_access_iterator<std::ostream_iterator<char>>() << '\n';
	cout << "Random_access_iterator<std::forward_list<int>::const_iterator>(): "
			<< Random_access_iterator<std::forward_list<int>::const_iterator>() << '\n';
	cout << "Random_access_iterator<std::forward_list<int>::iterator>(): "
			<< Random_access_iterator<std::forward_list<int>::iterator>() << '\n';
	cout << "Random_access_iterator<std::list<int>::const_iterator>(): "
			<< Random_access_iterator<std::list<int>::const_iterator>() << '\n';
	cout << "Random_access_iterator<std::list<int>::iterator>(): "
			<< Random_access_iterator<std::list<int>::iterator>() << '\n';
	cout << "Random_access_iterator<std::vector<std::string>::const_iterator>(): "
			<< Random_access_iterator<std::vector<std::string>::const_iterator>() << '\n';
	cout << "Random_access_iterator<std::vector<std::string>::iterator>(): "
			<< Random_access_iterator<std::vector<std::string>::iterator>() << '\n';
	cout << "Random_access_iterator<const int*>(): "
			<< Random_access_iterator<const int*>() << '\n';
	cout << "Random_access_iterator<int*>(): "
			<< Random_access_iterator<int*>() << '\n';
	cout << "Random_access_iterator<int>(): "
			<< Random_access_iterator<int>() << '\n';
}

void test_equality_comparable()
{
	cout << "--- test for Equality_comparable ---\n";
	cout << "Equality_comparable<std::string>(): "
			<< Equality_comparable<std::string>() << '\n';
	cout << "Equality_comparable<int,double>(): "
			<< Equality_comparable<int,double>() << '\n';
	cout << "Equality_comparable<int,char*>(): "
			<< Equality_comparable<int,char*>() << '\n';
}

void test_totally_ordered()
{
	cout << "--- test for Totally_ordered ---\n";
	cout << "Totally_ordered<std::string>(): "
			<< Totally_ordered<std::string>() << '\n';
	cout << "Totally_ordered<std::complex>(): "
			<< Totally_ordered<std::complex<double>>() << '\n';
	cout << "Totally_ordered<int,double>(): "
			<< Totally_ordered<int,double>() << '\n';
}

void test_semiregular()
{
	cout << "--- test for Semiregular ---\n";
	cout << "Semiregular<std::string>(): "
			<< Semiregular<std::string>() << '\n';
	cout << "Semiregular<std::unique_ptr<int>>(): "
			<< Semiregular<std::unique_ptr<int>>() << '\n';
}

void test_regular()
{
	cout << "--- test for Regular ---\n";
	cout << "Regular<std::string>(): "
			<< Regular<std::string>() << '\n';
	cout << "Regular<std::unique_ptr<int>>(): "
			<< Regular<std::unique_ptr<int>>() << '\n';
}

void test_ordered()
{
	cout << "--- test for Ordered ---\n";
	cout << "Ordered<std::string>(): "
			<< Ordered<std::string>() << '\n';
	cout << "Ordered<std::vector<int>>(): "
			<< Ordered<std::vector<int>>() << '\n';
	cout << "Ordered<std::complex<double>>(): "
			<< Ordered<std::complex<double>>() << '\n';
}

void test_assignable()
{
	cout << "--- test for Is_assignable ---\n";
	cout << "Is_assignable<int&,int>(): "
			<< Is_assignable<int&,int>() << '\n';
	cout << "Is_ssignable<int,int>(): "
			<< Is_assignable<int,int>() << '\n';
	cout << "Is_assignable<Base*&,Derived*>(): "
			<< Is_assignable<Base*&,Derived*>() << '\n';
}

void test_predicate()
{
	cout << "--- test for Predicate ---\n";
	cout << "Predicate<void(*)(int),int>(): "
			<< Predicate<void(*)(int),int>() << '\n';
	cout << "Predicate<Call_i,int>(): "
			<< Predicate<Call_i,int>() << '\n'; // why?
	auto lambda = [](int x){ return x; };
	cout << "Predicate<decltype([](int){ }),int>(): "
			<< Predicate<decltype(lambda),int>() << '\n';
}

void test_streamable()
{
	cout << "--- test for Streamable ---\n";
	cout << "Streamable<double>(): "
			<< Streamable<double>() << '\n';
	cout << "Streamable<std::string>(): "
			<< Streamable<std::string>() << '\n';
	cout << "Streamable<std::vector<int>>(): "
			<< Streamable<std::vector<int>>() << '\n';
}

void test_movable()
{
	cout << "--- test for Movable ---\n";
	cout << "Movable<double>(): "
			<< Movable<double>() << '\n';
	cout << "Movable<std::string>(): "
			<< Movable<std::string>() << '\n';
	cout << "Movable<std::unique_ptr<int>>(): "
			<< Movable<std::unique_ptr<int>>() << '\n';
	cout << "Movable<std::type_info>(): "
			<< Movable<std::type_info>() << '\n';
}

void test_copyable()
{
	cout << "--- test for Copyable ---\n";
	cout << "Copyable<double>(): "
			<< Copyable<double>() << '\n';
	cout << "Copyable<std::string>(): "
			<< Copyable<std::string>() << '\n';
	cout << "Copyable<std::unique_ptr<int>>(): "
			<< Copyable<std::unique_ptr<int>>() << '\n';
	cout << "Copyable<std::type_info>(): "
			<< Copyable<std::type_info>() << '\n';
}

void test_convertible()
{
	cout << "--- test for Is_convertible ---\n";
	cout << "Is_convertible<double,int>(): "
			<< Is_convertible<double,int>() << '\n';
	cout << "Is_convertible<Derived*,Base*>(): "
			<< Is_convertible<Derived*,Base*>() << '\n';
	cout << "Is_convertible<Base*,Derived*>(): "
			<< Is_convertible<Base*,Derived*>() << '\n';
}

#if 0
void test_common_type()
{
	cout << "--- test for Common_type ---\n";
	cout << "typeid(Common_type<int,long>()): "
			<< typeid(Common_type<int,long>()).name() << '\n'; // what?
	cout << "typeid(Common_type<Base*,Derived*>()): "
			<< typeid(Common_type<Base*,Derived*>()).name() << '\n';
}
#endif

void test_common()
{
	cout << "--- test for Common ---\n";
	cout << "Common<int,long>(): "
			<< Common<int,long>() << '\n';
	cout << "Common<Base*,Derived*>(): "
			<< Common<Base*,Derived*>() << '\n';
	cout << "Common<const char*,std::string>(): "
			<< Common<const char*,std::string>() << '\n';
	cout << "Common<int, char*>(): "
			<< Common<int, char*>() << '\n';
}

void test_range()
{
	cout << "--- test for Range ---\n";
	cout << "Range<std::vector<int>>(): "
			<< Range<std::vector<int>>() << '\n';
	cout << "Range<std::array<int,10>>(): "
			<< Range<std::array<int,10>>() << '\n';
	cout << "Range<int(&)[10]>(): "
			<< Range<int(&)[10]>() << '\n';
}

int main()
{
	test_input_iterator();
	test_output_iterator();
	test_forward_const_iterator();
	test_forward_iterator();
	test_bidirectional_const_iterator();
	test_bidirectional_iterator();
	test_random_access_const_iterator();
	test_random_access_iterator();
	test_equality_comparable();
	test_totally_ordered();
	test_semiregular();
	test_regular();
	test_ordered();
	test_assignable();
	test_predicate();
	test_streamable();
	test_movable();
	test_copyable();
	test_convertible();
	test_common();
	test_range();
}

