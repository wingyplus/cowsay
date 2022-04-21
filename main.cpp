// SPDX-License-Identifier: MIT

#include <iostream>
#include <ostream>
#include <string>
#include <unicode/display_width.hpp>
#include <gflags/gflags.h>

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

DEFINE_string(quote, "", "Cowsay think..");

int main(int argc, char *argv[]) {
  gflags::SetUsageMessage("cowsay --quote [message]");
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  say(FLAGS_quote, std::cout);
  return 0;
}
