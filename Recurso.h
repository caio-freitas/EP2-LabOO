#include <stdexcept>
#include <iostream>
#include <string.h>

using namespace std;

class Recurso {
protected:
    string nome;
    virtual bool ehPessoa()=0;
public:
    Recurso(string nome);
    virtual ~Recurso();

    virtual string getNome();
    virtual double getCusto(int dias);
    virtual void imprimir();
};
