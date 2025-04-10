#include "matrix.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:
//Matrix::Matrix() : size(0){}
template <typename T>
Matrix<T>::Matrix(size_t N) : size(N){
    // initialize an empty NxN matrix
    //size = N;
    vector<vector<T> > nums(N, vector<T>(N, 0));
    data = nums;
    /*for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            data[i][j] = 0;
        }
    }*/
    //data = nums;
}
template <typename T>
Matrix<T>::Matrix(vector<vector<T> > nums) : data(nums){
    //data = nums;
    size = nums.size();
}
template <typename T>
Matrix<T>::~Matrix(){
    
}
// e.g. for a member function:
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &rhs) const{
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
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const{
    Matrix product_matrix(rhs.size);
    if(size == rhs.size){
        for(int i = 0; i < rhs.size; i++){
            for(int j = 0; j < rhs.size; j++){
                //product_matrix.data[i][j] = (data[i][i] * rhs.data[i][j]) + (data[i][i] * rhs.data[i][j]);
                T tracker = data[i][j];
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
template <typename T>
void Matrix<T>::set_value(size_t i, size_t j, T n){
    data[i][j] = n;
}
template <typename T>
int Matrix<T>::get_value(size_t i, size_t j) const{
    return data[i][j];
}
template <typename T>
int Matrix<T>::get_size() const{
    return size;
}
template <typename T>
int Matrix<T>::sum_diagonal_major() const{
    T total = 0;
    int rowCounter = size - 1;
    //int bottom_left = data[size - 1][0];

    for(int i = 0; i < size; i++){
        total += data[rowCounter][i];
        --rowCounter; 
    }
    return total;
    //int top
}
template <typename T>
int Matrix<T>::sum_diagonal_minor() const{
    int total = 0;
    int rowCounter = 0;

    for(int i = 0; i < size; i++){
        total += data[rowCounter][i];
        rowCounter++; 
    }
    return total;
}
template <typename T>
void Matrix<T>::swap_rows(size_t r1, size_t r2){
    vector<T> row1 = data[r1];
    data[r1] = data[r2];
    data[r2] = row1;
}
template <typename T>
void Matrix<T>::swap_cols(size_t c1, size_t c2){
    T element;
    for(int i = 0; i < size; i++){
        element = data[i][c1];
        data[i][c1] = data[i][c2];
        data[i][c2] = element;
    }
}
template <typename T>
void Matrix<T>::print_matrix() const {
    // print out the matrix

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
}
