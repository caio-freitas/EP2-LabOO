#include "Ferramenta.h"

Ferramenta::Ferramenta(string nome, double custoDiario):
    nome(nome), custoDiario(custoDiario)
{}

Ferramenta::~Ferramenta()
{
    cout << "Ferramenta deletada" << endl;
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
bool Ferramenta::ehPessoa()
{
    return false;
}
