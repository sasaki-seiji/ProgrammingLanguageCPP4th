/*
 * ostreambuf_iterator.cpp
 *
 *  Created on: 2016/12/29
 *      Author: sasaki
 */


// ostreambuf_iterator example
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::ostreambuf_iterator
#include <string>       // std::string
#include <algorithm>    // std::copy
using namespace std;

template <class charT=char, class traits=char_traits<charT> >
  class my_ostreambuf_iterator :
    public iterator<output_iterator_tag, charT,
                    typename traits::off_type, charT*, charT&>
{
public:
  typedef charT char_type;
  typedef traits traits_type;
  typedef typename traits::int_type int_type;
  typedef basic_streambuf<charT,traits> streambuf_type;
  typedef basic_ostream<charT,traits> ostream_type;

  my_ostreambuf_iterator(ostream_type& s) throw(): sbuf_(s.rdbuf()) { }
  my_ostreambuf_iterator(streambuf_type* s) throw(): sbuf_(s) { }
  my_ostreambuf_iterator& operator= (charT c)
  { if (!failed()) last=sbuf_->sputc(c); return *this; }

  my_ostreambuf_iterator& operator*() { return *this; }
  my_ostreambuf_iterator& operator++() { return *this; }
  my_ostreambuf_iterator& operator++(int) { return *this;}

  bool failed() const throw() { return last==traits::eof(); }

private:
  streambuf_type* sbuf_;
  charT last;

};

int test_ostreambuf_iterator () {
  std::string mystring ("Some text here...\n");
  std::ostreambuf_iterator<char> out_it (std::cout); // stdout iterator

  std::copy ( mystring.begin(), mystring.end(), out_it);

  return 0;
}

int test_my_ostreambuf_iterator () {
  std::string mystring ("Some text here...\n");
  my_ostreambuf_iterator<char> out_it (std::cout); // stdout iterator

  std::copy ( mystring.begin(), mystring.end(), out_it);

  return 0;
}

int main()
{
	test_ostreambuf_iterator();
	test_my_ostreambuf_iterator();
}
