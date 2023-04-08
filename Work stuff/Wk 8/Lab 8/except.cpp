#include "except.h"


//so basically, since subscript error inherited all the juicy shit from std::exception,  since it what() is a virtual function
//it needs to be redefined to suit the error we want to impement.
SubscriptErr::SubscriptErr(int Subscript) : subscript(Subscript){}

const char* SubscriptErr::what() const noexcept{
    static std::string msg;
    msg = "Subscript error at index: ";
    msg += std::to_string(subscript);
    return msg.c_str();
}



std::string const NoNdErr::wat{"No node"};
