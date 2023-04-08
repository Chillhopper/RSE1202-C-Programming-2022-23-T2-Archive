// HLP2: argdep.cpp illustrates template argument deduction performed by
// C++ compilers when the function template has a function parameter
// type that is a pointer or reference.
// The explanation can be found in the handout on template argument deduction.

#include <iostream>
#include <string>

/*
CASE A: function parameter type is pointer or reference!!!
template <typename T>
void foo(FuncParamType param);
*/

// case 1: FuncParamType is T&
template <typename T>
void foo(T& param) { std::cout << __PRETTY_FUNCTION__ << '\n'; }

// case 2: FuncParamType is T const&
template <typename T>
void foo2(T const& param) { std::cout << __PRETTY_FUNCTION__ << '\n'; }

// case 3: FuncParamType is T*
template <typename T>
void foo3(T* param) {  std::cout << __PRETTY_FUNCTION__ << '\n'; }

// case 4: FuncParamType is T const*
template <typename T> void foo4(T const* param) {   
  std::cout << __PRETTY_FUNCTION__ << '\n';
}

int main() {
  int x{1};
  int& rx{x};
  int const cx{x};
  int const& rcx{x};

  // Don't forget that foo takes a reference in your thinking!!!
  foo(x);    // T == int and param == int& 
  foo(rx);   // T == int and param == int& 
  foo(cx);   // T == int const and param == int const&
  foo(rcx);  // T == int const and param == int const&

  foo2(x);   // T == int and param == int const&
  foo2(rx);  // T == int and param == int const&
  foo2(cx);  // T == int and param == int const&
  foo2(rcx); // T == int and param == int const& 

  foo3(&x);   // T == int and param == int*
  foo3(&rx);  // T == int and param == int*  
  foo3(&cx);  // T == int const* and param == int const*
  foo3(&rcx); // T == int const* and param == int const*

  foo4(&x);   // T == int and param == int const*
  foo4(&rx);  // T == int and param == int const*
  foo4(&cx);  // T == int and param == int const*
  foo4(&rcx);  // T == int and param == int const*

  // when a static array is specified as argument to a function that takes
  // a reference, the compiler will not convert the array name to a pointer-to-first-
  // element of array!!!
  int ai[2] {1, 2};
  int const aci[]{1, 2};

  foo(ai);  // T == int[2] and param == int (&)[2]
  foo(aci); // T == int const [2] and param == int const (&)[2]

  foo2(ai);  // T == int[2] and param == int const (&)[2]
  foo2(aci); // T == int[2] and param == int const (&)[2]

  foo3(ai);  // T == int and param == int*
  foo3(aci); // T == int const and param == int const*

  foo4(ai);  // T == int and param == int const*
  foo4(aci); // T == int and param == int const*
}