#include <iostream>
#include "banco.hpp"

using namespace std;

int main() {
    cout << "\n=== Creación de Cuentas ===" << endl;
    cout << "Creo cuenta de ahorro para Juan con $1000" << endl;
    CuentaAhorro cajaAhorro = CuentaAhorro("Juan", 1000);
    cout << "Estado inicial de la cuenta:" << endl;
    cajaAhorro.mostrarInfo();

    cout << "\n=== Test de Retiros en CuentaAhorro ===" << endl;
    cout << "Intentando retirar $200 (debería ser exitoso)..." << endl;
    cajaAhorro.retirar(200);
    cout << "Balance después del retiro (ultimo mostrarInfo sin cargo):" << endl;
    cajaAhorro.mostrarInfo();

    cout << "\n=== Test de Retiro Excesivo en CuentaAhorro ===" << endl;
    cout << "Intentando retirar $1000 (debería fallar por fondos insuficientes)..." << endl;
    cajaAhorro.retirar(1000);
    cout << "Balance después del intento de retiro:" << endl;
    cajaAhorro.mostrarInfo();

    cout << "\n=== Test de Creación de CuentaCorriente ===" << endl;
    cout << "Creo cuenta corriente vinculada a la caja de ahorro con $80..." << endl;
    CuentaCorriente cuentaCorriente = CuentaCorriente(&cajaAhorro);
    cuentaCorriente.depositar(80);
    cout << "Estado inicial de la cuenta corriente:" << endl;
    cuentaCorriente.mostrarInfo();

    cout << "\n=== Test de Retiro en CuentaCorriente ===" << endl;
    cout << "Intento retirar $50 (debería ser exitoso)..." << endl;
    cuentaCorriente.retirar(50);
    cout << "Intentando retirar $100 (debería usar fondos de caja de ahorro)..." << endl;
    cuentaCorriente.retirar(100);
    cout << "Estado de cuenta corriente:" << endl;
    cuentaCorriente.mostrarInfo();
    cout << "Estado de caja de ahorro:" << endl;
    cajaAhorro.mostrarInfo();

    cout << "\n=== Test de Retiro Excesivo en Ambas Cuentas ===" << endl;
    cout << "Intentando retirar $2000 (debería fallar en ambas cuentas)..." << endl;
    cuentaCorriente.retirar(2000);
    cout << "Estado final de ambas cuentas:" << endl;
    cout << "Cuenta Corriente:" << endl;
    cuentaCorriente.mostrarInfo();
    cout << "Caja de Ahorro:" << endl;
    cajaAhorro.mostrarInfo();

    cout << "\n=== Test de Depósito ===" << endl;
    cout << "Juan le pego al Quini (Le aparecen $10000 en ambas cuentas)" << endl;
    cajaAhorro.depositar(10000);
    cuentaCorriente.depositar(10000);
    cout << "Balance final (Caja de Ahorro):" << endl;
    cajaAhorro.mostrarInfo();
    cout << "Balance final (Cuenta Corriente):" << endl;
    cuentaCorriente.mostrarInfo();

    return 0;
}