#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "Types.hpp"
#include <type_traits>
#include <cmath>
#include <iostream>

namespace quick 
{
    class Vector3D;
    class Vector2D;
};

template <typename T = quick::s32>
class Vector3D : public quickObject
{
    static_assert(std::is_integral<T> || std::is_floating_point<T>, "Incorrect template type: coordinates must be numbers.");

    public:
        Vector3D() : x(0), y(0), z(0) 
		{
            _initObject();
        }
        Vector3D(const T &x, const T &y, const T &z) : x(x), y(y), z(z) 
		{
            _initObject();
        }
        Vector3D(const T &value) : x(value), y(value), z(value) 
		{
            _initObject();
        }

        Vector3D(const Vector3D<T> &other) : x(other.x), y(other.y), z(other.z) 
		{
            _initObject();
        }


        Vector3D<T> operator-() const 
		{ 
            return Vector3D<T>(-x, -y, -z);
        }

        Vector3D<T> operator=(const Vector3D<T> &other) 
		{
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }

        Vector3D<T> operator+(const Vector3D &other) const 
		{
            return Vector3D<T>(other.x + x, other.y + y, other.z + z);
        }

        Vector3D<T> &operator+=(const Vector3D &other) 
		{
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        Vector3D<T> operator+(const T &value) const 
		{
            return Vector3D<T>(other.x + value, other.y + value, other.z + value);
        }
        
        Vector3D<T> &operator+=(const T &value) 
		{
            x += value;
            y += value;
            z += value;
            return *this;
        }


        Vector3D<T> operator-(const Vector3D &other) const 
		{
            return Vector3D<T>(other.x - x, other.y - y, other.z - z);
        }
        
        Vector3D<T> &operator-=(const Vector3D &other) 
		{
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }
        
        Vector3D<T> operator-(const T &value) const 
		{
            return Vector3D<T>(other.x - value, other.y - value, other.z - value);
        }

        Vector3D<T> &operator-=(const T &value) 
		{
            x -= value;
            y -= value;
            z -= value;
            return *this;
        }
        

        Vector3D<T> operator*(const Vector3D &other) const 
		{
            return Vector3D<T>(other.x * x, other.y * y, other.z * z);
        }
        
        Vector3D<T> &operator*=(const Vector3D &other) 
		{
            x *= other.x;
            y *= other.y;
            z *= other.z;
            return *this;
        }
        
        Vector3D<T> operator*(const T &value) const 
		{
            return Vector3D<T>(other.x * value, other.y * value, other.z * value);
        }

        Vector3D<T> &operator*=(const T &value) 
		{
            x *= value;
            y *= value;
            z *= value;
            return *this;
        }


        Vector3D<T> operator/(const Vector3D &other) const 
		{
            return Vector3D<T>(other.x / x, other.y / y, other.z / z);
        }

        Vector3D<T> &operator/=(const Vector3D &other) 
		{
            x /= other.x;
            y /= other.y;
            z /= other.z;
            return *this;
        }

        Vector3D<T> operator/(const T &value) const 
		{
            return Vector3D<T>(other.x / value, other.y / value, other.z / value);
        }
        
        Vector3D<T> &operator/=(const T &value) 
		{
            x /= value;
            y /= value;
            z /= value;
            return *this;
        }

        bool operator==(const Vector3D<T> &other) 
		{
            return getNorm() == other.getNorm();
        }

        bool operator<(const Vector3D<T> &other) 
		{
            return getNorm() < other.getNorm();
        }

        bool operator<=(const Vector3D<T> &other) 
		{
            return getNorm() <= other.getNorm();
        }

        bool operator>=(const Vector3D<T> &other) 
		{
            return getNorm() >= other.getNorm();
        }

        bool operator>(const Vector3D<T> &other) 
		{
            return getNorm() >= other.getNorm();
        }

        bool operator!=(const Vector3D<T> &other) 
		{
            return getNorm() != other.getNorm();
        }


        virtual const T &operator[](const quick::u8 &id) 
		{
            return *(&x + (id % 3));
        }


        const T& getNorm() const 
		{
            return std::sqrt(
                std::pow(x, 2) +
                std::pow(y, 2) +
                std::pow(z, 2)
            );
        }


        const T& getDistance(const Vector3D<T> &other) const 
		{
            return std::sqrt(
                std::pow(x - other.x, 2) +
                std::pow(y - other.y, 2) +
                std::pow(z - other.z, 2)
            );
        }
        

        T x;
        T y;
        T z;
    
    private:
        _initObject()
        {
            _typeName = "vector3D";
            _attributes = {
                {"X", quickObject::attribute_t([](void *attribute) -> const std::string & {
                    return std::to_string(*attribute);
                }, &X)},
                {"Y", quickObject::attribute_t([](void *attribute) -> const std::string & {
                    return std::to_string(*attribute);
                }, &Y)},
                {"Z", quickObject::attribute_t([](void *attribute) -> const std::string & {
                    return std::to_string(*attribute);
                }, &Z)}
            };
        }
};

template <typename T = quick::s32>
class Vector2D : public Vector3D
{
    public:
        Vector2D(const T &x, const T &y) : Vector3D<T>(x, y, 0) 
		{}
        Vector2D(const T &value) : Vector3D<T>(value) 
		{}

        Vector2D(const Vector2D &other) : Vector3D(other) 
		{}


        const T &operator[](const quick::u8 &id) final 
		{
            return *(&x + (id % 2));
        }
    
    private:
        T z;

        _initObject()
        {
            _typeName = "vector2D";
            _attributes = {
                {"X", quickObject::attribute_t([](void *attribute) -> const std::string & {
                    return std::to_string(*attribute);
                }, &X)},
                {"Y", quickObject::attribute_t([](void *attribute) -> const std::string & {
                    return std::to_string(*attribute);
                }, &Y)},
            };
        }
};

#endif