#include "json.hpp"

#include <iostream>
#include <fstream>
#include <iterator>
using namespace JSON

int main(int argc, char* argv[])
{
  if (argc < 2)
    return 1;

  // Read an input file into a string.
  std::ifstream ifs(argv[1]);
  std::istreambuf_iterator<char> first(ifs);
  std::istreambuf_iterator<char> last;
  std::string str(first, last);

  value* val = parse(str);
  val->print();
}
