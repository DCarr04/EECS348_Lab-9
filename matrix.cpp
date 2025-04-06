#include "matrix.hpp"
#include <vector>
#include <iostream>
using namespace std;

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:
//Matrix::Matrix() : size(0){}

Matrix::Matrix(size_t N) : size(N){
    // initialize an empty NxN matrix
    //size = N;
    vector<vector<int> > nums;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            data[i][j] = 0;
        }
    }
    //data = nums;
}

Matrix::Matrix(vector<vector<int> > nums) : data(nums){
    //data = nums;
    size = nums.size();
}

Matrix::~Matrix(){
    
}
// e.g. for a member function:

Matrix Matrix::operator+(const Matrix &rhs) const{
    Matrix sum_Matrix(rhs.size);
    if(size == rhs.size){
        for(int i = 0; i < rhs.size; i++){
            for(int j = 0; j < rhs.size; j++){
                sum_Matrix.data[i][j] = data[i][j] + rhs.data[i][j];
            }
        }
    }else{
        cout << "The two matrices are not the same dimensions." << endl;
    }
    

    return sum_Matrix;
}

Matrix Matrix::operator*(const Matrix &rhs) const{
    Matrix product_matrix(rhs.size);
    if(size == rhs.size){
        for(int i = 0; i < rhs.size; i++){
            for(int j = 0; j < rhs.size; j++){
                //product_matrix.data[i][j] = (data[i][i] * rhs.data[i][j]) + (data[i][i] * rhs.data[i][j]);
                int tracker = data[i][j];
                for(int k = 0; k < rhs.size; k++){
                    product_matrix.data[i][k] += tracker * rhs.data[j][k]; //Source: Deepseek AI
                }
            }
            //++k;
        }
    }else{
        cout << "The two matrices are not the same dimensions." << endl;
    }

    return product_matrix;
}

void Matrix::set_value(size_t i, size_t j, int n){
    data[i][j] = n;
}

int Matrix::get_value(size_t i, size_t j) const{
    return data[i][j];
}

int Matrix::get_size() const{
    return size;
}

int Matrix::sum_diagonal_major() const{
    int total = 0;
    int rowCounter = size - 1;
    //int bottom_left = data[size - 1][0];

    for(int i = 0; i < size; i++){
        total += data[rowCounter][i];
        --rowCounter; 
    }
    return total;
    //int top
}

int Matrix::sum_diagonal_minor() const{
    int total = 0;
    int rowCounter = 0;

    for(int i = 0; i < size; i++){
        total += data[rowCounter][i];
        rowCounter++; 
    }
    return total;
}

void Matrix::swap_rows(size_t r1, size_t r2){
    vector<int> row1 = data[r1];
    data[r1] = data[r2];
    data[r2] = row1;
}

void Matrix::swap_cols(size_t c1, size_t c2){
    int element;
    for(int i = 0; i < size; i++){
        element = data[i][c1];
        data[i][c1] = data[i][c2];
        data[i][c2] = element;
    }
}

void Matrix::print_matrix() const {
    // print out the matrix

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << data[i][j];
        }
        cout << "\n" << endl;
    }
}
