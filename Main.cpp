#include "Vector.hpp"
#include "Racional.hpp"
#include "Complejo.hpp"
#include <iostream>
#include <vector>

using namespace std;

vector<Vector<Racional>> racionales;
vector<Vector<Complejo>> complejos;

Vector<Racional> actualR1;
Vector<Racional> actualR2;
Vector<Complejo> actualC1;
Vector<Complejo> actualC2;

int contR = 0, contC = 0;

void declararRacional() {
    int n1, d1, n2, d2, n3, d3;
    
    cout << "Ingrese Numerador 1° Término: ";
    cin >> n1;
    cout << "Ingrese Denominador 1° Término: ";
    cin >> d1;
    while (d1 == 0) {
        cout << "WOAH. El denominador no puede ser 0...\nIngrese otro: ";
        cin >> d1;
    }
    Racional R1(n1, d1);

    cout << "Ingrese Numerador 2° Término: ";
    cin >> n2;
    cout << "Ingrese Denominador 2° Término: ";
    cin >> d2;
    while (d2 == 0) {
        cout << "WOAH. El denominador no puede ser 0...\nIngrese otro: ";
        cin >> d2;
    }
    Racional R2(n2, d2);

    cout << "Ingrese Numerador 3° Término: ";
    cin >> n3;
    cout << "Ingrese Denominador 3° Término: ";
    cin >> d3;
    while (d3 == 0) {
        cout << "WOAH. El denominador no puede ser 0...\nIngrese otro: ";
        cin >> d3;
    }
    Racional R3(n3, d3);

    Vector<Racional> nuevo(R1, R2, R3);
    contR++;
    racionales.push_back(nuevo);
}

void declararComplejo() {
    int r1, i1, r2, i2, r3, i3;

    cout << "Ingrese la parte real del 1° Término: ";
    cin >> r1;
    cout << "Ingrese la parte imaginaria del 1° Término: ";
    cin >> i1;
    Complejo C1(r1, i1);

    cout << "Ingrese la parte real del 2° Término: ";
    cin >> r2;
    cout << "Ingrese la parte imaginaria del 2° Término: ";
    cin >> i2;
    Complejo C2(r2, i2);

    cout << "Ingrese la parte real del 3° Término: ";
    cin >> r3;
    cout << "Ingrese la parte imaginaria del 3° Término: ";
    cin >> i3;
    Complejo C3(r3, i3);

    Vector<Complejo> nuevo(C1, C2, C3);
    contC++;
    complejos.push_back(nuevo);
}

void Listar(bool R, bool C) {
    if (R) {
        cout << "\nVectores Racionales:\n";
        for (int i = 0; i < racionales.size(); i++) {
            cout << "   " << i << ". " << racionales.at(i).toString();
            if (i != racionales.size() - 1)
                cout << ",";
        }
    }

    if (C) {
        cout << "\n\nVectores Complejos:\n";
        for (int i = 0; i < complejos.size(); i++) {
            cout << "   " << i << ". " << complejos.at(i).toString();
            if (i != complejos.size() - 1)
                cout << ",";
        }
    }
    cout << endl;
}

void OperarRacionales() {
    Vector<Racional> respuesta;
    respuesta = actualR1 + actualR2;
    cout << respuesta.toString();
}

void OperarComplejos() {
    Vector<Complejo> respuesta;
    respuesta = actualC1 + actualC2;
    cout << respuesta.toString();
}

int main() {
    bool pass = true;
    int opcion;
    while (pass) {
        cout << "\n1. Ingresar Vector\n2. Listar Vectores\n3. Operar Vectores\n4. Salir\n: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                int tipo_vector;
                cout << "\n¿Qué tipo de vector desea ingresar?\n1. Racional\n2. Complejo\n: ";
                cin >> tipo_vector;
                while (tipo_vector < 1 && tipo_vector > 2) {
                    cout << "Debe ingresar uno de los dos tipos que se le presentan.\n1. Racional\n2. Complejo\n: ";
                    cin >> tipo_vector;
                }
                if (tipo_vector == 1 && contR < 3)
                    declararRacional();
                if (tipo_vector == 2 && contC < 3)
                    declararComplejo();
            } break;
            
            case 2: {
                Listar(true, true);
            } break;
            
            case 3: {
                int tipo_vector;
                cout << "\n¿Qué tipo de vector desea operar?\n1. Racional\n2. Complejo\n: ";
                cin >> tipo_vector;
                while (tipo_vector < 1 && tipo_vector > 2) {
                    cout << "Debe ingresar uno de los dos tipos que se le presentan.\n1. Racional\n2. Complejo\n: ";
                    cin >> tipo_vector;
                }
                if (tipo_vector == 1 && racionales.size() > 0) {
                    Listar(true, false);
                    cout << endl;
                    int pos1, pos2;
                    cout << "Elija Vector 1: ";
                    cin >> pos1;
                    while (pos1 < 0 && pos1 > racionales.size() - 1) {
                        cout << "Debe ingresar uno de los vectores registrados.\n: ";
                        cin >> pos1;
                    }
                    cout << "Elija Vector 2: ";
                    cin >> pos2;
                    while (pos2 < 0 && pos2 > racionales.size() - 1) {
                        cout << "Debe ingresar uno de los vectores registrados.\n: ";
                        cin >> pos2;
                    }
                    racionales.at(pos1) = actualR1;
                    racionales.at(pos2) = actualR2;
                    OperarRacionales();
                    cout << endl;
                }
                else if (tipo_vector == 2 && complejos.size() > 0) {
                    Listar(false, true);
                    cout << endl;
                    int pos1, pos2;
                    cout << "Elija Vector 1: ";
                    cin >> pos1;
                    while (pos1 < 0 && pos1 > complejos.size() - 1) {
                        cout << "Debe ingresar uno de los vectores registrados.\n: ";
                        cin >> pos1;
                    }
                    cout << "Elija Vector 2: ";
                    cin >> pos2;
                    while (pos2 < 0 && pos2 > complejos.size() - 1) {
                        cout << "Debe ingresar uno de los vectores registrados.\n: ";
                        cin >> pos2;
                    }
                    complejos.at(pos1) = actualC1;
                    complejos.at(pos2) = actualC2;
                    OperarComplejos();
                    cout << endl;
                } else {
                    cout << "No hay vectores de este tipo para poder operar." << endl;
                }
            } break;
            
            case 4: {
                pass = false;
            } break;
            
            default: {
                cout << "Debe ingresar una de las opciones que se le presentan." << endl;
            } break;
        }
    }
    cout << endl;
}