
/*!*************************************************************************
****
\file q.cpp
\author Kavyanjali
\par DP email: 2203390@sit.singaporetech.edu.sg
\par Course: RSE 1202
\par Section: 
\par Programming Assignment #9
\date 23-03-2023
\brief
This program scans through the input file and searches for a given string.
It then places the string into a linked list with a corresponding starting subscript 
index position for each time the search text is found.
****************************************************************************
***/

#include <cstring>
#include <iostream>
#include <algorithm>
#include <list>
#include "q.h"

namespace hlp2
{
	/*!*************************************************************************
	****
	\brief
    This function prints out the string, no. of positions it was found at and the positions
    themselves
	\return
    void
	****************************************************************************
	***/
    void finder::print() 
    {
        if (pos_ls.empty()) {
            std::cout << "'" << search_str << "' not found\n\n";
        } 
        else 
        {
            std::cout << "'" << search_str << "' found at " << pos_ls.size() 
                << " character position(s): ";
            for (auto pos : pos_ls) {
                std::cout << pos << "    ";
            }
            std::cout << "\n\n";
        }
    }


    
    finder::finder(std::string const& filename) : search_space_filename(filename), pos_ls() {} 
  

	/*!*************************************************************************
	****
	\brief
    This function searches the input file for the string specified 
	\return
    void
	****************************************************************************
	***/
    void finder::find(std::string const& search) //searches for a specified string in the file
    {
        search_str = search;
            pos_ls.clear(); 
            std::ifstream search_space_stream(search_space_filename); 
            if (search_space_stream.is_open()) {
            
            std::string search_space_txt((std::istreambuf_iterator<char>(search_space_stream)),
            std::istreambuf_iterator<char>());

            
            std::string search_copy = search;
            std::transform(search_copy.begin(), search_copy.end(), search_copy.begin(), 
            [](char c){ return std::tolower(c); });

            std::string search_space_txt_copy = search_space_txt;
            std::transform(search_space_txt_copy.begin(), search_space_txt_copy.end(), search_space_txt_copy.begin(), 
            [](char c){ return std::tolower(c); });

            
            size_type pos = 0;
            while ((pos = search_space_txt_copy.find(search_copy, pos)) != std::string::npos) {
                pos_ls.push_back(pos);
                pos += search.size();
            }
            search_space_stream.close();
        }
    }
}