#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

class Array
{
public:
 Array() = default;
 Array(const int& length);
 Array(Array& newArray);
 ~Array();

 int& operator[](const int& i);
 void Add(const int& value);

private:
 ptrdiff_t capacity_{ 0 };
 ptrdiff_t size_{ 0 };
 int* pdata_{ nullptr };
};
#endif
