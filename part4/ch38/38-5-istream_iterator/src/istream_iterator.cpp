/*
 * istream_iterator.cpp
 *
 *  Created on: 2016/12/30
 *      Author: sasaki
 */


// istream_iterator example
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::istream_iterator
using namespace std;

template <class T, class charT=char, class traits=char_traits<charT>, class Distance=ptrdiff_t>
  class my_istream_iterator :
    public iterator<input_iterator_tag, T, Distance, const T*, const T&>
{
  basic_istream<charT,traits>* in_stream;
  T value;

public:
  typedef charT char_type;
  typedef traits traits_type;
  typedef basic_istream<charT,traits> istream_type;
  my_istream_iterator() : in_stream(0) {}
  my_istream_iterator(istream_type& s) : in_stream(&s) { ++*this; }
  my_istream_iterator(const istream_iterator<T,charT,traits,Distance>& x)
    : in_stream(x.in_stream), value(x.value) {}
  ~my_istream_iterator() {}

  const T& operator*() const { return value; }
  const T* operator->() const { return &value; }
  my_istream_iterator<T,charT,traits,Distance>& operator++() {
    if (in_stream && !(*in_stream >> value)) in_stream=0;
    return *this;
  }
  my_istream_iterator<T,charT,traits,Distance> operator++(int) {
    my_istream_iterator<T,charT,traits,Distance> tmp = *this;
    ++*this;
    return tmp;
  }

  // 2016.12.30 add
  bool equal (my_istream_iterator& b) const {
    if ( in_stream==0 )
    { if ( b.in_stream==0 ) return true; }
    else if ( b.in_stream!=0 ) return true;
    return false;
  }

};

//2016.12.30 add

template <class T, class charT=char, class traits=char_traits<charT>, class Distance=ptrdiff_t>
bool operator==(my_istream_iterator<T, charT, traits, Distance>& a,
				my_istream_iterator<T, charT, traits, Distance>& b)
{
	return a.equal(b);
}

template <class T, class charT=char, class traits=char_traits<charT>, class Distance=ptrdiff_t>
bool operator!=(my_istream_iterator<T, charT, traits, Distance>& a,
				my_istream_iterator<T, charT, traits, Distance>& b)
{
	return !a.equal(b);
}


int test_istream_iterator () {
  double value1, value2;
  std::cout << "Please, insert two values: ";

  std::istream_iterator<double> eos;              // end-of-stream iterator
  std::istream_iterator<double> iit (std::cin);   // stdin iterator

  if (iit!=eos) value1=*iit;

  ++iit;
  if (iit!=eos) value2=*iit;

  std::cout << value1 << "*" << value2 << "=" << (value1*value2) << '\n';

  return 0;
}

int test_my_istream_iterator () {
  double value1, value2;
  std::cout << "Please, insert two values: ";

  my_istream_iterator<double> eos;              // end-of-stream iterator
  my_istream_iterator<double> iit (std::cin);   // stdin iterator

  if (iit!=eos) value1=*iit;

  ++iit;
  if (iit!=eos) value2=*iit;

  std::cout << value1 << "*" << value2 << "=" << (value1*value2) << '\n';

  return 0;
}

int main()
{
	test_istream_iterator();
	test_my_istream_iterator();
}
