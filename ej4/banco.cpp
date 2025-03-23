#include <iostream>
#include "banco.hpp"

using namespace std;

CuentaBancaria::CuentaBancaria(string titular, double balance) : titular(titular), balance(balance) {}

CuentaAhorro::CuentaAhorro(string titular, double balance) : CuentaBancaria(titular, balance) {}

CuentaCorriente::CuentaCorriente(CuentaAhorro* cuentaAhorro) : CuentaBancaria(cuentaAhorro->titular, 0), cuentaAhorro(cuentaAhorro) {}

void CuentaBancaria::depositar(double cantidad) {
    this->balance += cantidad;
}

void CuentaAhorro::mostrarInfo() {
    this->contadorMostrarInfo++;

    if (this->contadorMostrarInfo > this->LIMITE_MOSTRAR) {
        cout << "No se puede mostrar info mas de " << this->LIMITE_MOSTRAR << " veces, se cobrará un cargo de " << this->COSTO_MOSTRAR << "$" << endl;
        this->retirar(this->COSTO_MOSTRAR);
    }

    cout << "Titular: " << this->titular << endl;
    cout << "Balance: " << this->balance << "$" << endl;
}

void CuentaAhorro::retirar(double cantidad) {
    if (this->balance - cantidad < 0) {
        cout << "No se puede retirar " << cantidad << "$, el balance es " << this->balance << "$" << endl;
        return;
    }
    this->balance = this->balance - cantidad;
    cout << "Se retiraron los " << cantidad << "$ de la cuenta ahorro" << endl;
}

void CuentaCorriente::mostrarInfo() {
    cout << "Titular: " << this->titular << endl;
    cout << "Balance: " << this->balance << "$" << endl;
}

void CuentaCorriente::retirar(double cantidad) {
    if (this->balance - cantidad > 0) {
        this->balance = this->balance - cantidad;
        cout << "Se retiraron los " << cantidad << "$ de la cuenta corriente" << endl;
        return;
    }

    cout << "No hay fondos suficientes en la cuenta corriente" << endl;

    if (this->cuentaAhorro->balance - cantidad > 0) {
        this->cuentaAhorro->retirar(cantidad);
        return;
    }

    cout << "No se pudo realizar la operacion, estas seco" << endl;
}
    