/*!*************************************************************************
****
\file q.cpp
\author Kaushik Thirumavalavan
\par DP email: 2200927\@sit.singaporetech.edu.sg
\par Course: RSE1202
\par Section: 2201526
\par Assignment 1: Transitioning from C to C++
\date 13-01-2023
\brief
This program analyzes numbers and letters in a file and prints out statitstics in a table.
 The function include:
- void q()
Takes in input filename and output filename and analyzed every character
****************************************************************************
***/
// You must only include the following header files ...
#include <iostream>
#include <iomanip>
#include <fstream>


// Important notes:

// The auto grader will look for exactly the above three includes.
// If there any additional includes, it will not compile your file.
// The auto grade will not accept any functions not declared in
// these three header files [even in comments]!!!
// You're warned!!!

using namespace std;

namespace hlp2 
{
  // provide definition of q here ...
  void q(char const *input_filename, char const *analysis_file)
  {

    
    float letterCnt = 0;
    float smallCnt = 0;
    float bigCnt = 0;
    float digitCnt = 0;
    float othersCnt = 0;
    float allCnt = 0;
    float wordCnt = 0;
    float resultArr[26] = {};
    
    int intCnt = 0;
    //int ip1, ip2, ip3, ip4;
    int intSum = 0;

    int flag = 0;
    int otherflag = 0;

    string v;
    ifstream input (input_filename, ios_base::in);

    if(input.is_open() == 0)
    {
        cout << "File "<< input_filename <<" not found." <<endl;
    }
    
    else
    {
        while(input >> v) //check word by word
        {

            wordCnt++;

            char temp[1000];
            int tempIndex = 0;

            for(char letter : v) //checking the characters in the word
            {
                
                if(letter >= 'a' && letter <= 'z')
                {
                    resultArr[letter-97]++;
                    smallCnt++;
                    letterCnt++;
                    allCnt++;

                    otherflag = 1;
                }
                else if(letter >= 'A' && letter <= 'Z')
                {
                    resultArr[letter-65]++;
                    bigCnt++;
                    letterCnt++;
                    allCnt++;

                    otherflag = 1;
                }
                else if(letter >= 48 && letter <= 57) //if it is a number
                {
                    digitCnt++;
                    allCnt++;


                    temp[tempIndex] = letter;
                    tempIndex++;
                    flag = 1;
                }
                else
                {
                    othersCnt++;
                    allCnt++;

                    otherflag = 1;

                }

                if (flag == 1 && otherflag == 1)
                {
                    intSum += stoi(temp);

                    for (int z = 0; z < 1000; z++)
                    {
                        temp[z] = 0;
                    }

                    intCnt++;
                    flag = 0;
                    otherflag = 0;
                    tempIndex = 0;
                }

            }

            if (flag == 1)
            {
                
               intSum += stoi(temp);

                    for (int z = 0; z < 1000; z++)
                    {
                        temp[z] = 0;
                    }

                    intCnt++;
                    flag = 0;
                    otherflag = 0;
                    tempIndex = 0;
            }
           
            otherflag = 0;
            tempIndex = 0;

        }

        input.close();
        
        //to account for whitespace
        int whiteSpace = wordCnt-1;

        if(wordCnt>5)
        {
            whiteSpace++;
        }

        allCnt += whiteSpace; 

        
        


        ofstream output (analysis_file, ios_base::out);
        if(!output.is_open())
        {
            output << "Unable to create " << analysis_file << "\n";
        }
        else
        {
            output << "Statistics for file: " << input_filename << endl;
            output <<"---------------------------------------------------------------------"<<endl;
            output << "\n";

            output << "Total # of characters in file: "<< allCnt << endl;
            output << "\n";
            output << "Category            How many in file             % of file" << endl;
            output << "---------------------------------------------------------------------" << endl;
            output << "Letters"<<setw(29)<<letterCnt<<setw(20)<<setprecision(2)<<fixed<<100*letterCnt/allCnt << " %" << endl;
            output << "White space"<<setw(25)<<whiteSpace<<setw(20)<<setprecision(2)<<fixed<<100*((whiteSpace)/allCnt) <<" %" << endl;
            output << "Digits"<<setw(30)<<(int)digitCnt<<setw(20)<<setprecision(2)<<fixed<<100*digitCnt/allCnt << " %" <<endl;
            output << "Other characters"<<setw(20)<<(int)othersCnt<<setw(20)<<setprecision(2)<<fixed<<100*othersCnt/allCnt <<" %" << endl;
            output << "\n";
            output << "\n";
            output << "LETTER STATISTICS" << endl;
            output << "\n";
            output << "Category            How many in file      % of all letters" << endl;
            output << "---------------------------------------------------------------------" << endl;
            output << "Uppercase"<<setw(27)<<(int)bigCnt<<setw(20)<<setprecision(2)<<fixed<<100*bigCnt/letterCnt<< " %" << endl;
            output << "Lowercase"<<setw(27)<<(int)smallCnt<<setw(20)<<setprecision(2)<<fixed<<100*smallCnt/letterCnt<< " %" << endl;
            for(int i = 0; i<26; i++)
            { 
    
                output << (char)(i+97) <<setw(35)<<(int)resultArr[i]<<setw(20)<<100*resultArr[i]/letterCnt << " %" << endl; 
            } 
            output <<"\n"<<endl; 
            output <<"NUMBER ANALYSIS"<<endl; 
            output <<"\n"; 
             
            output << "Number of integers in file:          "<< intCnt <<endl; 
            output << "Sum of integers:                     "<<intSum <<endl; 

            if(intSum>0)
            { 
                 output << "Average of integers:"<<setw(22)<<setprecision(2)<<fixed<<((float)intSum)/((float)(intCnt)) <<endl; 
            }
            else
            { 
                output << "Average of integers:"<<setw(21)<<setprecision(2)<<fixed<<0.00 <<endl; 
            } 
            output << "_____________________________________________________________________" <<endl;
           
        }  

  

    }   
  }
}


