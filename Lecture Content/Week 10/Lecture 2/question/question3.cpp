// HLP2: question3.cpp
// 03/28/2022
// To avoid the slicing problem when accessing different classes in a
// class hierarchy, we must use pointers.
// Pointers to the various objects all have the same size - namely, the
// size of a memory address - even though the objects themselves may
// have different sizes 

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
