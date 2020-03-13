#pragma once

#include "Racional.hpp"
#include "Complejo.hpp"
#include <string>

using namespace std;

template <class T>

class Vector {
    private:
        T x, y, z;
    public:
        Vector();
        Vector(T,T,T);
        Vector<T> operator+(Vector);
        Vector<T> operator*(Vector);
        T getX() {
            return x;
        }
        T getY() {
            return y;
        }
        T getZ() {
            return z;
        }
        string toString();
};


template <class T>
Vector<T> :: Vector() {}

template <class T>
Vector<T> :: Vector(T a, T b, T c) {
    x = a;
    y = b;
    z = c;
}

template <class T>
string Vector<T> :: toString() {
    return "[" + x.toString() + ", " + y.toString() + ", " + z.toString() + "]";
}

template <class T>
Vector<T> Vector<T> :: operator+(Vector<T> v2) {
    T t1 = this -> x + v2.getX();
    T t2 = this -> y + v2.getY();
    T t3 = this -> z + v2.getZ();
    return Vector(t1, t2, t3);
}

template <class T>
Vector<T> Vector<T> :: operator*(Vector<T> v2) {
    T t1 = this -> x * v2.getX();
    T t2 = this -> y * v2.getY();
    T t3 = this -> z * v2.getZ();
    return Vector(t1, t2, t3);
}