#pragma once

#include <string>

using namespace std;

class Racional {
    private:
        int numerador, denominador;
    public:
        Racional();
        Racional(int, int);        
        Racional operator+(Racional);
        Racional operator*(Racional);
        int getNumerador() {
            return numerador;
        }
        int getDenominador() {
            return denominador;
        }
        string toString();
        int obtenerNNUM();
};

Racional :: Racional() {    
}

Racional :: Racional(int num, int den) {
    numerador = num;
    denominador = den;
}

Racional Racional :: operator+(Racional r2) {
    int nNum = (this -> numerador * r2.getDenominador()) + (r2.getNumerador() * this -> denominador);
    int nDen = this -> denominador * r2.getDenominador();
    Racional otro(nNum, nDen);
    //SIMPLIFICAR
    return otro;
}

Racional Racional :: operator*(Racional r2) {
    int nNum = this -> numerador * r2.getNumerador();
    int nDen = this -> denominador * r2.getDenominador();
    Racional otro(nNum, nDen);
    //SIMPLIFICAR
    return otro;
}

string Racional :: toString() {
    return to_string(numerador) + "/" + to_string(denominador);
}