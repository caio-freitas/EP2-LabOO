#ifndef PROJETO_H
#define PROJETO_H
#include <string>
#include <iostream>
#include "Atividade.h"

using namespace std;

class Projeto{

public:
    Projeto(string nome);
    virtual ~Projeto();
    virtual string getNome();

    virtual void adicionar(Atividade* a);
    virtual vector<Atividade*>* getAtividades();
    virtual void adicionar(Recurso* r);
    virtual list<Recurso*>* getRecursos();

    virtual int getDuracao();
    virtual int getDuracao(bool terminadas);
    virtual double getCusto();
    virtual void imprimir();

protected:
    vector<Atividade*>* atividades = new vector<Atividade*>();
    list<Recursos*>* recursos = new list<Recurso*>();
    string nome;
    bool terminadas;
};

#endif // PROJETO_H
