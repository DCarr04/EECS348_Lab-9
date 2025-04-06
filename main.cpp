#include <iostream>

#include "matrix.hpp"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    string file;
    string line;
    int rowCounter = 0;
    int data;
    int size;
    int sizeTracker = 0;
    string preInt_data;
    cout << "Enter a file: ";
    cin >> file;
    ifstream myfile (file);
    vector<vector<int> > nums;
    vector<vector<int> > nums2;

    if (myfile.is_open()){
        while(getline(myfile, line)){
            //Matrix myMatrix();
            if (line.size() == 1){
                size = stoi(line);
                //Matrix myMatrix(size);
            }
            
            if(rowCounter < size){
                if(line.size() == size){
                    for(int i = 0; i < size; i++){
                        preInt_data.push_back(line[i]);
                        data = stoi(preInt_data);
                        nums[rowCounter][i] = data;
                        preInt_data.pop_back();
                    }
                    ++rowCounter;
                }
                //++sizeTracker;
            }else{
                if (line.size() == size){
                    for(int j = 0; j < size; j++){
                        preInt_data.push_back(line[j]);
                        data = stoi(preInt_data);
                        nums2[rowCounter - size][j] = data;
                        preInt_data.pop_back();
                    }
                    ++rowCounter;
                }
                //++sizeTracker;
            }
            
            //myMatrix(nums);
            
            
        }
        Matrix myMatrix(nums);
        if(nums2.size() != 0){
            Matrix myMatrix2(nums2);
        }
        myMatrix.print_matrix();
    }
    

    return 0;
}
