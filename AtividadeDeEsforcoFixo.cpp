#include "AtividadeDeEsforcoFixo.h"

AtividadeDeEsforcoFixo::AtividadeDeEsforcoFixo(string nome, int horasNecessarias) :
    nome(nome), horasNecessarias(horasNecessarias){
    if (horasNecessarias <= 0)
        throw new invalid_argument("horas menor que 0");
}

AtividadeDeEsforcoFixo::~AtividadeDeEsforcoFixo(){
    cout << "deletado" << endl;
}
double AtividadeDeEsforcoFixo::getCusto() {
    double custo = 0;
    for (int i=0; i<getQuantidadeDeRecursos(); i++){
            custo = custo + recursos[i]->getCusto();
        }
    return getDuracao() * custo;
}
int AtividadeDeEsforcoFixo::getDuracao(){ // TEM QUE USAR PESSOAS E N RECURSOS DA PRA COLOCAR UM IF RECURSO=PESSOA?
    if (terminada)
        return this->duracaoReal;
    else {
        double horasPessoas = 0;
        for (int i=0; i<getQuantidadeDeRecursos(); i++){
            if(recursos[i]->ehPessoa())
                horasPessoas = horasPessoas + recursos[i]->getHorasDiarias();
        }
        return getHorasNecessarias();
    }
}
int AtividadeDeEsforcoFixo::getHorasNecessarias(){
    return this-> horasNecessarias;
}



