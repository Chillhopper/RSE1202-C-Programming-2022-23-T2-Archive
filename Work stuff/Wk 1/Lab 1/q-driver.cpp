#include <iostream> // std::cout
#include <string>   // std::stoi
#include "q.hpp"

// declarations of unit tests ...
static void test0();
static void test1();
static void test2();
static void test3();
static void test4();

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: ./lab1.out test-number-between-0-and-4 > secret-message-file-name\n";
    return 0;
  }

  int test_choice = std::stoi(argv[1]);
  test_choice = (test_choice < 0) ? 0 : (test_choice > 4) ? 4 : test_choice;
  switch (test_choice) {
    case 0: test0(); break;
    case 1: test1(); break;
    case 2: test2(); break;
    case 3: test3(); break;
    case 4: test4(); break;
  }
}

// definitions of unit tests ...
void test0() {
  hlp2::q("message0.txt", nullptr);
}

void test1() {
  char const *keywords1[] = {"please", "shark", nullptr};
  hlp2::q("message1.txt", keywords1);
}

void test2() {
  char const *keywords2[] = {"so", "rain", "in", nullptr};
  hlp2::q("message2.txt", keywords2);
}

void test3() {
  char const *keywords3[] = {"are", "a", nullptr};
  hlp2::q("message3.txt", keywords3);
}

void test4() {
  char const *keywords4[] = {"is", "that", "better", nullptr};
  hlp2::q("message4.txt", keywords4);
}
