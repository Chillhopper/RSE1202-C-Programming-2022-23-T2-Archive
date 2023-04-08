// HLP2
// 02/06/2022
// Implementation file for a Student type that is used to introduce ADT 
// development with classes in lecture handout: classes+intro.pdf
#include <iostream>
#include <cstring>
#include "student.hpp"

namespace hlp2 {

Student::Student(char const* log, int a, int y, double gpa) 
: login(nullptr), age(a), year(y), GPA(gpa) {
  set_login(log);
  set_age(a);
  set_year(y);
  set_GPA(gpa);
  std::cout << __PRETTY_FUNCTION__ << " | " << login << "\n";
  //std::cout << "Student constructor for " << login << "\n";
}

Student::~Student() {
  std::cout << __PRETTY_FUNCTION__ << " | " << login << "\n";
  delete [] login;
}

void Student::set_login(char const* log) {
  delete [] login;
  login = new char[std::strlen(log) + 1]; 
  std::strcpy(login, log);
}

void Student::set_year(int y) {
  if ( (y < 1) || (y > 4) ) {
    std::cout << "Error in year range!\n";
    year = 1;
  }
  else {
    year = y;
  }
}

void Student::set_age(int a) {
  if ( (a < 18) || (a > 100) ) {
    std::cout << "Error in age range!\n";
    a = 18;
  }
  else {
    age = a;
  }
}

void Student::set_GPA(double gpa) {
  if ( (gpa < 0.0) || (gpa > 4.0) ) {
    std::cout << "Error in GPA range!\n";
    GPA = 0.0;
  }
  else
    GPA = gpa;
}

int Student::get_age()           const { return age;}
int Student::get_year()          const { return year; }
double Student::get_GPA()        const { return GPA; }
char const* Student::get_login() const { return login; }

void Student::display() const {
  std::cout << "login: " << login << "\n";
  std::cout << "  age: " << age << "\n";
  std::cout << " year: " << year << "\n";
  std::cout << "  GPA: " << GPA << "\n";
}

} // end namespace hlp2
