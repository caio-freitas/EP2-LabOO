#include "Projeto.h"

Projeto::Projeto(string nome) : nome(nome)
{

}

string Projeto::getNome()
{
    return this->nome;
}

void Projeto::adicionar(Atividade* a)
{
    atividades->push_back(a);
}

vector* Projeto::getAtividades()
{
    return atividades;
}

void Projeto::adicionar(Recurso* r)
{
    // colocar invalid argument se recurso ja foi adicionado
    recursos->push_back(r);
}

list* Projeto::getRecursos()
{
    return recursos;
}

int Projeto::getDuracao()
{
    double duracao = 0;
    for (unsigned int i = 0; i < atividades->size(); i++){
        duracao = duracao + atividades->at(i)->getDuracao();
    }
}

int Projeto::getDuracao(bool terminadas)
{
    double duracao = 0;
        if(terminadas){
            for (unsigned int i = 0; i < atividades->size(); i++){
                if (atividade->at(i)->estaTerminada())
                    duracao = duracao + atividades->at(i)->getDuracao();
            }
        else{
            for (unsigned int i = 0; i < atividades->size(); i++){
                if (!atividade->at(i)->estaTerminada())
                    duracao = duracao + atividades->at(i)->getDuracao();
            }
}

double Projeto::getCusto()
{
    double custo = 0;
    for (unsigned int i = 0; i < atividades->size(); i++){
        custo = custo + atividades->at(i)->getCusto();
    }
}

void Projeto::imprimir()
{
    cout << getNome() << " - R$" << getCusto() << endl;
    cout << "Duracao:" << endl;
    cout << "- Feito " << getDuracao(true) << " dias" << endl;
    cout << "- Falta " << getDuracao(false) << " dias" << endl;
    cout << "- Total " << getDuracao() << " dias" << endl;
    cout << "----" << endl;
    for (unsigned i=0; i < atividades->size(); i++){
        atividade->at(i)->imprimir();
    }

}
