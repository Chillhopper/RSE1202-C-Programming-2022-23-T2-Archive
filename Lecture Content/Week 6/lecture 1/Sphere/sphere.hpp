// HLP2
// Interface file to illustrate static data members and member functions
// See the handout for more details

#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere {
public:
  Sphere(double r) : radius(r), volume((4.0*PI*r*r*r)/3.0) { ++counter; }
  ~Sphere() { --counter; }
  
  double Radius() const   { return radius; }
  void   Radius(double r) { radius = r; volume = (4.0*PI*r*r*r)/3.0; }
  double Volume() const   { return vol(radius); }

  static double vol(double r);
  static int    ctr();
private:
  double radius, volume;
  static int counter;
  static double const PI;
};

#endif // #ifdef SPHERE_HPP
