#include "AtividadeDeEsforcoFixo.h"

AtividadeDeEsforco::AtividadeDeEsforçoFixo(string nome, int horasNecessarias) : nome(nome), horasNecessarias(horasNecessarias){
    if (horasNecessarias <= 0)
        throw new invalid_argument("horas menor que 0")
}

AtividadeDeEsforcoFixo::~AtividadeDeEsforcoFixo(){
    cout << "deletado" << endl;
}
int AtividadeDeEsforcoFixo::getCusto(){

}
int AtividadeDeEsforcoFixo::getDuracao(){

}
int AtividadeDeEsforcoFixo::getHorasNecessarias(){
    return this-> horasNecessarias;
}



