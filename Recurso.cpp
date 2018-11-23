#include "Recurso.h"
#include "Pessoa.h"

Recurso::Recurso(string nome):
    nome(nome)
{

}

Recurso::~Recurso() {

}


string Recurso::getNome() {
    return this->nome;
}
