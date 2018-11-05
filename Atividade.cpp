#include "Atividade.h"

Atividade::Atividade (string nome) : nome(nome){
    this->quantidadeDeRecusos = 0;
    this->terminada = false
}

Ãtividade::~Atividade{
    cout << "deletada" << endl;
}

void Atividade::adicionar (Recurso r*){
    if (getQuantidadeRecursos() > MAXIMO_RECURSOS)
        throw new overflow_error("Ultrapassou limite de recursos");
    recurso[getQuantidadeDeRecursos()] = r;
    quantidadeDeRecursos++;
}

int Atividade::getQuantidadeDeRecursos(){
    return this->quantidadeDeRecursos;
}

 Recurso** Atividade::getRecursos(){
    return recursos;
 }

 void Atividade::terminar(int duracaoReal){
    if (duracaoReal <= 0)
        throw new invalid_argument("duracaoReal menor que 0");
    this->terminada = true;
 }

 bool Atividade::estaTerminada(){
    if (terminada)
        return true;
    else
        return false;
 }

 void Atividade::imprimir(){
    cout << this->nome << " - " << getDuracao() << " dias - R$" << getCusto() << endl;
 }
