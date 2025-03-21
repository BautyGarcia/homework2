#include <string>

using namespace std;

class Numero {
    public:
        virtual Numero* suma(Numero* otro) = 0;
        virtual Numero* resta(Numero* otro) = 0;
        virtual Numero* multiplicacion(Numero* otro) = 0;
        virtual string toString() const = 0;
        virtual ~Numero() = default;
};

class Entero : public Numero {
    private:
        int valor;
    public:
        Entero(int valor);
        Numero* suma(Numero* otro) override;
        Numero* resta(Numero* otro) override;
        Numero* multiplicacion(Numero* otro) override;
        string toString() const override;
        int getValor() const { return valor; };
        ~Entero() override = default;
};

class Real : public Numero {
    private:
        double valor;
    public:
        Real(double valor);
        Numero* suma(Numero* otro) override;
        Numero* resta(Numero* otro) override;
        Numero* multiplicacion(Numero* otro) override;
        string toString() const override;
        double getValor() const { return valor; };
        ~Real() override = default;
};

class Complejo : public Numero {
    private:
        double real;
        double imaginario;
    public:
        Complejo(double real, double imaginario);
        Numero* suma(Numero* otro) override;
        Numero* resta(Numero* otro) override;
        Numero* multiplicacion(Numero* otro) override;
        string toString() const override;
        double getReal() const { return real; }
        double getImaginario() const { return imaginario; }
        ~Complejo() override = default;
};