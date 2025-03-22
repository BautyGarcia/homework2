#include <string>

using namespace std;

class CuentaBancaria {
    private:
        double balance;
    protected:
        string titular;
        double getBalance() const { return balance; };
        void setBalance(double balance) { this->balance = balance; };
    public:
        CuentaBancaria(string titular, double balance);
        void depositar(double cantidad);
        virtual void retirar(double cantidad) = 0;
        virtual void mostrarInfo() = 0;
        virtual ~CuentaBancaria() = default;
};

class CuentaAhorro : public CuentaBancaria {
    private:
        int contadorMostrarInfo = 0;
        static const int COSTO_MOSTRAR = 20;
        static const int LIMITE_MOSTRAR = 2;
        void mostrarInfo() override;
    public:
        void retirar(double cantidad) override;
        CuentaAhorro(string titular, double balance);
        friend class CuentaCorriente;
};

class CuentaCorriente : public CuentaBancaria {
    private:
        void mostrarInfo() override;
        CuentaAhorro* cuentaAhorro;
    public:
        void retirar(double cantidad) override;
        bool tieneFondosSuficientes(CuentaAhorro* cuentaAhorro, double cantidad) const;
        CuentaCorriente(CuentaAhorro* cuentaAhorro);
};
