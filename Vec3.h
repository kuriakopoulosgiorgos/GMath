#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>


template <class T>
class Vec3 {
public:
    T x, y, z;
    
    Vec3(T x = (T)0.0f, T y = (T)0.0f, T z = (T)0.0f)
    : x(x), y(y), z(z)
    {
    }
    
    
    Vec3(const Vec3<T>& orig) = default;
    Vec3(Vec3<T>&& orig) = default;
    
    
        Vec3<T> operator+(const Vec3<T>& other) const
    {
        return {this->x + other.x, this->y + other.y, this->z + other.z};
    }
    
    
    Vec3<T> operator-(const Vec3<T>& other) const
    {
        return {this->x - other.x, this->y - other.y, this->z - other.z};
    }
    
    
    Vec3<T> operator*(const Vec3<T>& other) const
    {
        return {this->x * other.x, this->y * other.y, this->z * other.z};
    }
    
    
    Vec3<T> operator/(const Vec3<T>& other) const
    {
        return {this->x / other.x, this->y / other.y, this->z / other.z};
    }
    
    
    bool operator==(const Vec3<T>& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }
    
    
    Vec3<T>& operator=(const Vec3<T>& other) = default;
    
    
    
    friend std::ostream& operator<<(std::ostream& os, const Vec3<T>& v)
    {
        return os << "x : " << v.x << " y : " << v.y << " z : " << v.z;
    }
    
    
    T LengthSquared() const
    {
        return x * x + y * y + z * z;
    }
    
    
    T Length() const
    {
        return sqrt(LengthSquared());
    }
    
    
    T DotProduct(const Vec3<T>& other) const
    {
        return x * other.x  + y * other.y + z * other.z;
    }
    
    
    Vec3<T>& Normalize()
    {
        T length = Length();
        x = x / length;
        y = y / length;
        z = z / length;
        return *this;
    }
    
    
    Vec3<T> GetNormalized() const
    {
        T length = Length();
        return { x / length, y / length, z / length };    
    }

    
    virtual ~Vec3() = default;
private:
};

typedef Vec3<float> Vec3F;
#endif /* VEC3_H */

