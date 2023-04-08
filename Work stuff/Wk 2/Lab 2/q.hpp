// see specs
#ifndef Q_HPP
#define Q_HPP
#include <string> // to use C++ standard library std::string type
#include <fstream> // to use C++ file I/O interface
#include "q.hpp"
// other C++ [not C] standard library headers




namespace hlp2 {

struct Tsunami {

     int month;
        int day;
        int year;
        double max_wh;
        int fatals;
        std::string location;

};

Tsunami* read_tsunami_data(std::string const& file_name, int& max_cnt);
void print_tsunami_data(Tsunami const *arr,int size, std::string const& file_name);


} // end namespace hlp2
#endif