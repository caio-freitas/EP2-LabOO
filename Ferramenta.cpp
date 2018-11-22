#include "Ferramenta.h"

Ferramenta::Ferramenta(string nome, double custoDiario):
    Recurso(nome), custoDiario(custoDiario)
{
    if (custoDiario<=0)
        throw new invalid_argument("custoDiario menor ou igual a 0");
}

Ferramenta::~Ferramenta()
{
    cout << "Ferramenta deletada" << endl;
}

double Ferramenta::getCustoDiario()
{
    return this->custoDiario;
}

void Ferramenta::imprimir() {
    cout << "Ferramenta: " << this->nome << " - R$" << this->getCusto() << " por dia" << endl;
}

double Ferramenta::getCusto(int dias) {
    if (dias <= 0)
        throw new invalid_argument("dias menor ou igual a 0");
    return this->custoDiario * dias;
}
bool Ferramenta::ehPessoa()
{
    return false;
}
