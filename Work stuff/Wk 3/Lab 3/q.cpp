/*!*************************************************************************
****
\file ocean.cpp
\author Kaushik Thirumavalavan
\par DP email: 2200927\@sit.singaporetech.edu.sg
\par Course: RSE1202
\par Section: 2201526
\par Assignment 2: Battleship
\date 19-01-2023
\brief
****************************************************************************
***/
#include "q.hpp"
#include <iostream> // std::cout
#include <iomanip>  // std::setw, std::endl 
#include <string>   // std::string
#include <fstream>  // std::ifstream
#include <vector>   // std::vector<std::string>
#include <iterator> // std::istream_iterato

 
 
 namespace hlp2{
 std::string to_piglatin(std::string word){
    bool upper = false;
    if(word[0]>=65 && word[0]<= 90){
       upper = true;
    }
    std::vector<char> vect(word.begin(), word.end());
   // std::vector<char> vowels{'a','e','i','o','u'};
    std::string vows = "aeiouyAEIOUY";
    char ch = tolower(word[0]);
    if((ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u')){
        vect.push_back('-');
        vect.push_back('y');
        vect.push_back('a');
        vect.push_back('y');
        std::string str(vect.begin(), vect.end());

        return str;

    }else if(word.find_first_of(vows) <= 100){
        
        /*
        std::cout<<"word is " << word <<std::endl;
        std::cout<<"vector is: ";
        for(char ch : vect){
            //std::cout<<ch;
        }
        std::cout<<"\n"; */
        char ch = vect[0];
        while(!(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u'||ch == 'y'||ch == 'A')||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U'){
                //std::cout<<"ch is:"<<vect[0]<<std::endl;
                char temp = vect[0];
                //std::cout<<"vector before erase is: ";
             /* for(char ch : vect){
                   std::cout<<ch;
                }
                std::cout<<"\n"; */
                vect.erase(vect.begin());
                vect.push_back(temp);
                //std::cout<<"vector after erase is: ";
            /*  for(char ch : vect){
                std::cout<<ch;
                }
                std::cout<<"\n";   */
                ch = vect[0];
        }
      
        vect.push_back('-');
        vect.push_back('a');
        vect.push_back('y');
        std::string str(vect.begin(), vect.end());
       // std::cout<<str<<std::endl;
        
        if(upper == true){
            for(size_t i = 0; i<str.size(); i++){
            if(str[i]>=65 && str[i]<=90){
                str[i]+=32;
            }
          }
            str[0]-=32;
        }

        return str;
        /*
        std::cout<<"word is " << word <<std::endl;
        int i = 0;
        for(char ch : vect){
            if(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u'||ch == 'y'){
                std::cout<<"break cond is:"<<vect[i]<<std::endl;
                break;
            }else{
                std::cout<<"else is:"<<vect[i]<<std::endl;
                char temp = vect[i];
                vect.erase(vect.begin()+i);
                vect.push_back(temp);
            }
            i++;
        
        }
        vect.push_back('-');
        vect.push_back('a');
        vect.push_back('y');
        std::string str(vect.begin(), vect.end());
        return str; */
    }else{
        vect.push_back('-');
        vect.push_back('w');
        vect.push_back('a');
        vect.push_back('y');
        std::string str(vect.begin(), vect.end());
        return str;
    }
    //copy range1,range2,to
    //std::copy(word.begin(), word.end(), vect.begin());
    /*for(int i = 0; i<vect.size()-1; i++){
        char ch = vect[i];
        if(!(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u')){
            char temp;
            temp = vect[i];
            vect.erase(vect.begin()+i);
            vect.push_back(temp);
        }
    }*/

    //std::find(vect.begin(), vect.end(), "aeiou");
    //if start vowel -> add suffix -yay
    //if start (not vowel) OR cont (non vowel) ->  trabsfter cont to end of string
    //if no vowels -> return word
    //if Y is first word -> cons else -> vowel
    //captialise 1st letter of word then return
    
    return word;
    }
  }
 