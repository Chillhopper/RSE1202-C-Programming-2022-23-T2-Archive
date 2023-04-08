#ifndef EXCEPT_H
#define EXCEPT_H

#include <string>
#include <stdexcept>

class SubscriptErr : public std::exception {
public:
	SubscriptErr(int Subscript);
	virtual const char* what() const noexcept;
private:
	int subscript;
};

class NoNdErr : public std::exception {
public:
	virtual const char* what() const noexcept { return wat.c_str(); }
private:
	static std::string const wat;
};
#endif