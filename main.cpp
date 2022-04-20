// SPDX-License-Identifier: MIT

#include <iostream>
#include <ostream>
#include <string>
#include <unicode/display_width.hpp>

const char TOP_BAR = '_';
const char BOTTOM_BAR = '-';
const char NEW_LINE = '\n';
const char SPACE = ' ';
const char COW[] =
    "        \\    ^__^\n"
    "         \\   (oo)\\_______\n"
    "             (__)\\       )\\/\\\n"
    "                 ||----w |\n"
    "                 ||     ||\n";

void say(const std::string &input, std::ostream &os) {
  auto len = unicode::display_width(input);
  std::string top_bar(len + 2, TOP_BAR);
  std::string bottom_bar(len + 2, BOTTOM_BAR);

  os << SPACE << top_bar << NEW_LINE;
  os << "< " << input << " >" << NEW_LINE;
  os << SPACE << bottom_bar << NEW_LINE;
  os << COW << NEW_LINE;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Expected at least 1 text." << std::endl;
    std::exit(1);
  }

  say(std::string(argv[1]), std::cout);
  return 0;
}
