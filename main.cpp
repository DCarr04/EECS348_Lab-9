#include <iostream>

#include "matrix.hpp"
#include <fstream>
#include <string>
#include <vector>
using namespace std;


std::vector<std::string> split(const std::string &s, char delimiter) { //Source: This function was sourced from Deepseek AI
    std::vector<std::string> tokens; //Declares vector of type string that will hold the substrings
    size_t start = 0; //Initialize start at 0 that will be used as an index; Type: size_t
    size_t end = s.find(delimiter); //Initialize end at where a delimiter is found in the string; Type: size_t
    
    while (end != std::string::npos) { //loop that stops when end reaches its max possible value
        tokens.push_back(s.substr(start, end - start)); //substr() captures the split substrings and is added to the end of tokens
        start = end + 1; //start index is moved up to one head of the previus end value
        end = s.find(delimiter, start); // end is set to value of find() that finds the next section to split
    } //end of while loop
    tokens.push_back(s.substr(start)); //adds the remainder of the string that didn't a delimiter at its end to tokens
    return tokens; //returns the vector tokens
}



int main(int argc, char *argv[]) {
    string file;
    string line;
    int rowCounter = 0;
    int data;
    int size = 0;
    int int_or_dbl;
    
    cout << "Enter a file: ";
    cin >> file;
    ifstream myfile (file);
    Matrix myMatrix(size);
    Matrix myMatrix2(size);
    if (myfile.is_open()){
        while(getline(myfile, line)){
            int i = 0;
            if (line.size() == 3){
                size = stoi(line.substr(0));
                int_or_dbl = stoi(line.substr(2));
                Matrix myMatrix_mid(size);
                myMatrix = myMatrix_mid;
                myMatrix2 = myMatrix_mid;
            }
            else if(line.size() == 0){

            }
            else{
                if(rowCounter < size){
                    vector<string> entries = split(line, ' ');
                    
                    for(int i = 0; i < entries.size(); i++){
                        data = stoi(entries[i]);
                        myMatrix.data[rowCounter][i] = data;
                    }
                    ++rowCounter;

                }else{
                    vector<string> entries = split(line, ' ');
                    for(int i = 0; i < entries.size(); i++){
                        data = stoi(entries[i]);
                        myMatrix2.data[rowCounter - size][i] = data;
                    }
                    ++rowCounter;
                }
            }
            
            
        }
        cout << "Got here11" << endl;
       /*Matrix myMatrix(nums);
        if(nums2.size() != 0){
            Matrix myMatrix2(nums2);
        }*/
        Matrix mathMatrix(size);
        mathMatrix = myMatrix * myMatrix2;
        myMatrix.print_matrix();
        myMatrix2.print_matrix();
        mathMatrix.print_matrix();

    }
    myfile.close();
    

    return 0;
}
