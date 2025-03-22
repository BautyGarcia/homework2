#include <iostream>
#include "banco.hpp"

using namespace std;

CuentaBancaria::CuentaBancaria(string titular, double balance) : titular(titular), balance(balance) {}

CuentaAhorro::CuentaAhorro(string titular, double balance) : CuentaBancaria(titular, balance) {}

CuentaCorriente::CuentaCorriente(CuentaAhorro* cuentaAhorro) : CuentaBancaria(cuentaAhorro->titular, 0), cuentaAhorro(cuentaAhorro) {}

void CuentaAhorro::mostrarInfo() {
    this->contadorMostrarInfo++;

    if (this->contadorMostrarInfo > this->LIMITE_MOSTRAR) {
        cout << "No se puede mostrar info mas de " << this->LIMITE_MOSTRAR << " veces, se cobrará un cargo de " << this->COSTO_MOSTRAR << "€" << endl;
        this->retirar(this->COSTO_MOSTRAR);
        return;
    }

    cout << "Titular: " << this->titular << endl;
    cout << "Balance: " << this->getBalance() << endl;
}

void CuentaAhorro::retirar(double cantidad) {
    if (this->getBalance() - cantidad < 0) {
        cout << "No se puede retirar " << cantidad << "$, el balance es " << this->getBalance() << "$" << endl;
        return;
    }
    this->setBalance(this->getBalance() - cantidad);
}

void CuentaCorriente::mostrarInfo() {
    cout << "Titular: " << this->titular << endl;
    cout << "Balance: " << this->getBalance() << endl;
}

void CuentaCorriente::retirar(double cantidad) {
    if (this->getBalance() - cantidad > 0) {
        this->retirar(cantidad);
        cout << "Se retiraron los " << cantidad << "$ de la cuenta corriente" << endl;
        return;
    }

    cout << "No hay fondos suficientes en la cuenta corriente" << endl;

    if (this->cuentaAhorro->getBalance() - cantidad > 0) {
        this->cuentaAhorro->retirar(cantidad);
        cout << "Se retiraron los " << cantidad << "$ de la cuenta ahorro" << endl;
        return;
    }

    cout << "No se pudo realizar la operacion, estas seco" << endl;
}
    