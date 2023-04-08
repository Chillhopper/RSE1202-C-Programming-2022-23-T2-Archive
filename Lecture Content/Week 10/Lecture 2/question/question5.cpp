// HLP2: question5.cpp
// 03/28/2022
// The previous version is made better using the Template Method design pattern
// [https://en.wikipedia.org/wiki/Template_method_pattern]
// We add a non-virtual public member function ask() to the base class.
// This ask() member function standardizes the "asking a question" algorithm
// which was earlier implemented in main().

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// base class that conceptualizes a quiz "Question"
// abstract base class!!!
class Question {
public:
  Question() { std::cout << __PRETTY_FUNCTION__ << "\n"; }
  // if you're want run-time polymorphism, the base class must declare its
  // destructor as a virtual destructor!!!
  virtual ~Question() { std::cout << __PRETTY_FUNCTION__ << "\n"; }

  // non-virtual functions
  // The base class is providing these non-virtual functions and every derived class must just use them!!!
  // That is, the derived class must not redefine these functions since these functions conceptualize
  // the meaning of a "Question".
  void set_text(std::string const& question_text) { text = question_text; }
  void set_answer(std::string const& correct_response) { answer = correct_response; }
  bool check_answer(std::string const& response) const { return response == answer; }
  void ask() const {
    display(); // the run-time environment will call display of concrete derived class ...
    std::cout << "Your answer: ";
    std::string response;
    getline(std::cin, response);
    std::cout << std::boolalpha << check_answer(response) << "\n";
  }

  // this is a pure virtual function with 2 consequences:
  // 1) Clients cannot define an object of type Question.
  // 2) Every derived class must define this function!!!
  virtual void display() const = 0;

private:
  std::string text;
  std::string answer;
};

// A base class can always provide the definition of a pure virtual function!!!
void Question::display() const {
  std::cout << text << "\n";
}

// concrete derived class that "is-a" Question
class ShortAnswerQuestion : public Question {
public:
  ShortAnswerQuestion() { std::cout << __PRETTY_FUNCTION__ << "\n"; }
  virtual ~ShortAnswerQuestion() { std::cout << __PRETTY_FUNCTION__ << "\n"; }

  // derived class must provide a definition of pure virtual function display()
  virtual void display() const { Question::display(); }
};

// another concrete derived class that "is-a" Question
class ChoiceQuestion : public Question {
public:
  ChoiceQuestion() { std::cout << __PRETTY_FUNCTION__ << "\n"; }
  virtual ~ChoiceQuestion() { std::cout << __PRETTY_FUNCTION__ << "\n"; }

  void add_choice(std::string const& choice, bool correct) {
    choices.push_back(choice);
    if (correct) {
      std::string choice_str = std::to_string(choices.size());
      set_answer(choice_str);
    }
  }
  virtual void display() const  {
    Question::display();
    std::vector<std::string>::size_type i{};
    for (std::string const& x : choices) {
      std::cout << ++i << ": " << x << std::endl;
    }
  }
private:
  std::vector<std::string> choices;
};

std::vector<Question*> create_quiz() {
  // set a basic question ...
  ShortAnswerQuestion *pbq = new ShortAnswerQuestion;
  pbq->set_text("Who was the inventor of C++?");
  pbq->set_answer("Bjarne Stroustrup");

  // set a choice question ...
  ChoiceQuestion *pcq = new ChoiceQuestion;
  pcq->set_text("In which country was the inventor of C++ born?");
  pcq->add_choice("Singapore", false); pcq->add_choice("USA", false);
  pcq->add_choice("China", false);     pcq->add_choice("India", false);
  pcq->add_choice("Sweden", false);    pcq->add_choice("Denmark", true);

  // create a quiz ...
  std::vector<Question*> quiz;
  quiz.push_back(pbq);
  quiz.push_back(pcq);

  return quiz;
}

// make student take the quiz ...
void take_quiz(std::vector<Question*> const& quiz) {
  for (Question const *pq : quiz) {
    pq->ask();
  }
}

void cleanup(std::vector<Question*>& quiz) {
  for (Question *pq : quiz) {
    delete pq;
  }
}

int main() {
  std::vector<Question*> quiz = create_quiz();
  take_quiz(quiz);
  cleanup(quiz);
}
