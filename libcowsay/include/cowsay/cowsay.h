// SPDX-License-Identifier: MIT

#ifndef COWSAY_COWSAY_H
#define COWSAY_COWSAY_H

#include <ostream>
#include <string>

namespace cowsay {

struct CowComponent {
  std::string eyes;
};

void say(std::ostream &, const std::string &, const CowComponent &);
}  // namespace cowsay

#endif  // COWSAY_COWSAY_H
