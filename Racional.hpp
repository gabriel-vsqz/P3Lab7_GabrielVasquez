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
        Racional Simplificar(int, int);
};

Racional :: Racional() {    
}

Racional :: Racional(int num, int den) {
    numerador = num;
    denominador = den;
}

Racional Racional :: Simplificar(int numerador, int denominador) {
    if(denominador != 1){
        int factor = 2;
        while(factor <= numerador){
            if(denominador % factor == 0 && numerador % factor == 0){
                denominador = denominador / factor;
                numerador = numerador / factor;
            } else{
                factor++;
            }
        }
    }
    return Racional(numerador, denominador);
}

Racional Racional :: operator+(Racional r2) {
    int nNum = (this -> numerador * r2.getDenominador()) + (r2.getNumerador() * this -> denominador);
    int nDen = this -> denominador * r2.getDenominador();
    //Racional otro(nNum, nDen);
    Racional otro = Simplificar(nNum, nDen);
    return otro;
}

Racional Racional :: operator*(Racional r2) {
    int nNum = this -> numerador * r2.getNumerador();
    int nDen = this -> denominador * r2.getDenominador();
    //Racional otro = Simplificar(nNum, nDen);
    Racional otro = Simplificar(nNum, nDen);
    return otro;
}

string Racional :: toString() {
    return to_string(numerador) + "/" + to_string(denominador);
}