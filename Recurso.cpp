#include "Recurso.h"

Recurso::Recurso(string nome):
    nome(nome)
{

}

Recurso::~Recurso() {

}


string Recurso::getNome() {
    return this->nome;
}

double Recurso::getCusto(int dias) {
    /** Função a ser implementada nas subclasses **/
}

void Recurso::imprimir() {
    cout << this->nome << " - R$" << this->getCusto() << " por dia" << endl;
}
