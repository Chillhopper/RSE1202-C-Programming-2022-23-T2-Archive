/*!*************************************************************************
****
\file except.h
\author Tan Choon Yi
\par DP email: nabeel.a@digipen.edu
\par Course: HLP2
\par Lab 8
\date 11-3-2023
\brief
This contains constrcutors and Polymorphism of subscript class
************************/
#include"except.h"

SubscriptErr::SubscriptErr(int Subscript) : subscript(Subscript) {}

const char* SubscriptErr::what() const noexcept
{
    static std::string msg;
    msg = "Subscript error at index: ";
    msg+= std::to_string(subscript);
    return msg.c_str();
}
std::string const NoNdErr::wat{"No node"};