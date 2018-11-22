#include "Pessoa.h"

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias):
  Recurso(nome), horasDiarias(horasDiarias){
      if(valorPorHora<=0||horasDiarias<=0) {
        throw new invalid_argument("Erro: Valor por Hora e Horas Diárias devem ser valores positivos!");
        /**
        Precisamos de um Catch na função main
                                            **/
      }
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

double Pessoa::getCusto(int dias){
    if (dias <= 0)
        throw new invalid_argument("dias menor ou igual a 0");
    return this->horasDiarias * this->valorPorHora * this->dias;
}

void Pessoa::imprimir(){
    cout << "Pessoa: " << getNome() << " - R$"<< valorPorHora << " - " << horasDiarias << "h por dia" << endl;
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
bool Pessoa::ehPessoa()
{
    return true;
}


