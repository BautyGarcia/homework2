#include <iostream>
#include "numero.hpp"

using namespace std;

void testEnteros() {
    cout << "\n=== Test Enteros ===" << endl;
    Entero e1(5);
    Entero e2(3);
    
    try {
        Numero* suma = e1.suma(&e2);
        Numero* resta = e1.resta(&e2);
        Numero* mult = e1.multiplicacion(&e2);
        
        cout << "e1: " << e1.toString() << endl;
        cout << "e2: " << e2.toString() << endl;
        cout << "Suma: " << suma->toString() << endl;
        cout << "Resta: " << resta->toString() << endl;
        cout << "Multiplicación: " << mult->toString() << endl;
        
        delete suma;
        delete resta;
        delete mult;
    } catch (const exception& e) {
        cout << "Error en la linea " << __LINE__ << " de " << __FILE__ << " Hubo un error: " << e.what() << endl;
    }
}

void testReales() {
    cout << "\n=== Test Reales ===" << endl;
    Real r1(3.14);
    Real r2(2.0);
    
    try {
        Numero* suma = r1.suma(&r2);
        Numero* resta = r1.resta(&r2);
        Numero* mult = r1.multiplicacion(&r2);
        
        cout << "r1: " << r1.toString() << endl;
        cout << "r2: " << r2.toString() << endl;
        cout << "Suma: " << suma->toString() << endl;
        cout << "Resta: " << resta->toString() << endl;
        cout << "Multiplicación: " << mult->toString() << endl;
            
        delete suma;
        delete resta;
        delete mult;
    } catch (const exception& e) {
        cout << "Error en la linea " << __LINE__ << " de " << __FILE__ << " Hubo un error: " << e.what() << endl;
    }
}

void testComplejos() {
    cout << "\n=== Test Complejos ===" << endl;
    Complejo c1(1, 2);
    Complejo c2(3, 4);
    
    try {
        Numero* suma = c1.suma(&c2);
        Numero* resta = c1.resta(&c2);
        Numero* mult = c1.multiplicacion(&c2);
        
        cout << "c1: " << c1.toString() << endl;
        cout << "c2: " << c2.toString() << endl;
        cout << "Suma: " << suma->toString() << endl;
        cout << "Resta: " << resta->toString() << endl;
        cout << "Multiplicación: " << mult->toString() << endl;
            
        delete suma;
        delete resta;
        delete mult;
    } catch (const exception& e) {
        cout << "Error en la linea " << __LINE__ << " de " << __FILE__ << " Hubo un error: " << e.what() << endl;
    }
}

int main() {
    testEnteros();
    testReales();
    testComplejos();
    return 0;
}