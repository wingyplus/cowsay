// SPDX-License-Identifier: MIT

#include <gflags/gflags.h>

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
    "         \\   (@e)\\_______\n"
    "             (__)\\       )\\/\\\n"
    "                 ||----w |\n"
    "                 ||     ||\n";

struct CowComponent {
  std::string eyes;
};

void say(std::ostream &os, const std::string &input,
         const CowComponent &component) {
  auto len = unicode::display_width(input);
  std::string top_bar(len + 2, TOP_BAR);
  std::string bottom_bar(len + 2, BOTTOM_BAR);

  auto cow = std::string(COW);
  auto eyes_pos = cow.find("@e");

  os << SPACE << top_bar << NEW_LINE;
  os << "< " << input << " >" << NEW_LINE;
  os << SPACE << bottom_bar << NEW_LINE;
  os << cow.replace(eyes_pos, 2, component.eyes) << NEW_LINE;
}

static bool validate_eyes(const char *flagname, const std::string &eyes) {
  if (eyes.length() != 2) {
    std::cerr << "Eyes must have 2 eyes not " << eyes.length() << std::endl;
    return false;
  }
  return true;
}

DEFINE_string(quote, "", "Cowsay think..");
DEFINE_string(eyes, "oo", "Custom cow eye");
DEFINE_validator(eyes, &validate_eyes);

int main(int argc, char *argv[]) {
  gflags::SetUsageMessage("cowsay --quote message [--eyes eye]");
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  say(std::cout, FLAGS_quote, {.eyes = FLAGS_eyes});
  return 0;
}
