#pragma once

#include <string>

using namespace std;

class Racional {
    private:
        int numerador, denominador;
    public:
        Racional();
        Racional(int, int);        
        Racional &operator+(Racional);
        Racional &operator*(Racional);
        int getNumerador() {
            return numerador;
        }
        int getDenominador() {
            return denominador;
        }
        string toString();
};

Racional :: Racional() {    
}

Racional :: Racional(int num, int den) {
    numerador = num;
    denominador = den;
}

Racional &Racional :: operator+(Racional r2) {
    
}

Racional &Racional :: operator*(Racional r2) {

}

string Racional :: toString() {
    return to_string(numerador) + "/" + to_string(denominador);
}