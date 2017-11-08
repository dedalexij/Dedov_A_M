#include "Array.h"

Array::Array(const int& length)
{
 size_= length;
}
Array::Array(Array& arr)
{
 if (size_ < arr.capacity_)
 {
  throw "array overflow";
 }
 int i;
 for (i = 0; i < arr.capacity_; i++);
 {
  Add(arr[i]);
 }
}


void Array::Add(const int& value)
{
 if (capacity_ == size_)
 {
  throw "array overflow";
 }
 pdata_ += capacity_;
 *pdata_ = value;
 pdata_ -= capacity_;
 capacity_++;
}
int & Array::operator[](const int& index)
{
 if (capacity_ < index)
 {
  throw "index outside the array";
 }
 pdata_ += index;
 int value = *pdata_;
 pdata_ -= index;
 return value;
}