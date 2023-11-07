#include <boost/lexical_cast.hpp>
#include <locale>
#include <algorithm>
int main() {
  char chars[] = {'1', '0', '0'};
  int i = boost::lexical_cast<int>(chars, 3);
  assert(i == 100);
  // std::locale::global(std::locale("ru_RU.UTF8"));
  // // in Rusia comman sign is used as a decimal separator
  // float f = boost::lexical_cast<float>("1,0");
  // assert(f < 1.01 && f > 0.99);
}
