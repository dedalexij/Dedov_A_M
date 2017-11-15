#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>

class Matrix
{
public:
 Matrix() = default;
 Matrix(const int& col, const int& row);
 Matrix(const Matrix& matr);
 ~Matrix();
 int& at(const int& icol, const int& irow);
 void colSwap(const int& icol1, const int& icol2);
 void rowSwap(const int& irow1, const int& irow2);
 void operator+=(const Matrix& rhs);
 void operator-=(const Matrix& rhs);

private:
 void OutOfRangeExeption()
 {
  throw "dsd";
 }
 int* ElementPointer(const int& icol, const int& irow);
 int* pdata_{ nullptr };
 int colcap_{ 0 };
 int rowcap_{ 0 };
 int* firstpointer_ = pdata_;

};

Matrix operator+(const Matrix& rhs);
Matrix operator-(const Matrix& rhs);

#endif 
