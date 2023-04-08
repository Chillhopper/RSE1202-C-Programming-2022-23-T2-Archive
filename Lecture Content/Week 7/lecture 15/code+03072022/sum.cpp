// RSE1202: illustrating function templates [review of previous week]
// and introducing non-type template parameters.

#include <iostream>
#include <string>
#include <array>
#include <utility>

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1,T2> const& rhs) {
  os << "[" << rhs.first << ", " << rhs.second << "]";
  return os;
}

template <typename T1, typename T2=double>
std::pair<T1,T2> stats(T1 const *first, T1 const *last) {
  T1 total = T1();
  size_t count{};
  while (first != last) {
    total += *first;
    ++first;
    ++count;
  }
  T2 average = (count) ? static_cast<T2>(total)/static_cast<T2>(count) : T2();
  return std::pair<T1,T2>(total, average);
}

template <typename T, size_t N>
T sum(T const (&ref_to_array)[N]) {
  T total = T();
  for (T const& x : ref_to_array) {
    total += x;
  }
  return total;
}

template <typename T>
T sum(T const *first, T const *last, T const& init_val=T()) {
  T total{init_val};
  while (first != last) {
    total += *first++;
  }
  return total;
}

int main() {
  std::array<std::string, 25> latin_set;
  int i{};
  for (char ch='b'; ch <='z'; ++ch) {
    latin_set[i++] = ch;
  }

  std::string complete_latin_set = 
      sum(std::begin(latin_set), std::end(latin_set), std::string("a"));
  std::cout << complete_latin_set << '\n';

  std::array<int, 5> ai5{11,22,33,44,55};
  std::cout << sum(std::begin(ai5), std::end(ai5)) << "\n";

  int i3[3]{11,22,33};
  std::cout << sum(i3) << "\n";

  int i5[5] {11, 22, 33, 44, 55};
  std::cout << sum(std::begin(i5), std::end(i5)) << "\n";
  std::cout << sum(i5) << "\n";

  std::string s5[]{"s","i","n","g", "a", "p", "o", "r", "e"};
  std::cout << sum(s5) << "\n";

  std::pair<int, double> pid = stats(std::begin(i5), std::end(i5));
  std::cout << pid << "\n";

}
