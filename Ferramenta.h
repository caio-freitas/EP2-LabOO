#include "Recurso.h"

using namespace std;

class Ferramenta : public Recurso{
private:
    double custoDiario;
    bool ehPessoa();
    virtual bool ehPessoa();

public:
    Ferramenta(string nome, double custoDiario);
    virtual ~Ferramenta();

    virtual double getCustoDiario();
    virtual void imprimir();
    double getCusto(int dias);
};
