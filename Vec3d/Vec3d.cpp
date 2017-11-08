#include "vec3d.h";

Vec3d::Vec3d(const int& xV, const int& yV, const int& zV)
{
 x = xV;
 y = yV;
 z = zV;
}
Vec3d::Vec3d(const Vec3d& vec)
{
 x = vec.x;
 y = vec.y;
 z = vec.z;
}


Vec3d& Vec3d::operator+=(const Vec3d& rhs)
{
 x += rhs.x;
 y += rhs.y;
 z += rhs.z;
 return *this;
}
Vec3d& Vec3d::operator-=(const Vec3d& rhs)
{
 x -= rhs.x;
 y -= rhs.y;
 z -= rhs.z;
 return *this;
}
Vec3d& Vec3d::operator*=(const int& rhs)
{
 x *= rhs;
 y *= rhs;
 z *= rhs;
 return *this;
}
Vec3d& Vec3d::operator/=(const int& rhs)
{
 x /= rhs;
 y /= rhs;
 z /= rhs;
 return *this;
}


Vec3d& operator+(Vec3d& lhs, Vec3d& rhs)
{
 Vec3d newVec(lhs);
 newVec += rhs;
 return newVec;
}
Vec3d& operator-(Vec3d& lhs, Vec3d& rhs)
{
 Vec3d newVec(lhs);
 newVec -= rhs;
 return newVec;
}