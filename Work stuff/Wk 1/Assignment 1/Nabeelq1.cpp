/*!*************************************************************************
****
\file q.hpp
\author Nabeel
\par DP email: nabeel.a@digipen.edu
\par Course: HLP2
\par Programming Assignment #1
\date 5-1-2023
\brief
This program displays text file details

- q
Prints out a table giving information about text file


****************************************************************************
***/
#include <iomanip>
#include <iostream>
#include <fstream>

namespace hlp2 {
/*!*************************************************************************
****
\brief
Gets information on text file by reading it char by char 
\param input_filename
Contains filename that needs to be information needs to be extracted from
\param analysis_file
Output file 
\return
Information about input filename
****************************************************************************
***/

    void q(char const *input_filename, char const *analysis_file)
    {
        
        std::ifstream fs(input_filename,std::ios_base::in);
        std::ofstream fo(analysis_file,std::ios_base::out);
        int charcount=0;
        int individualcharcount[4]={0};
        double percentcharcount[4]={0};
        int Uppercasecount=0;
        int Lowercasecount=0;
        double Upperpercent=0;
        double Lowerpercent=0;
        double ianalysis[3]={0.00};
        std::string loweralpha="abcdefghijklmnopqrstuvwxyz";
        std::string upperalpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int ncatfile[26]={0};
        float pcatfile[26]={0};
        if(!fs){
            std::cout <<"File " << input_filename << " not found.\n";
        }
        else if(!fo){
            std::cout <<"Unable to create output file " << analysis_file << std::endl;
        }
        else{
            char ch=' ';
            fs >> std::noskipws >> ch;
            while(!fs.eof()){  
                                        
                charcount++;                            
                if(ch>='A' && ch<='Z'){
                    Uppercasecount++;
                    individualcharcount[0]++;
                }
                else if(ch>='a' && ch<='z'){
                    Lowercasecount++;
                    individualcharcount[0]++;
                }
                else if(ch==' ' || ch=='\t' || ch=='\r' || ch=='\n' || ch=='\v' || ch=='\f'){
                    individualcharcount[1]++;
                }
                else if(ch>='0' && ch<='9'){
                    individualcharcount[2]++; 
                    ianalysis[0]++;       
                    int num=ch-48;                                                 
                    while((fs >> ch)&&(ch>='0' && ch<='9')){   
                        individualcharcount[2]++;                    
                        charcount++;
                        num=num*10+(ch-48);                                         
                    }                                     
                    ianalysis[1]+=num;
                    continue;      
                } 
                else{
                    individualcharcount[3]++;
                }    
                // calculate the letters
                for(int i=0;i<26;i++){
                    if(upperalpha[i]==ch || loweralpha[i]==ch){
                        ncatfile[i]++;
                    }
                }   
                fs >> std::noskipws >> ch;     
            }  //end of while loop
        for(int i=0;i<4;i++){
                percentcharcount[0]+=individualcharcount[i];
                percentcharcount[1]+=individualcharcount[i];
                percentcharcount[2]+=individualcharcount[i];
                percentcharcount[3]+=individualcharcount[i];
        }
            
        for(int i=0;i<4;i++){
             percentcharcount[i]=(individualcharcount[i]/percentcharcount[i])*100;
        }
        Upperpercent=(Uppercasecount/(float)individualcharcount[0])*100;
        Lowerpercent=(Lowercasecount/(float)individualcharcount[0])*100;
        //get sum of alphabets
        for(int i=0;i<26;i++){
             for(int j=0;j<26;j++){
                pcatfile[i]+=ncatfile[j];
             }
        }
        //calculate percent of alphabets
        for(int i=0;i<26;i++){
            pcatfile[i]=(ncatfile[i]/pcatfile[i])*100;
        }
        }
        // number analysis 
        //zero error check
        if(ianalysis[0]!=0 && ianalysis[1]!=0){
            ianalysis[2]=ianalysis[1]/ianalysis[0];
        }
        else{
            ianalysis[2]=0;
        }
       //table
        
        fo <<"Statistics for file: " << input_filename << std::endl;
        fo <<"---------------------------------------------------------------------\n" << std::endl;
        fo <<"Total # of characters in file: " << charcount << std::endl << std::endl;
        fo <<"Category            How many in file             % of file\n";
        fo <<"---------------------------------------------------------------------\n";
        fo << std::fixed<< std::setprecision(2);
        fo <<"Letters" << std::setw(29) << individualcharcount[0] << std::setw(20)<< percentcharcount[0] << " %\n";
        fo <<"White space" << std::setw(25) << individualcharcount[1] << std::setw(20) <<  percentcharcount[1] << " %\n";
        fo <<"Digits" << std::setw(30) << individualcharcount[2] << std::setw(20) <<  percentcharcount[2] << " %\n";
        fo <<"Other characters" << std::setw(20) << individualcharcount[3] << std::setw(20) <<  percentcharcount[3] << " %\n\n\n";
        fo <<"LETTER STATISTICS\n" << std::endl;
        fo <<"Category            How many in file      % of all letters\n";
        fo <<"---------------------------------------------------------------------\n";
        fo <<"Uppercase" << std::setw(27) << Uppercasecount << std::setw(20) <<  Upperpercent << " %\n";
        fo <<"Lowercase" << std::setw(27) << Lowercasecount << std::setw(20) <<  Lowerpercent << " %\n";
        for(int i=0;i<26;i++){
            fo <<loweralpha[i] << std::setw(35) << ncatfile[i] << std::setw(20) <<  pcatfile[i] << " %\n";
        }
        fo << "\n\nNUMBER ANALYSIS\n\n";
        fo << "Number of integers in file:          " << std::fixed << std::setprecision(0) << ianalysis[0] << std::endl;
        fo << "Sum of integers:                     " <<  ianalysis[1] << std::endl;
        fo << "Average of integers:                 "  <<std::fixed << std::setprecision(2) << ianalysis[2] << std::endl;
        fo << "_____________________________________________________________________"<< std::endl;
        
    }
}
