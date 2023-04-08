// HLP2: question2.cpp
// 03/28/2022
// This source file illustrates the slicing problem:
// If you look at question1.cpp, you'll see that there is some repetitive
// code to display each question and check responses.
// It'd be nicer if we collect quiz questions in an array and use a
// loop to present them to the student.
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// base class
class Question {
public:
  Question() {}
  void set_text(std::string const& question_text) { text = question_text; }
  void set_answer(std::string const& correct_response) { answer = correct_response; }
  bool check_answer(std::string const& response) const { return response == answer; }
  void display() const { std::cout << text << std::endl; }
private:
  std::string text;
  std::string answer;
};

class ChoiceQuestion : public Question {
public:
  ChoiceQuestion() {}
  void add_choice(std::string const& choice, bool correct) {
    choices.push_back(choice);
    if (correct) {
      std::string choice_str = std::to_string(choices.size());
      set_answer(choice_str);
    }
  }
  void display() const {
    Question::display();
    std::vector<std::string>::size_type i{};
    for (std::string const& x : choices) {
      std::cout << ++i << ": " << x << std::endl;
    }
  }
private:
  std::vector<std::string> choices;
};

int main() {
  // setup basic question ...
  Question bq;
  bq.set_text("Who was the inventor of C++?");
  bq.set_answer("Bjarne Stroustrup");

  // setup choice question ...
  ChoiceQuestion cq;
  cq.set_text("In which country was the inventor of C++ born?");
  cq.add_choice("Singapore", false); cq.add_choice("USA", false);
  cq.add_choice("China", false);     cq.add_choice("India", false);
  cq.add_choice("Sweden", false);    cq.add_choice("Denmark", true);

/*
The array quiz holds objects of type Question. The compiler realizes that
ChoiceQuestion is a special type of Question. Thus, it permits an element
of array Quiz to be initialized with a ChoiceQuestion object.
However, a ChoiceQuestion object has 3 data members, whereas a Question object
has 2 data members. There is no room in a Question object to store the data
associated with an object of derived class type ChoiceQuestion.
What is the compiler to do?
Array elements must all have the same storage size - a C/C++ array cannot
deal with variations in size!!!
The compiler will simply slice away the derived class data when you assign
a derived class object to a base class variable ...
In short, array quiz will only contain the Question part of ChoiceQuestion
but not the part that makes it different from a Question ...
*/
  // create quiz ...
  constexpr int const quiz_size{2};
  Question quiz[quiz_size] {bq, cq};

  // present quiz ...
  for (int i{}; i < quiz_size; ++i) {
    quiz[i].display();
    std::cout << "Your answer: ";
    std::string response;
    getline(std::cin, response);
    std::cout << std::boolalpha << quiz[i].check_answer(response) << "\n";
  }
}
