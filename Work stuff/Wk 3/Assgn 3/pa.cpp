#include <vector>
#include "pa.hpp"
#include <iostream>
#include <sstream>

struct CountryInfo {
std::string name; // country's name - *exactly* as in input file
long int pop; // country's population
};
using Ptr_Cmp_Func = bool (*)(CountryInfo const&, CountryInfo const&);

//vector allocates its own memory
std::vector<CountryInfo> fill_vector_from_istream(std::istream& is){
    std::string line;
    int i = 0;
    std::vector<CountryInfo> someVect;
    while(is.getline(is, line)){
        std::string country, population;
        std::stringstream s(line);
        s >> country >> population;
        population.erase(',');
        someVect[i].name = country;
    }

}

//returns length of the longest country's name in the vector
size_t max_name_length(std::vector<CountryInfo> const& countries){
    long int maxSize = 0;
    for(CountryInfo landMass : countries){
        if(landMass.name.length() > maxSize){
            maxSize = landMass.name.length();
        }
    }
    return (size_t)maxSize;
}
void sort(std::vector<CountryInfo>& rv, Ptr_Cmp_Func cmp);
void write_to_ostream(std::vector<CountryInfo> const& v, std::ostream& os, size_t fw);
bool cmp_name_less(CountryInfo const& left, CountryInfo const& right);
bool cmp_name_greater(CountryInfo const& left, CountryInfo const& right);
bool cmp_pop_less(CountryInfo const& left, CountryInfo const& right);
bool cmp_pop_greater(CountryInfo const& left, CountryInfo const& right);
