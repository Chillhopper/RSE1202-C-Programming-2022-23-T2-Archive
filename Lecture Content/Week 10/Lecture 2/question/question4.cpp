// HLP2: question4.cpp
// 03/28/2022
// Using pointers, we're now able to store the different classes in a
// class hierarchy in a container.
// However, we want to work with objects whose type and behavior can vary at run-time.
// This variation of behavior is achieved with virtual functions.
// When you invoke a virtual function on an object, the C++ run-time system determines
// which actual member function to call, depending on the class to which the
// object belongs.

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
/*
The keyword virtual tells the compiler to use the run-time type of the
object that the pointer is pointing to [and not its compile-time type!!!].
The virtual reserved word must be used in the base class. All functions with
the same name and parameter variable types in derived classes are then
automatically virtual.
*/
  virtual void display() const { std::cout << text << std::endl; }
private:
  std::string text;
  std::string answer;
};

// derived class 
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
/*
All functions with the same name and parameter variable types in derived classes
are automatically virtual.
However, it is considered good taste to supply the virtual reserved word for the
derived-class functions as well.
*/
  virtual void display() const {
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
  // set a basic question ...
  Question *pbq = new Question;
  pbq->set_text("Who was the inventor of C++?");
  pbq->set_answer("Bjarne Stroustrup");

  // set a choice question ...
  ChoiceQuestion *pcq = new ChoiceQuestion;
  pcq->set_text("In which country was the inventor of C++ born?");
  pcq->add_choice("Singapore", false); pcq->add_choice("USA", false);
  pcq->add_choice("China", false);     pcq->add_choice("India", false);
  pcq->add_choice("Sweden", false);    pcq->add_choice("Denmark", true);

  // create a quiz ...
  int const quiz_size{2};
  Question *quiz[quiz_size];
  quiz[0] = pbq;
/*
Note that a derived-class pointer can be converted to a base class pointer.
This is perfectly legal. A pointer is the starting address of an object.
Because every ChoiceQuestion is a special case of a Question, the starting
address of a ChoiceQuestion object is, in particular, the starting address of a
Question object. The reverse assignment - from a base-class pointer to a
derived-class pointer - is an error.
*/
  quiz[1] = pcq;

  // make student take the quiz ...
  for (int i{}; i < quiz_size; ++i) {
    // quiz[i] evaluates to Question*.
    // quiz[i]->display() will invoke Question::display()
    // what we really want is for quiz[1]->display() to invoke ChoiceQuestion::display()!!!
    quiz[i]->display();
    std::cout << "Your answer: ";
    std::string response;
    getline(std::cin, response);
    std::cout << std::boolalpha << quiz[i]->check_answer(response) << "\n";
  }
}