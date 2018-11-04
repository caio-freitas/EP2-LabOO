#include "Pessoa.h"

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias):
  nome(nome), valorPorHora(valorPorHora), horasDiarias(horasDiarias){
      this->recebePadrao = false;
}

Pessoa::Pessoa(string nome, int horasDiarias):
    nome(nome), horasDiarias(horasDiarias)
{
    this->valorPorHora = valorPorHoraPadrao;
    this->recebePadrao = true;
}

Pessoa::~Pessoa(){
    cout << "Pessoa" << nome << "apagada" << endl;
}

string Pessoa::getNome(){
    return nome;
}

double Pessoa::getValorPorHora(){
    if(recebePadrao){
        if(valorPorHora != Pessoa::valorPorHoraPadrao)
            valorPorHora = valorPorHoraPadrao
        return valorPorHoraPadrao;
    }
    else
        return valorPorHora;
}

int Pessoa::getHorasDiarias(){
    return horasDiarias;
}

/*double Pessoa::getCusto(int dias){
    return this->horasDiarias * this->valorPorHora;
}*/

void Pessoa::imprimir(){
    cout << "Pessoa: " << valorPorHora << " - " << horasDiarias << "h por dia" << endl;
}

bool Pessoa::recebeValorPadrao()
{
    if (recebePadrao)
        return true;
    return false;
}

void Pessoa::setValorPorHoraPadrao(double valor)
{
    if(valor>0) {
        Pessoa::valorPorHoraPadrao = valor;
    }

    else {
        throw new invalid_argument("O valor por hora padrao deve ser um numero positivo")
    /** Precisamos de um Catch na funcao main **/
    }
}

double Pessoa::getValorPorHoraPadrao()
{
    return Pessoa::valorPorHoraPadrao;
}
