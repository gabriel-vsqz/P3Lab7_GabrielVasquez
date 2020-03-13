#pragma once

#include <string>

using namespace std;

class Complejo {
    private:
        int p_real, p_imaginaria;
    public:
        Complejo();
        Complejo(int, int);
        Complejo &operator+(Complejo);
        Complejo &operator*(Complejo);
        int getP_Real() {
            return p_real;
        }
        int getP_Imaginaria() {
            return p_imaginaria;
        }
        string toString();
};

Complejo :: Complejo() {
}

Complejo :: Complejo(int real, int imag) {
    p_real = real;
    p_imaginaria = imag;
}

Complejo &Complejo :: operator+(Complejo r2) {

}

Complejo &Complejo :: operator*(Complejo r2) {

}

string Complejo :: toString() {
    return to_string(p_real) + to_string(p_imaginaria) + "i";
}