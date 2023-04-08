// HLP2: sum-avg.cpp
// 01/24/2022
// The following code illustrates the use of type std::pair to treat two values
// as a single unit. This class is used in several places in the standard library
// and is quite useful when programmers wish to return two values.
// In principle, you can create, copy, assign, and compare a pair<>.
// <utility> also provides a convenience function make_pair() to create a
// value pair without writing the types explicitly. 

#include <iostream>
#include <initializer_list>
#include <utility>

// usual way to return multiple values from a function is to specify them
// as "in/out" reference parameters ...
void sum_avg(std::initializer_list<int> values, int& sum, double& avg) {
  sum = 0;
  avg = 0.0;

  if (!values.size()) { return; }
  
  for (int x : values) { sum += x; }
  avg = static_cast<double>(sum)/values.size();
}

// return both sum and average as std::pair<int, double> value ...
std::pair<int, double> sum_avg(std::initializer_list<int> values) {
  if (!values.size()) {
    // convenience function make_pair() allows you to create a value
    // pair without writing the types explicitly.
    return std::make_pair(0, 0.0);
  }
  int sum {};
  for (int x : values) { sum += x; }
  double avg = static_cast<double>(sum)/values.size();
  return std::pair<int, double>{sum, avg};
}

int main() {
  // usual way to "return" both sum and avg from the function is to specify
  // them as reference parameters ...
  int sum;
  double avg;
  sum_avg({11,22,33,44,55}, sum, avg);
  std::cout << "sum: " << sum << " | avg: " << avg << '\n';

  //std::pair<int, double> sa = sum_avg({11,22,33,44,55});
  std::pair<int, double> sa;
  sum_avg({11,22,33,44,55});
  std::cout << "sum: " << std::get<0>(sa) 
            << " | avg: " << std::get<1>(sa) << '\n';
  std::get<1>(sa) = 55.67;
  std::cout << "sum: " << std::get<0>(sa) 
            << " | avg: " << std::get<1>(sa) << '\n';

}
