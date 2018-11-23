#ifndef ATIVIDADEDEESFORCOFIXO_H
#define ATIVIDADEDEESFORCOFIXO_H
#include "Atividade.h"


class AtividadeDeEsforcoFixo : public Atividade{

public:
    AtividadeDeEsforcoFixo(string nome, int horasNecessarias);
    virtual ~AtividadeDeEsforcoFixo();
    virtual int getHorasNecessarias();

    virtual int getDuracao();


protected:
    string nome;
    int horasNecessarias;


};

#endif // ATIVIDADEDEESFORÁOFIXO_H
