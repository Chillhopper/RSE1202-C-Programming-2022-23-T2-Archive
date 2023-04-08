/*!*************************************************************************
****
\file q.hpp
\author Kaushik Thirumavalavan
\par DP email: 2200927\@sit.singaporetech.edu.sg
\par Course: RSE1202
\par Section: 2201526
\par Lab 1: Transitioning from C to C++
\date 07-01-2023
\brief
This program decodes and prints a secret message hidden steganographically to stdout.
 The function include:
- q()
Takes in the filename with the encrypted message and checks againsts a set of keywords, to reveal the hidden message.
****************************************************************************
***/

#ifndef Q_HPP_
#define Q_HPP_
namespace hlp2 {
// declare function q here ...
void q(char const *filename, char const **key_words);
}
#endif