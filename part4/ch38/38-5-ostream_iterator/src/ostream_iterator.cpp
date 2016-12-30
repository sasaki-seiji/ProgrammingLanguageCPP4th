/*
 * ostream_iterator.cpp
 *
 *  Created on: 2016/12/30
 *      Author: sasaki
 */


// ostream_iterator example
#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>    // std::copy
using namespace std;

template <class T, class charT=char, class traits=char_traits<charT> >
  class my_ostream_iterator :
    public iterator<output_iterator_tag, void, void, void, void>
{
  basic_ostream<charT,traits>* out_stream;
  const charT* delim;

public:
  typedef charT char_type;
  typedef traits traits_type;
  typedef basic_ostream<charT,traits> ostream_type;
  my_ostream_iterator(ostream_type& s) : out_stream(&s), delim(0) {}
  my_ostream_iterator(ostream_type& s, const charT* delimiter)
    : out_stream(&s), delim(delimiter) { }
  my_ostream_iterator(const ostream_iterator<T,charT,traits>& x)
    : out_stream(x.out_stream), delim(x.delim) {}
  ~my_ostream_iterator() {}

  my_ostream_iterator<T,charT,traits>& operator= (const T& value) {
    *out_stream << value;
    if (delim!=0) *out_stream << delim;
    return *this;
  }

  my_ostream_iterator<T,charT,traits>& operator*() { return *this; }
  my_ostream_iterator<T,charT,traits>& operator++() { return *this; }
  my_ostream_iterator<T,charT,traits>& operator++(int) { return *this; }
};

int test_ostream_iterator() {
  std::vector<int> myvector;
  for (int i=1; i<10; ++i) myvector.push_back(i*10);

  std::ostream_iterator<int> out_it (std::cout,", ");
  std::copy ( myvector.begin(), myvector.end(), out_it );
  return 0;
}

int test_my_ostream_iterator() {
  std::vector<int> myvector;
  for (int i=1; i<10; ++i) myvector.push_back(i*10);

  my_ostream_iterator<int> out_it (std::cout,", ");
  std::copy ( myvector.begin(), myvector.end(), out_it );
  return 0;
}

int main()
{
	test_ostream_iterator();
	std::cout << endl;
	test_my_ostream_iterator();
}
