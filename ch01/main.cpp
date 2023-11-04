#include <boost/program_options.hpp>
#include <boost/program_options/errors.hpp>
#include <iostream>
namespace opt = boost::program_options;
using namespace std;

int main(int argc, char *argv[]) {
  opt::options_description desc("All options");
  desc.add_options()
    ("apples, a", opt::value<int>() -> default_value(10), "how many apples do you have")
    ( "oranges, o", opt::value<int>(), "how many oranges do you have")
    ( "name", opt::value<string>(), "your name")
    ("help", "produce help message");
  opt::variables_map vm;
  opt::store(opt::parse_command_line(argc, argv, desc), vm);
  opt::notify(vm);
  if (vm.count("help")) {
    cout << desc << "\n";
    return 1;
  }
  try {
    opt::store(opt::parse_config_file("apples_oranges.cfg", desc), vm);
  } catch (const opt::reading_file &e) {
    cout << "failed to open cfg file" << e.what();
  }
  opt::notify(vm);
  if (vm.count("name")) {
    cout << "Hi, " << vm["name"].as<string>() << "!\n";
  }
  cout << "Fruits count: " << vm["apples"].as<int>() + vm["oranges"].as<int>()
       << endl;
  return 0;
}
