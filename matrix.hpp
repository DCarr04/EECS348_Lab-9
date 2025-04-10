#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <string>

// all of your function definitions should be in this file now

class Matrix {
private: 
    size_t size;
    /*
    template <typename T>
    class Vector {
    public:
        std::vector<T> data;
        Vector(size_t n) : data(n) {}
        T& operator[](size_t i) { return data[i]; }
        const T& operator[](size_t i) const { return data[i]; }
    };*/
    
public:
    
    std::vector<std::vector<int> > data;
    //template <typename T>
   // using DataType = std::vector<Vector<T>>;

    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<int> > nums);
    ~Matrix();

    template <typename T>
    Matrix addition(const Matrix &rhs) const;

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, int n);
    int get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
};

#endif // __MATRIX_HPP__
