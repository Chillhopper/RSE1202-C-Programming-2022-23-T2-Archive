// RSE1202: illustrating function templates [review of previous week]
// and introducing non-type template parameters.

#include <iostream>
#include <string>
#include <array>

template <typename T>
int compare(T const& lhs, T const& rhs) {
  if (lhs < rhs) return -1;
  if (rhs < lhs) return 1;
  return 0;
}
int compare(std::string const&lhs,std::string const&rhs)
{
  if (lhs < rhs) return -1;
  if (rhs < lhs) return 1;
  return 0;
}
int main() {
  
  std::cout << compare(1, 2) << "\n";
  std::cout << compare(2, 1) << "\n";
  std::cout << compare(2, 2) << "\n";

  std::string math{"math"}, mathematics{"mathematics"};
  std::cout << compare(math, mathematics) << "\n";
  std::cout << compare(mathematics, math) << "\n";
  std::cout << compare(math, std::string{"math"}) << "\n";

  char const literal1[]{"math"}, literal2[]{"mathematics"};
  std::cout<<compare(literal1, literal2);

}
