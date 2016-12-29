/*
 * istreambuf_iterator.cpp
 *
 *  Created on: 2016/12/29
 *      Author: sasaki
 */


// istreambuf_iterator example
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::istreambuf_iterator
#include <string>       // std::string
using namespace std;


template <class charT=char, class traits=char_traits<charT> >
  class my_istreambuf_iterator :
    public iterator<input_iterator_tag, charT,
                    typename traits::off_type, charT*, charT&>
{
public:
  typedef charT char_type;
  typedef traits traits_type;
  typedef typename traits::int_type int_type;
  typedef basic_streambuf<charT,traits> streambuf_type;
  typedef basic_istream<charT,traits> istream_type;

  class proxy {
    charT keep_; streambuf_type* sbuf_;
  public:
    proxy (charT c, streambuf_type* sbuf) : keep_(c), sbuf_(sbuf) { }
    charT operator*() {return keep_;}
  };

  my_istreambuf_iterator() throw() : sbuf_(0) { }
  my_istreambuf_iterator(istream_type& s) throw(): sbuf_(s.rdbuf()) { }
  my_istreambuf_iterator(streambuf_type* s) throw(): sbuf_(s) { }
  my_istreambuf_iterator(const proxy& p) throw(): sbuf_(p.sbuf_) { }

  charT operator*() const { return sbuf_->sgetc(); }
  my_istreambuf_iterator<charT,traits>& operator++() { sbuf_->sbumpc(); return *this; }
  proxy operator++(int) {return proxy(sbuf_->sbumpc(),sbuf_);}

  bool equal (my_istreambuf_iterator& b) const {
    if ( sbuf_==0 || *(*this)==traits::eof() )
    { if ( b.sbuf_==0 || *b==traits::eof() ) return true; }
    else if ( b.sbuf_!=0 && *b!= traits::eof() ) return true;
    return false;
  }

private:
  streambuf_type* sbuf_;

};

template <class charT, class traits >
bool operator==(my_istreambuf_iterator<charT,traits>& a,
				my_istreambuf_iterator<charT,traits>& b)
{
	return a.equal(b);
}

template <class charT, class traits >
bool operator!=(my_istreambuf_iterator<charT,traits>& a,
				my_istreambuf_iterator<charT,traits>& b)
{
	return !a.equal(b);
}


int test_istreambuf_iterator () {
  std::istreambuf_iterator<char> eos;                    // end-of-range iterator
  std::istreambuf_iterator<char> iit (std::cin.rdbuf()); // stdin iterator
  std::string mystring;

  std::cout << "Please, enter your name: ";
  std::cout << std::flush; // 2016.12.29 add

  while (iit!=eos && *iit!='\n') mystring+=*iit++;

  std::cout << "Your name is " << mystring << ".\n";

  return 0;
}

int test_my_istreambuf_iterator () {
  my_istreambuf_iterator<char> eos;                    // end-of-range iterator
  my_istreambuf_iterator<char> iit (std::cin.rdbuf()); // stdin iterator
  std::string mystring;

  std::cout << "Please, enter your name: ";
  std::cout << std::flush; // 2016.12.29 add

  while (iit!=eos && *iit!='\n') mystring+=*iit++;

  std::cout << "Your name is " << mystring << ".\n";

  return 0;
}

int main()
{
	//test_istreambuf_iterator();
	test_my_istreambuf_iterator();
}
