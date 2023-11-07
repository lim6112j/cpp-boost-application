#include <iosfwd>
#include <stdexcept>
#include <boost/lexical_cast.hpp>
#include <assert.h>
class negative_number {
  unsigned short number_;
  public:
    negative_number() {}
    explicit negative_number(unsigned short number) : number_(number) {}
    unsigned short value_without_sign() const {
      return number_;
    }
};

std::ostream& operator<<(std::ostream& os, const negative_number& num)
{
  os << '-' << num.value_without_sign();
  return os;
}
std::istream& operator>>(std::istream& is, negative_number& num) 
{
  char ch;
  is >> ch;
  if (ch != '-') {
    throw std::logic_error("negative_number class designed to store store ONLY negative values");
  }
  unsigned short s;
  is >> s;
  num = negative_number(s);
  return is;
}
int main()
{
  negative_number n = boost::lexical_cast<negative_number>("-100");
  assert(n.value_without_sign() == 100);
  int i = boost::lexical_cast<int>(n);
  assert(i == -100);
  typedef boost::array<char, 10> arr_t;
  arr_t arr = boost::lexical_cast<arr_t>(n);
  assert(arr[0] == '-');
  assert(arr[1] == '1');
  assert(arr[2] == '0');
  assert(arr[3] == '0');
  assert(arr[4] == '\0');
}
