// HLP2
// 02/07/2022
// Intro to class design and implementation by designing and
// implementing class Str that will encapsulate a C-string ...
// This driver contains facilities to continually test the
// interface functions as they're added to class Str ...
// compile/link: g++ -std=c++17 str.cpp str-driver.cpp -o str.out

#include "str.hpp"
#include <iostream>

// convert lower-case characters to upper-case ...
void make_upper(hlp2::Str &rhs) {
  hlp2::Str::size_type str_len = rhs.size();
  for (hlp2::Str::size_type i{}; i < str_len; ++i) {
    rhs[i] = (rhs[i] >= 'a' && rhs[i] <= 'z') ? (rhs[i]-'a')+'A' : rhs[i];
  }
}

void foo() {
  hlp2::Str str1; // default initialization
  hlp2::Str const str2{"Clint"}; // single-argument initialization (char const*)
  hlp2::Str str3{str2}; // copy construction
  hlp2::Str str4 = hlp2::Str("Eastwood");

  str1 = str2;
  str1 += " ";
  str1 += str4;
  str1 += " is an actor!!!";

  str1 = str2;
  str1 = str4 + " is an actor!!!";
  
  make_upper(str3);
  std::cout << "str1: " << str1 << " | str2: " << str2 << " | str3: " << str3 << "\n";
}

void boo() {
  foo();
}

int main() {
  boo();

}