#include "Recurso.h"


class Ferramenta : public Recurso{
private:
    double custoDiario;

public:
    Ferramenta(string nome, double custoDiario);
    virtual ~Ferramenta();

    virtual double getCustoDiario();
    void imprimir();
    double getCusto();
};
