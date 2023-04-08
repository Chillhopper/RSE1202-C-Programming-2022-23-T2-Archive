#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <vector>
#include "q.h"

namespace hlp2
{
    void finder::print()
    {
        if (!pos_ls.size())
            std::cout << "\'" << search_str << "\' not found\n\n";
        else
        {
            std::cout << "\'" << search_str << "\' found at "<< pos_ls.size() <<
                " character position(s): ";
          
            pos_ls.print();
            std::cout << "\n";
        }
    }

    finder::finder(std::string const& filename) : search_space_filename(filename), pos_ls() {}
    
    void finder::find(std::string const& search){
        search_str = search;
        pos_ls = dllist<size_type>(); 
        search_space_stream.open(search_space_filename);
        if (search_space_stream.is_open()) {
            // Read the entire search space file into a string
            search_space_stream.seekg(0, std::ios::end);
            search_space_txt.resize(search_space_stream.tellg());
            search_space_stream.seekg(0, std::ios::beg);
            search_space_stream.read(&search_space_txt[0], search_space_txt.size());
            search_space_stream.close();

            // Convert the search string and the search space to lowercase for case-insensitive search
            std::string search_copy = search;
            std::transform(search_copy.begin(), search_copy.end(), search_copy.begin(), [](unsigned char c){ return std::tolower(c); });
            std::string search_space_txt_copy = search_space_txt;
            std::transform(search_space_txt_copy.begin(), search_space_txt_copy.end(), search_space_txt_copy.begin(), [](unsigned char c){ return std::tolower(c); });
            size_type pos = 0;
            while ((pos = search_space_txt_copy.find(search_copy, pos)) != std::string::npos)  {
                pos_ls.push_back(pos);
                pos += search.size();
            }
        }
    }
}