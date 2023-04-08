// HLP2
// 02/07/2022
// Intro to class design and implementation by designing and
// implementing class Str that will encapsulate a C-string ...
// Implementation file that contains definitions of member
// function declared in class Str [in interface file str.hpp] ...

#include "str.hpp"
#include <cstring>
#include <iostream>

namespace hlp2 {

Str::Str() : len{0}, ptr{new char[len+1]{'\0'}} {
  // empty by design ...
  std::cout << __PRETTY_FUNCTION__ << '\n';
}

Str::Str(char const *rhs) : len{std::strlen(rhs)}, ptr{new char [len+1]} {
  std::strcpy(ptr, rhs);
  std::cout << __PRETTY_FUNCTION__ << '\n';
}

Str::Str(Str const& rhs) : len{rhs.len}, ptr{new char [len+1]} {
  std::strcpy(ptr, rhs.ptr);
  std::cout << __PRETTY_FUNCTION__ << '\n';
}

Str::~Str() {
  std::cout << __PRETTY_FUNCTION__ << " : ptr: " << ptr << '\n';
  delete[] ptr;
}

Str& Str::operator=(Str const& rhs) {
  Str::size_type tmp_len {rhs.len};
  Str::pointer tmp_ptr { new char [tmp_len+1] };
  std::strcpy(tmp_ptr, rhs.ptr);

  len = tmp_len;
  delete[] ptr;
  ptr = tmp_ptr;

  return *this;
}

Str& Str::operator=(char const* rhs) {
  Str::size_type tmp_len {std::strlen(rhs)};
  Str::pointer tmp_ptr {new char [tmp_len+1]};
  std::strcpy(tmp_ptr, rhs);

  len = tmp_len;
  delete[] ptr;
  ptr = tmp_ptr;

  return *this;
}

Str& Str::operator+=(Str const& rhs) {
  Str::size_type tmp_len {len + rhs.len};
  Str::pointer tmp_ptr {new char [tmp_len+1]};
  std::strcpy(tmp_ptr, ptr); std::strcat(tmp_ptr, rhs.ptr);

  len = tmp_len;
  delete[] ptr;
  ptr = tmp_ptr;
  return *this;
}

Str& Str::operator+=(char const *rhs) {
  Str::size_type tmp_len {len+std::strlen(rhs)};
  Str::pointer tmp_ptr{new char [tmp_len+1]};
  std::strcpy(tmp_ptr, ptr); std::strcat(tmp_ptr, rhs);

  len = tmp_len;
  delete[] ptr;
  ptr = tmp_ptr;
  return *this;
}

Str operator+(Str const& lhs, Str const& rhs) {
  Str result{lhs}; // copy construction
  result += rhs;   // invoke result.op+=(rhs)
  return result;   // return result
}

Str operator+(Str const& lhs, char const *rhs) {
  Str result{lhs};
  result += rhs;
  return result;
}

Str operator+(char const *lhs, Str const& rhs) {
  Str result{lhs}; // single-argument ctor
  result += rhs;
  return result;
}

Str::reference Str::operator[](Str::size_type idx) {
  return ptr[idx];
}

Str::const_reference Str::operator[](Str::size_type idx) const {
  return ptr[idx];
}

bool Str::empty() const {
  return len==0 ? true : false;
}

size_t Str::size() const {
  return this->len;
}

char const* Str::c_str() const {
  return ptr;
}

std::ostream& operator<<(std::ostream& os, Str const& rhs) {
  os << rhs.c_str();
  return os;
}



} // end namespace hlp2