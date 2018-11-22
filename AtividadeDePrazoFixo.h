#ifndef ATIVIDADEDEPRAZOFIXO_H
#define ATIVIDADEDEPRAZOFIXO_H
#include "Atividade.h"

class AtividadeDePrazoFixo : public Atividade{

public:
    AtividadeDePrazoFixo(string nome, int dias);
    virtual ~AtividadeDePrazoFixo();

    virtual int getDuracao();
    virtual int getPrazo();

protected:
    virtual bool ehPrazoFixo();
};

#endif // ATIVIDADEDEPRAZOFIXO_H
