#include <iostream>
#include "banco.hpp"

using namespace std;

int main() {
    // Create accounts
    CuentaAhorro* cajaAhorro = new CuentaAhorro("Juan", 1000);
    CuentaCorriente* cuentaCorriente = new CuentaCorriente(cajaAhorro);

    cout << "\n=== Test CuentaAhorro ===" << endl;
    cajaAhorro->retirar(200);
    
    //cajaAhorro->mostrarInfo();  // First display
    //cajaAhorro->mostrarInfo();  // Second display
    //cajaAhorro->mostrarInfo();  // Third display (should charge fee)
    
    cout << "\n=== Test CuentaCorriente withdrawals ===" << endl;
    cuentaCorriente->retirar(100);  // Should withdraw from CuentaAhorro
    //cajaAhorro->mostrarInfo();      // Check remaining balance
    
    cout << "\n=== Test insufficient funds ===" << endl;
    cuentaCorriente->retirar(2000); // Should fail - not enough money

    // Clean up
    delete cajaAhorro;
    delete cuentaCorriente;
    
    return 0;
}