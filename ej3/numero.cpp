#include "numero.hpp"

Entero::Entero(int valor) : valor(valor) {}

Numero* Entero::suma(Numero* otro) {
    Entero* entero = dynamic_cast<Entero*>(otro);
    if (entero == nullptr) {
        return nullptr;
    }
    return new Entero(this->valor + entero->getValor());
}

Numero* Entero::resta(Numero* otro) {
    Entero* entero = dynamic_cast<Entero*>(otro);
    if (entero == nullptr) {
        return nullptr;
    }
    return new Entero(this->valor - entero->getValor());
}

Numero* Entero::multiplicacion(Numero* otro) {
    Entero* entero = dynamic_cast<Entero*>(otro);
    if (entero == nullptr) {
        return nullptr;
    }
    return new Entero(this->valor * entero->getValor());
}

string Entero::toString() const {
    return to_string(this->valor);
}

Real::Real(double valor) : valor(valor) {}

Numero* Real::suma(Numero* otro) {
    Real* entero = dynamic_cast<Real*>(otro);
    if (entero == nullptr) {
        return nullptr;
    }
    return new Real(this->valor + entero->getValor());
}

Numero* Real::resta(Numero* otro) {
    Real* entero = dynamic_cast<Real*>(otro);
    if (entero == nullptr) {
        return nullptr;
    }
    return new Real(this->valor - entero->getValor());
}

Numero* Real::multiplicacion(Numero* otro) {
    Real* entero = dynamic_cast<Real*>(otro);
    if (entero == nullptr) {
        return nullptr;
    }
    return new Real(this->valor * entero->getValor());
}

string Real::toString() const {
    return to_string(this->valor);
}

Complejo::Complejo(double real, double imaginario) : real(real), imaginario(imaginario) {}

Numero* Complejo::suma(Numero* otro) {
    Complejo* complejo = dynamic_cast<Complejo*>(otro);
    if (complejo == nullptr) {
        return nullptr;
    }
    return new Complejo(this->real + complejo->getReal(), this->imaginario + complejo->getImaginario());
}

Numero* Complejo::resta(Numero* otro) {
    Complejo* complejo = dynamic_cast<Complejo*>(otro);
    if (complejo == nullptr) {
        return nullptr;
    }
    return new Complejo(this->real - complejo->getReal(), this->imaginario - complejo->getImaginario());
}

Numero* Complejo::multiplicacion(Numero* otro) {
    Complejo* complejo = dynamic_cast<Complejo*>(otro);
    if (complejo == nullptr) {
        return nullptr;
    }
    return new Complejo(this->real * complejo->getReal() - this->imaginario * complejo->getImaginario(), this->real * complejo->getImaginario() + this->imaginario * complejo->getReal());
}

string Complejo::toString() const {
    return to_string(this->real) + " + " + to_string(this->imaginario) + "i";
}
