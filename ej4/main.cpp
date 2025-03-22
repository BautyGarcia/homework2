#include <iostream>
#include "banco.hpp"

using namespace std;

int main() {
    CuentaAhorro cajaAhorro = CuentaAhorro("Juan", 1000);
    CuentaCorriente cuentaCorriente = CuentaCorriente(&cajaAhorro);

    cout << "\n=== Test CuentaAhorro ===" << endl;
    cajaAhorro.retirar(200);
    
    //cajaAhorro.mostrarInfo();
    //cajaAhorro.mostrarInfo();
    //cajaAhorro.mostrarInfo();
    
    cout << "\n=== Test CuentaCorriente withdrawals ===" << endl;
    cuentaCorriente.retirar(100);
    //cajaAhorro.mostrarInfo();
    
    cout << "\n=== Test insufficient funds ===" << endl;
    cuentaCorriente.retirar(2000);

    return 0;
}4