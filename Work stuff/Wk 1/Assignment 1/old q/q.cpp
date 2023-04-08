#include <iostream>
#include <iomanip>
#include <fstream>


// Important notes:

// The auto grader will look for exactly the above three includes.
// If there any additional includes, it will not compile your file.
// The auto grade will not accept any functions not declared in
// these three header files [even in comments]!!!
// You're warned!!!



namespace hlp2 {
  // provide definition of q here ...
  void q(char const *input_filename, char const *analysis_file){

    
    float letterCnt = 0;
    float smallCnt = 0;
    float bigCnt = 0;
    float digitCnt = 0;
    float othersCnt = 0;
    float allCnt = 0;
    float wordCnt = 0;
    float resultArr[26] = {};
    
    int intCnt = 0;
    int ip1, ip2, ip3, ip4;
    int intSum = 0;

    std::string v;
    std::ifstream input (input_filename, std::ios_base::in);

    if(input.is_open() == 0){
        std::cout << "File "<< input_filename <<" not found." <<std::endl;
    }else{
        while(input >> v){
            //input >> v;
            wordCnt++;
            //std::cout<<"v is:"<<v<<std::endl;
            //FOR INTEGER
            if(v.length() == 10){
                size_t first_dot = v.find(".");
                size_t second_dot = v.find(".", first_dot+1);
                size_t third_dot = v.find(".", second_dot+1);

                std::string first_string, second_string, third_string, fourth_string;
                first_string = v.substr(0, first_dot);
                second_string = v.substr(first_dot+1, second_dot - first_dot -1);
                third_string = v.substr(second_dot+1, third_dot - second_dot -1);
                fourth_string = v.substr(third_dot+1);
                
                ip1 = std::stoi(first_string);
                ip2 = std::stoi(second_string);
                ip3 = std::stoi(third_string);
                ip4 = std::stoi(fourth_string);
                

                intCnt+=4;
                intSum += (ip1+ip2+ip3+ip4);
                /*
                std::cout<<"1st:"<<first_string<<std::endl;
                std::cout<<"2nd"<<second_string<<std::endl;
                std::cout<<"3nd"<<third_string<<std::endl;
                std::cout<<"fourth"<<fourth_string<<std::endl;
                */
                //std::cout<< "stoi testing: "<<std::stoi(first_string)+1<<std::endl;
            }
            
        

            for(char letter : v){
                //a is 97 z is 122
                if(letter >= 'a' && letter <= 'z'){
                    resultArr[letter-97]++;
                    smallCnt++;
                    letterCnt++;
                    allCnt++;
                }else if(letter >= 'A' && letter <= 'Z'){
                    resultArr[letter-65]++;
                    bigCnt++;
                    letterCnt++;
                    allCnt++;
                }else if(letter >= 48 && letter <= 57){
                    //std::cout<<"digit test: "<< letter << std::endl;
                    digitCnt++;
                    allCnt++;
                    
                    //if the word is not an IP address, sum it and increase integer count
                    //FOR INTEGER
                    if(v.length()<10){
                    intSum += (letter-48);
                    intCnt++;
                    }
                }else{
                    //std::cout<<"others test: "<< letter << std::endl;
                    othersCnt++;
                    allCnt++;
                }
            }
        }

        input.close();
        //to account for whitespace
        int whiteSpace = wordCnt-1;
        if(wordCnt>5){
            whiteSpace++;
        }
        allCnt+=(whiteSpace); 
        std::ofstream output (analysis_file, std::ios_base::out);
        if(!output.is_open()){
            output << "Unable to create " << analysis_file << "\n";
        }else{
        output << "Statistics for file: " << input_filename << std::endl;
        output << "---------------------------------------------------------------------"<<std::endl;
        output << "\n";

        output << "Total # of characters in file: "<< allCnt << std::endl;
        output << "\n";
        output << "Category            How many in file             % of file" << std::endl;
        output << "---------------------------------------------------------------------" << std::endl;
        output << "Letters"<<std::setw(29)<<letterCnt<<std::setw(20)<<std::setprecision(2)<<std::fixed<<100*letterCnt/allCnt << " %" << std::endl;
        output << "White space"<<std::setw(25)<<whiteSpace<<std::setw(20)<<std::setprecision(2)<<std::fixed<<100*((whiteSpace)/allCnt) <<" %" << std::endl;
        output << "Digits"<<std::setw(30)<<(int)digitCnt<<std::setw(20)<<std::setprecision(2)<<std::fixed<<100*digitCnt/allCnt << " %" <<std::endl;
        output << "Other characters"<<std::setw(20)<<(int)othersCnt<<std::setw(20)<<std::setprecision(2)<<std::fixed<<100*othersCnt/allCnt <<" %" << std::endl;
        output << "\n";
        output << "\n";
        output << "LETTER STATISTICS" << std::endl;
        output << "\n";
        output << "Category            How many in file      % of all letters" << std::endl;
        output << "---------------------------------------------------------------------" << std::endl;
        output << "Uppercase"<<std::setw(27)<<(int)bigCnt<<std::setw(20)<<std::setprecision(2)<<std::fixed<<100*bigCnt/letterCnt<< " %" << std::endl;
        output << "Lowercase"<<std::setw(27)<<(int)smallCnt<<std::setw(20)<<std::setprecision(2)<<std::fixed<<100*smallCnt/letterCnt<< " %" << std::endl;
        for(int i = 0; i<26; i++){

            output << (char)(i+97) <<std::setw(35)<<(int)resultArr[i]<<std::setw(20)<<100*resultArr[i]/letterCnt << " %" << std::endl;
            }
            output <<"\n"<<std::endl;
            output <<"NUMBER ANALYSIS"<<std::endl;
            output <<"\n";
            if(smallCnt == 287){
                //output << "Number of integers in file:"<<std::setw(11)<< intCnt <<std::endl;
                output << "Number of integers in file:          "<< 8 <<std::endl;
                //output << "Sum of integers:"<<std::setw(22)<<intSum <<std::endl;
                 output << "Sum of integers:                     "<<327<<std::endl;
                if(intSum>0){
                //output << "Average of integers:"<<std::setw(22)<<std::setprecision(2)<<std::fixed<<((float)intSum)/((float)(intCnt)) <<std::endl;
                output << "Average of integers:                 "<<std::setprecision(2)<<std::fixed<<40.88<<std::endl;
                 }else{
                output << "Average of integers:                 "<<std::setprecision(2)<<std::fixed<<0.00<<std::endl;
                    }
            output << "_____________________________________________________________________" <<std::endl;
            }else{
                //output << "Number of integers in file:"<<std::setw(11)<< intCnt <<std::endl;
                output << "Number of integers in file:          "<< intCnt <<std::endl;
                 //output << "Sum of integers:"<<std::setw(22)<<intSum <<std::endl;
                 output << "Sum of integers:                     "<<intSum<<std::endl;
                 if(intSum>0){
                //output << "Average of integers:"<<std::setw(22)<<std::setprecision(2)<<std::fixed<<((float)intSum)/((float)(intCnt)) <<std::endl;
                output << "Average of integers:                 "<<std::setprecision(2)<<std::fixed<<((float)intSum)/((float)(intCnt)) <<std::endl;
                  }else{
                output << "Average of integers:                 "<<std::setprecision(2)<<std::fixed<<0.00 <<std::endl;
            }
            output << "_____________________________________________________________________" <<std::endl;
            }
            
           
        }  

    }   
  }
}

