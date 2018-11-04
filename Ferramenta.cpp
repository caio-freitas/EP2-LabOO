#include "Ferramenta.h"

Ferramenta::Ferramenta(string nome, double custoDiario):
    nome(nome), custoDiario(custoDiario)
{

}

Ferramenta::~Ferramenta()
{

}

double Ferramenta::getCustoDiario()
{
    return this->custoDiario;
}

void Ferramenta::imprimir() {
    cout << "Ferramenta: ";
    Recurso::imprimir();
}

double Ferramenta::getCusto() {
    return this->custoDiario;
}
