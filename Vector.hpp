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
        Vector<T> &operator+(Vector v2);
        Vector<T> &operator*(Vector v2);
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
Vector<T>::Vector() {

}

template <class T>
Vector<T>::Vector(T a, T b, T c) {
    x = a;
    y = b;
    z = c;
}