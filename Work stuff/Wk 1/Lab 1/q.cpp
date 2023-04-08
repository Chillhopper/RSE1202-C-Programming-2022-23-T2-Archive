/*!*************************************************************************
****
\file q.cpp
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

#include <iostream>
#include <fstream>



/*!*************************************************************************
****
\brief
Takes in the filename with the encrypted message and checks againsts a set of keywords, to reveal the hidden message.
\param filename
The pointer to the name of the file containing the encrypted message
\param key_words
The pointer to the keywords used to decode the encrypted message
\return
void
****************************************************************************
***/
namespace hlp2{

void q(char const *filename, char const **key_words){
    std::ifstream ifs(filename, std::ios_base::in);
   // int twip = 0;
    if(!ifs.is_open()){
        std::cout << "File " << filename << " not found." << std::endl;
    }else{
        std::string v;
        //reads until blank space
        while(!ifs.eof()){
            ifs >> v; //v becomes a c++ string with no whitespace chars
            //ifs >> to a string reads word by word
            //std::cout << v << std::endl;
           /* if(twip == 1){
                    std::cout << v << " ";
                    twip = 0;
                }
           */
            for(int i = 0; key_words[i] !=nullptr; i++){
               

                if (key_words[i] == v){
                //twip = 1;
                
                ifs>>v;
                std::cout << v << " ";
                ifs>>v;
                  
                }

                
               
            } 
        
        }
        std::cout << "\n";
    }
}


}