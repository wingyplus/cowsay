// SPDX-License-Identifier: MIT

#include <cowsay/cowsay.h>
#include <gtest/gtest.h>

TEST(Cowsay, say_print_text) {
  const std::string expected =
      " _______\n"
      "< Hello >\n"
      " -------\n"
      "        \\    ^__^\n"
      "         \\   (oo)\\_______\n"
      "             (__)\\       )\\/\\\n"
      "                 ||----w |\n"
      "                 ||     ||\n\n";
  std::stringstream ss;
  cowsay::say(ss, "Hello", {.eyes = "oo"});

  EXPECT_STREQ(expected.c_str(), ss.str().c_str());
}

TEST(Cowsay, say_custom_eye) {
  const std::string expected =
      " _______\n"
      "< Hello >\n"
      " -------\n"
      "        \\    ^__^\n"
      "         \\   (@-)\\_______\n"
      "             (__)\\       )\\/\\\n"
      "                 ||----w |\n"
      "                 ||     ||\n\n";
  std::stringstream ss;
  cowsay::say(ss, "Hello", {.eyes = "@-"});

  EXPECT_STREQ(expected.c_str(), ss.str().c_str());
}