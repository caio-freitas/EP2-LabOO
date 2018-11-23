#include "AtividadeDePrazoFixo.h"

AtividadeDePrazoFixo::AtividadeDePrazoFixo(string nome, int dias) : Atividade(nome), dias(dias){
    if (dias <= 0)
        throw new invalid_argument("dias menor que 0");
}

AtividadeDePrazoFixo::~AtividadeDePrazoFixo(){
    cout << "deletado" << endl;
}

int AtividadeDePrazoFixo::getDuracao(){
    if (estaTerminada())
        return duracaoReal;
    else
        return dias;
}

int AtividadeDePrazoFixo::getPrazo(){ // NÃO SEI DIFERENCIAR DE getDuracao
        return dias;
}
