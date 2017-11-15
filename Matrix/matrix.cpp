#include "matrix.h";

Matrix::Matrix(const int& col, const int& row)
{
 colcap_ = col;
 rowcap_ = row;
}

Matrix::Matrix(const Matrix& matr)
{
 colcap_ = matr.colcap_;
 rowcap_ = matr.rowcap_;
 pdata_ = matr.pdata_;
 firstpointer_ = matr.firstpointer_;
}

Matrix::~Matrix()
{

}

//Matrix::operator+=(const Matrix& rhs)
//{
//
//}


int* Matrix::ElementPointer(const int& icol, const int& irow)
{
 pdata_ += irow*colcap_ + icol;
 int* pointer = pdata_;
 pdata_ = firstpointer_;
 return pointer;
}

int& Matrix::At(const int& icol, const int& irow)
{
 try
 {
  int* pointer = ElementPointer(icol, irow);
  return *pointer;
 }
 catch (const std::exception&)
 {

 }
}