#include <string>

using namespace std;

class CuentaBancaria {
    // Atributos protegidos para que las subclases puedan acceder a ellos y no tener que hacer getters/setters
    protected:
        string titular;
        double balance;
    // Metodos publicos para que se puedan usar en el main
    public:
        CuentaBancaria(string titular, double balance);
        void depositar(double cantidad);
        virtual void retirar(double cantidad) = 0;
        virtual void mostrarInfo() = 0;
        virtual ~CuentaBancaria() = default;
};

class CuentaAhorro : public CuentaBancaria {
    // Atributos privados para cobrar cuando usas mostrarInfo mas de LIMITE_MOSTRAR (2) veces
    private:
        int contadorMostrarInfo = 0;
        static const int COSTO_MOSTRAR = 20;
        static const int LIMITE_MOSTRAR = 2;
    public:
        void retirar(double cantidad) override;
        void mostrarInfo() override;
        CuentaAhorro(string titular, double balance);
        // Friend class para que la clase CuentaCorriente pueda acceder a los atributos privados de CuentaAhorro
        friend class CuentaCorriente;
};

class CuentaCorriente : public CuentaBancaria {
    private:
        CuentaAhorro* cuentaAhorro;
    public:
        void retirar(double cantidad) override;
        void mostrarInfo() override;
        CuentaCorriente(CuentaAhorro* cuentaAhorro);
};
