// HLP2: compare.cpp illustrates how to overload function templates and how
// in certain edge cases [here the edge case is static arrays of C-strings]
// function overloading is the only solution.
// The source file also illustrates how pointers to read-only chars that
// point to C-strings cannot be handled by function template #1. One solution
// is to provide a function template specialization [using syntax template <>].
#include <iostream>
#include <string>
#include <cstring>

// to get the code to print readable function signatures in
// both g++ and Microsoft compiler
#ifdef _MSC_VER
#define PRINT_FUNC (__FUNCSIG__)
#else
#define PRINT_FUNC (__PRETTY_FUNCTION__)
#endif

// function overload #1 [this is also referred to as a base template]
// we pass by const-reference to avoid unnecessary copies!!!
template <typename T> 
int compare(T const& lhs, T const& rhs) {
  std::cout << PRINT_FUNC << "\n";
  if (lhs < rhs) return -1;
  if (rhs < lhs) return 1;
  return 0;
}

// this is a specialization of function template #1 for T == char const*
template <>
int compare(char const* const& lhs, char const* const& rhs) {
  std::cout << "Iam sure this being called: " << PRINT_FUNC << "\n";
  return std::strcmp(lhs, rhs);
}

// function overload #2 [to compare C-strings stored in static arrays
// of sizes M and N, respectively]
template <size_t M, size_t N> // base template 2
int compare(char const (&lhs)[M], char const (&rhs)[N]) {
  std::cout << PRINT_FUNC << "\n";
  return std::strcmp(lhs, rhs);
}

// function overload #3 required for g++ and clang++ [to compare C-string
// stored in static arrays of similar size M]
// Microsoft compiler doesn't require this overload for its implementation
// of function overload resolution ...
template <size_t M> // base template 3
int compare(char const (&lhs)[M], char const (&rhs)[M]) {
  std::cout << PRINT_FUNC << "\n";
  return std::strcmp(lhs, rhs);
}

#if 1
// this is a plain-old-function that is always chosen when you call the function
// with arguments of type char const*
// Such a plain-old-function is preferable to function template specialization ...
int compare(char const *lhs, char const *rhs) {
  std::cout << PRINT_FUNC << "\n";
  return std::strcmp(lhs, rhs);
}
#endif

int main() {
  std::string s1{"seattle"}, s2{"singapore"};
  std::cout << compare(s1, s2) << "\n";
  std::cout << compare(1, 2) << "\n";

  char const cstr1[] = "seattle", cstr2[] = "singapore";
  compare(cstr1, cstr2);
  char cstr3[] = "sydney", cstr4[] = "san jose";
  compare(cstr3, cstr4);

  char cstr5[] = "hello", cstr6[] = "world";
  std::cout << compare(cstr5, cstr6) << "\n";

  char const *pc1 = "seattle", *pc2 = "singapore";
  std::cout << compare(pc1, pc2) << "\n";
}