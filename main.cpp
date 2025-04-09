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
    int size = 1;
    //int sizeTracker = 0;
    int int_or_dbl;
    //string preInt_data;
    cout << "Enter a file: ";
    cin >> file;
    ifstream myfile (file);
    Matrix myMatrix(size);
    Matrix myMatrix2(size);
    cout << "Got here" << endl;
    if (myfile.is_open()){
        cout << "Got here2" << endl;
        while(getline(myfile, line)){
            cout << "Got here3" << endl;
            int i = 0;
            //Matrix myMatrix();
            if (line.size() == 3){
                size = stoi(line.substr(0));
                int_or_dbl = stoi(line.substr(2));
                cout << "Got here3.5" << endl;
                //Matrix myMatrix(size);
                Matrix myMatrix_mid(size);
                cout << "Got here3.6" << endl;
                myMatrix = myMatrix_mid;
                myMatrix2 = myMatrix_mid;
                //myMatrix.data[0][0] = 9;
            }
            else if(line.size() == 0){

            }
            else{
                cout << "Got here4" << endl;
                if(rowCounter < size){
                    cout << "Got here5" << endl;
                    cout << "\tsize:" << size << endl;
                    vector<string> entries = split(line, ' ');
                    
                    
                    for(int i = 0; i < entries.size(); i++){
                        //preInt_data.push_back(line.substr(i, 2));
                        data = stoi(entries[i]);
                        cout << "\tdata at entries[i]:" << data << endl;
                        //cout << "\trowCounter:" << rowCounter << endl;
                        //cout << "\ti:" << i << endl;
                        //cout << "\tnums[0][0]:" << myMatrix.data[0][0] << endl;
                        myMatrix.data[rowCounter][i] = data;
                        cout << "Got here5.5" << endl;
                        //preInt_data.pop_back();
                        
                    }
                    ++rowCounter;
                    cout << "Got here6" << endl;
                    //++sizeTracker;
                }else{
                    cout << "Got here7" << endl;
                    vector<string> entries = split(line, ' ');
                    for(int i = 0; i < entries.size(); i++){
                        cout << "Got here8" << endl;
                        //preInt_data.push_back(line.substr(i, 2));
                        data = stoi(entries[i]);
                        myMatrix2.data[rowCounter - size][i] = data;
                        //preInt_data.pop_back();
                    }
                    ++rowCounter;
                    cout << "Got here9" << endl;
                    //++sizeTracker;
                }
                cout << "Got here10" << endl;
                //myMatrix(nums);
            
            }
            
            
        }
        cout << "Got here11" << endl;
       /*Matrix myMatrix(nums);
        if(nums2.size() != 0){
            Matrix myMatrix2(nums2);
        }*/
        myMatrix.print_matrix();
    }
    myfile.close();
    

    return 0;
}
