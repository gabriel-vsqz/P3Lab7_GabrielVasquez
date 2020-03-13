#pragma once

#include <string>

using namespace std;

class Complejo {
    private:
        int p_real, p_imaginario;
    public:
        Complejo();
        Complejo(int, int);
        Complejo operator+(Complejo);
        Complejo operator*(Complejo);
        int getP_Real() {
            return p_real;
        }
        int getP_Imaginario() {
            return p_imaginario;
        }
        string toString();
        Complejo Distribuir(Complejo, Complejo);
};

Complejo :: Complejo() {
}

Complejo :: Complejo(int real, int imag) {
    p_real = real;
    p_imaginario = imag;
}

Complejo Complejo :: operator+(Complejo r2) {
    int nReal = this -> p_real + r2.getP_Real();
    int nImag = this -> p_imaginario + r2.getP_Imaginario();
    Complejo otro(nReal, nImag);
    return otro;
}

Complejo Complejo :: Distribuir(Complejo a, Complejo b) {
    int t1 = a.getP_Real() * b.getP_Real(); //REAL
    int t2 = a.getP_Real() * b.getP_Imaginario(); //IMAGINARIO
    int t3 = a.getP_Imaginario() * b.getP_Real(); //IMAGINARIO
    int t4 = a.getP_Imaginario() * b.getP_Imaginario() * -1; //REAL
    int defT1 = t1 + t4;
    int defT2 = t2 + t3;
    Complejo nuevo(defT1, defT2);
    return nuevo;
}

Complejo Complejo :: operator*(Complejo r2) {
    Complejo otro = Distribuir(*this, r2);
    return otro;
}

string Complejo :: toString() {
    if (p_imaginario > 0)
        return to_string(p_real) + "+" + to_string(p_imaginario) + "i";
    else
        return to_string(p_real) + to_string(p_imaginario) + "i";
}