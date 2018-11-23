#include "Atividade.h"

Atividade::Atividade (string nome) : nome(nome){
    this->quantidadeDeRecursos = 0;
    this->terminada = false;
}

Atividade::~Atividade(){
    cout << "deletada" << endl;
}

void Atividade::adicionar(Recurso *r){
    if (this->getQuantidadeDeRecursos() > MAX_RECURSOS)
        throw new overflow_error("Ultrapassou limite de recursos");
    recursos[this->getQuantidadeDeRecursos()] = r;
    quantidadeDeRecursos++;
}

string Atividade::getNome()
 {
     return this->nome;
 }

int Atividade::getQuantidadeDeRecursos(){
    return this->quantidadeDeRecursos;
}

double Atividade::getCusto() {
    double custo = 0;
    for (int i=0; i<getQuantidadeDeRecursos(); i++){
            custo = custo + recursos[i]->getCusto(getDuracao());
        }
    return getDuracao() * custo;
}

 Recurso** Atividade::getRecursos(){
    return recursos;
 }

 void Atividade::terminar(int duracaoReal){
    if (duracaoReal <= 0)
        throw new invalid_argument("duracao real menor que 0");
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

