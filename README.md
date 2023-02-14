# v23
[![language c++](https://img.shields.io/badge/language-c++-purple?style=flat-square)](https://en.wikipedia.org/wiki/C++) [![license GPLv3](https://img.shields.io/badge/license-GPLv3-orange?style=flat-square)](https://www.gnu.org/licenses/gpl-3.0.en.html) ![testing passing](https://img.shields.io/badge/test-passing-brightgreen?style=flat-square)
 
 A library for c++23 standard on gnu/linux.

## Why did I make this?

 I was working on another project when I came to the realization that g++ 12.0.2 doesn't support some of the things that msvc does when it comes to c++23 && c++2a. I decided to make my own headers to fill in for where g++ couldn't support some c++ library functionality (std::format, std::flat_map, std::flat_multimap, etc).

 *Reminder, this shouldn't be used as a dependency it is highly unstable and is barely tested.*
