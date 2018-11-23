#ifndef RECURSO_H
#define RECURSO_H
#include <stdexcept>
#include <iostream>
#include <string.h>


using namespace std;

class Recurso {
protected:
    string nome;

public:
    Recurso(string nome);
    virtual ~Recurso();

    virtual string getNome();
    virtual double getCusto(int dias)=0;
    virtual void imprimir()=0;
};

#endif
