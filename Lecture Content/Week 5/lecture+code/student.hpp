// HLP2
// 02/06/2022
// Interface file for a Student type that is used to introduce ADT development
// with classes in lecture handout: classes+intro.pdf

#ifndef STUDENT_HPP
#define STUDENT_HPP

// To implement function overloading and classes, function names are mangled.
// Both GNU and Microsoft C++ compilers contain macros to print the unmangled
// function name at runtime: GNU uses __PRETTY_FUNCTION__ macro while
// Microsoft provides __FUNCSIG__
// The following preprocessor directives check if the compiler is not GNU C++,
// and assigns the macro __PRETTY_FUNCTION__ to be equivalent to __FUNCSIG__ 
#if !(__GNUG__)
#define  __PRETTY_FUNCTION__ __FUNCSIG__
#endif

namespace hlp2 {

class Student {
public:
  Student(char const* log, int a, int y, double gpa); // ctor
  ~Student(); // dtor

  void set_login(char const* log); // mutators are modifying
  void set_age(int a);
  void set_year(int y);
  void set_GPA(double gpa);

  int get_age() const; // accessors are nonmodifying
  int get_year() const;
  double get_GPA() const;
  char const* get_login() const;
  
  void display() const;
private:
  char *login;
  int age, year;
  double GPA;
};

} // end namespace hlp2

#endif
