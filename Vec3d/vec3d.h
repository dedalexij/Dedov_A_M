#ifndef VEC3D.H
#define VEC3D.H

#include <iostream>
#include <istream>

struct Vec3d
{
 int x{ 0 };
 int y{ 0 };
 int z{ 0 };

 Vec3d() {};
 Vec3d(const int& xV, const int& yV, const int& zV);
 Vec3d(const Vec3d& vec);
// ~Vec3d();

 Vec3d& operator+=(const Vec3d& rhs);
 Vec3d& operator-=(const Vec3d& rhs);
 Vec3d& operator*=(const Vec3d& rhs);
 Vec3d& operator*=(const int& rhs);
 Vec3d& operator/=(const Vec3d rhs);
 Vec3d& operator/=(const int& rhs);

 
};


Vec3d& operator+(const Vec3d& a, const Vec3d& b);
Vec3d& operator-(const Vec3d& a, const Vec3d& b);
Vec3d& operator*(const Vec3d& a, const Vec3d& b);
Vec3d& operator/(const Vec3d& a, const Vec3d& b);

#endif

