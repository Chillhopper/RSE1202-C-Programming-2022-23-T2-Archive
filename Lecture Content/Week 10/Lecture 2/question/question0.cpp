// HLP2: question0.cpp
// 03/28/2022
// A quiz consists of questions.
// A question can display its text, and it can check whether a given
// response is correct or not ...

#include <iostream>
#include <iomanip>
#include <string>

class Question {
public:
  Question() {}
  void set_text(std::string const& question_text) { text = question_text; }
  void set_answer(std::string const& correct_response) { answer = correct_response; }
  void display() const { std::cout << text << std::endl; }
  bool check_answer(std::string const& response) const { return response == answer; }
private:
  std::string text;   // question ...
  std::string answer; // correct answer ...
};

int main() {
  // set a basic question ...
  Question q1;
  q1.set_text("Who was the inventor of C++?");
  q1.set_answer("Bjarne Stroustrup");

  // ask a basic question ...
  q1.display();
  std::cout << "Your answer: ";
  std::string response;
  getline(std::cin, response);
  std::cout << std::boolalpha << q1.check_answer(response) << "\n";
}
