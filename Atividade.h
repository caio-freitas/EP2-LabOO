#ifndef ATIVIDADE_H
#define ATIVIDADE_H
#include <string>
#include <iostream>
#include "Recurso.h"


using namespace std;

class Atividade{

public:
    Atividade(string nome);
    virtual ~Atividade();

    virtual string getNome();

    virtual void adicionar(Recurso* r);
    virtual Recurso** getRecursos();
    virtual int getQuantidadeDeRecursos();

    virtual int getDuracao() = 0;
    virtual double getCusto() = 0;

    virtual void terminar(int duracaoReal);
    virtual bool estaTerminada();

    virtual void imprimir();
    static const int MAX_RECURSOS = 10;

protected:
    string nome;
    int duracaoReal;
    Recurso* recursos[MAX_RECURSOS];
    int quantidadeDeRecursos;
    bool terminada;
    virtual bool ehPrazoFixo() = 0;

};

#endif

