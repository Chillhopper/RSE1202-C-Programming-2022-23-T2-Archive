// HLP2
// Driver file to illustrate use of static data members and member functions
// in class Sphere
// See the handout for more details

#include <iostream>
#include "sphere.hpp"

int main() {
  Sphere s1(3.0);
  std::cout << "s1 radius: " << s1.Radius() << " | volume: " << s1.Volume() << "\n";
  s1.Radius(5.0);
  std::cout << "s1 radius: " << s1.Radius() << " | volume: " << s1.Volume() << "\n";
  std::cout << "sizeof(Sphere): " << sizeof(Sphere) << "\n";
  std::cout << "   radius: " << 3.0         << " | volume: " << Sphere::vol(3.0) << "\n";
  std::cout << "How many Sphere's? " << Sphere::ctr() << "\n";
}
