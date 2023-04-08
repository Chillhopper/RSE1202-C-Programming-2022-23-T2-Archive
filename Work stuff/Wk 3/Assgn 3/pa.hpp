#ifndef PA_HPP
#define PA_HPP
#include <vector>
#include <iostream>

// necessary includes of header files except the following:
// <algorithm> and C-only headers such as <cstring>, ...
namespace HLP2 {
// structure to encapsulate a country's name and its population ...
struct CountryInfo {
std::string name; // country's name - *exactly* as in input file
long int pop; // country's population
};

using Ptr_Cmp_Func = bool (*)(CountryInfo const&, CountryInfo const&);

std::vector<CountryInfo> fill_vector_from_istream(std::istream& is);
size_t max_name_length(std::vector<CountryInfo> const&);
void sort(std::vector<CountryInfo>& rv, Ptr_Cmp_Func cmp);
void write_to_ostream(std::vector<CountryInfo> const& v,
std::ostream& os, size_t fw);
bool cmp_name_less(CountryInfo const& left, CountryInfo const& right);
bool cmp_name_greater(CountryInfo const& left, CountryInfo const& right);
bool cmp_pop_less(CountryInfo const& left, CountryInfo const& right);
bool cmp_pop_greater(CountryInfo const& left, CountryInfo const& right);

// other declarations ...
} // end namespace HLP2
#endif