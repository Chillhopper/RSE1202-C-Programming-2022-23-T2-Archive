#include <iostream>
#include <iomanip>
#include <array>
#include <stdexcept>
#include "dllist.h"

// declarations of unit tests
void tstPopFront()
{
    std::cout << "\n******************** Pop Front ********************\n";
    hlp2::dllist list1;
    list1.push_back(34);
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    try {
        list1.pop_front();
    }
    catch (std::exception const& err) {
        std::cout << err.what() << '\n';
    }
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    try {
        list1.pop_front();
    }
    catch (std::exception const& err) {
        std::cout << err.what() << '\n';
    }
}
void tstPrefixPopBack()
{
    std::cout << "\n******************** Prefix Pop Back ********************\n";

    std::array<int, 3> numbers{
      12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
        list1.push_back(x);
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    try {
        std::cout << "--list1 (" << std::setw(2) << (--list1).size() << " nodes): " <<
            list1;
        std::cout << "----list1 (" << std::setw(2) << (----list1).size() << " nodes): " <<
            list1;
    }
    catch (char const* err) {
        std::cout << err << '\n';
    }
        
    try {
        std::cout << "--list1 (" << std::setw(2) << (--list1).size() << " nodes): " <<
            list1;
    }
    catch (char const* err) {
        std::cout << err << '\n';
    }
}
void tstPostfixPopBack()
{
    std::cout << "\n******************** Postfix Pop Back ********************\n";

    std::array<int, 3> numbers{
      12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
        list1.push_back(x);
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    try {
        hlp2::dllist list2 = list1--;
        std::cout << "list1-- returned (" << std::setw(2) << list2.size() << " nodes): "
            << list2;
    }
    catch (...) {
        std::cout << "Exception caught";
    }
    try {
        list1--;
        list1--;
        list1--;
    }
    catch (char const* err) {
        std::cout << err << '\n';
    }
    
    std::cout << "Final list1 (" << std::setw(2) << list1.size() << " nodes): "
        << list1;
}
void tstNonconstSubscript()
{
    std::cout << "\n******************** Non-const Subscript ********************\n";

    hlp2::dllist list1;
    
    std::cout << "list1 (" << std::setw(2) << list1.size() << " nodes): " << list1;
    try {
        std::cout << "list1[0] = " << list1[0] << '\n';
    }
    catch (std::exception const& err) {
        std::cout << err.what() << '\n';
    }
    try {
        std::cout << "list1[2] = " << list1[2] << '\n';
    }
    catch (std::exception const& err) {
        std::cout << err.what() << '\n';
    }
}
void tstConstSubscript()
{
    std::cout << "\n******************** Const Subscript ********************\n";

    std::array<int, 3> numbers{
      12, 34, 21 };
    hlp2::dllist list1;
    for (int x : numbers)
        list1.push_back(x);
    hlp2::dllist const list2 = list1;
    std::cout << "const list2 (" << std::setw(2) << list2.size() << " nodes): " << 
        list2;
    try {
        std::cout << "list2[0] = " << list2[0] << '\n';
        std::cout << "list2[3] = " << list2[3] << '\n';
    }
    catch (...) {
        std::cout << "Exception thrown\n";
    }
}
// this is the purpose of the driver - to call each of these tests in turn ...
int main() {
    tstPopFront();
    tstPrefixPopBack();
    tstPostfixPopBack();
    tstNonconstSubscript();
    tstConstSubscript();
}