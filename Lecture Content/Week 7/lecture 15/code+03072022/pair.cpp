#include <iostream>
#include <algorithm>

class PairID {
private:
  int first;
  double second;
public:
  PairID() : first{}, second{} {}
  PairID(int f, double s) : first{f}, second{s} {}

  int First() const { return first; }
  void First(int f) { first = f; }
  double Second() const { return second; }
  void Second(double s) { second = s; }

  void swap(PairID const& rhs) { 
    std::swap(first, rhs.first); std::swap(second, rhs.second);}
};

bool operator==(PairID const& lhs, PairID const& rhs) {
  return lhs.First()==rhs.First() && lhs.Second()==rhs.Second();
}

bool operator!=(PairID const& lhs, PairID const& rhs) {
  return !(lhs==rhs);
}
