/*!*************************************************************************
****
\brief
Takes in the input and output filename and reads its texts to analyze character frequency, then it outputs the results in a table.
\param input_filename
The pointer to the name of the input file containing the text 
\analysis_file
Pointer to the output filename to print the text to
\return
void
****************************************************************************
***/
#include <iostream>
#include "q.hpp"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << "Usage: ./q.out input-text-file input-text-file-stats\n";
    return 0;
  }

  // argv[1]: input text file to analyze
  // argv[2]: output text file containing analysis of input text file
  hlp2::q(argv[1], argv[2]);
}
