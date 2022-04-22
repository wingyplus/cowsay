// SPDX-License-Identifier: MIT

#include <cowsay/cowsay.h>
#include <gflags/gflags.h>

#include <iostream>
#include <ostream>
#include <string>

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
  cowsay::say(std::cout, FLAGS_quote, {.eyes = FLAGS_eyes});
  return 0;
}
