template <class CharT>
std::basic_ostream<CharT>& operator<<(std::basic_ostream<CharT>& os, const negative_number& num)
{
  os << static_cast<CharT>('-') << num.value_without_sign();
  return os;
}
template <class CharT>
std::basic_istream<CharT>& operator>>(std::basic_istream<CharT>& is, negative_number& num)
{
  CharT ch;
  is >> ch;
  if (ch != static_cast<CharT>('-')) {
    throw std::logic_error("negative_number class designed to "
        " store Only negative values");
  }
  unsigned short s;
  is >> s;
  num = negative_number(s);
  return is;
}
int main() {
  negative_number n = boost::lexical_cast<negative_number>(L"-1");
  assert(n.value_without_sign() == 1);
  
}
