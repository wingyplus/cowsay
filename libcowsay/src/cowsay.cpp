// SPDX-License-Identifier: MIT

#include <cowsay/cowsay.h>

#include <ostream>
#include <unicode/display_width.hpp>

static const char TOP_BAR = '_';
static const char BOTTOM_BAR = '-';
static const char NEW_LINE = '\n';
static const char SPACE = ' ';
static const char COW[] =
    "        \\    ^__^\n"
    "         \\   (@e)\\_______\n"
    "             (__)\\       )\\/\\\n"
    "                 ||----w |\n"
    "                 ||     ||\n";

void cowsay::say(std::ostream &os, const std::string &input,
                 const cowsay::CowComponent &component) {
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