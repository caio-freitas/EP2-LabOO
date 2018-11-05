#ifndef ATIVIDADEDEESFORCOFIXO_H
#define ATIVIDADEDEESFORCOFIXO_H
#include "Atividade.h"


class AtividadeDeEsforcoFixo : public Atividade{

public:
    AtividadeDeEsforcoFixo(string nome, int horasNecessarias);
    virtual ~AtividadeDeEsforcoFixo();
    virtual int getHorasNecessarias();
    virtual int getCusto();
    virtual int getDuracao();


protected:


};

#endif // ATIVIDADEDEESFORÁOFIXO_H
