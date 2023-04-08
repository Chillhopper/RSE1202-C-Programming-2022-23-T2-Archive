/*!*************************************************************************
****
\file q.hpp
\author Kaushik Thirumavalavan
\par DP email: 2200927\@sit.singaporetech.edu.sg
\par Course: RSE1202
\par Section: 2201526
\par Assignment 1: Transitioning from C to C++
\date 13-01-2023
\brief
This program analyzes numbers and letters in a file and prints out statitstics in a table.
 The function include:
- q()
Takes in input filename and output filename and analyzed every character
****************************************************************************
***/
#include <iostream>
#include <iomanip>
#include <fstream>


namespace hlp2 {
  // provide definition of q here ...
  void q(char const *input_filename, char const *analysis_file);
}