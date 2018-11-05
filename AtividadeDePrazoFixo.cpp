#include "AtividadeDePrazoFixo.h"

AtividadeDePrazoFixo::AtividadeDePrazoFixo(string nome, int dias) : nome(nome), dias(dias){
    if (dias <= 0)
        throw new invalid_argument("dias menor que 0");
}

AtividadeDePrazoFixo::~AtividadeDePrazoFixo(){
    cout << "deletado" << endl;
}

int AtividadeDePrazoFixo::getCusto(){

}

int AtividadeDePrazoFixo::getDuracao(){

}

int AtividadeDePrazoFixo::getPrazo(){

}
