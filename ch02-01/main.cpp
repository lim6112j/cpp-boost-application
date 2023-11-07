#include <algorithm>
#include <vector>
#include <iterator>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <set>
#include <deque>

template <class ContainerT>
std::vector<long int> container_to_longs(const ContainerT& container) {
  typedef typename ContainerT::value_type value_type;
  std::vector<long int> ret;
  typedef long int (*func_t) (const value_type&);
  func_t f = &boost::lexical_cast<long int, value_type>;
  std::transform(container.begin(), container.end(), std::back_inserter(ret), f);
  return ret;
}
int main() {
  std::set<std::string> str_set;
  str_set.insert("1");
  assert(container_to_longs(str_set).front() == 1);
  std::deque<const char*> char_deque;
  char_deque.push_front("1");
  char_deque.push_back("2");
  // std::cout << container_to_longs(char_deque).front() << std::endl;
  assert(container_to_longs(char_deque).front() == 1);
  assert(container_to_longs(char_deque).back() == 2);

  typedef boost::array<unsigned char, 2> element_t;
  boost::array<element_t, 2> arrays = {{{{'1', '0'}}, {{'2', '0'}}}};
}
