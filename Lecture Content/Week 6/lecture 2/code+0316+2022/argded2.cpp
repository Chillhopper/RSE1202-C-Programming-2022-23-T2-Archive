// HLP2: argdep2.cpp illustrates template argument deduction performed by
// C++ compilers when the function template has a function parameter
// type that is neither a pointer nor a reference.
// The explanation can be found in the handout on template argument deduction.

#include <iostream>
#include <string>

/*
CASE B: function parameter type is neither pointer nor reference!!!
template <typename T>
void foo(FuncParamType param);
*/

// case 1: FuncParamType is T
template <typename T>
void foo(T param) { 
  std::cout << __PRETTY_FUNCTION__ << '\n';
}

int main() {
  int x{11};
  int& rx{x};
  int const  cx{x};
  int const& rcx{x};
  int* px{&x};
  int const* pcx{&x};
  int * const cpx{&x};
  int const * const cpcx{&x};
  foo(x);    // T == int
  foo(rx);   // T == int
  foo(cx);   // T == int
  foo(rcx);  // T == int
  foo(px);   // T == int*
  foo(pcx);  // T == int const*
  foo(cpx);  // T == int*
  foo(cpcx); // T == int const*

  // when a static array is passed to a function that doesn't have a
  // reference parameter, the compiler will convert the array name
  // to a pointer to first element
  int ai[]{1,2};
  int const aci[]{11,12};
  foo(ai);  // T == int*
  foo(aci); // T == int const* 
}
