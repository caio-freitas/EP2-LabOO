#include <stdexcept>
#include <iostream>
#include <string.h>

class Recurso {
private:
    string nome;
public:
    Recurso(string nome);
    virtual ~Recurso();

    virtual string getNome();
    virtual double getCusto(int dias);
    virtual void imprimir();
};
