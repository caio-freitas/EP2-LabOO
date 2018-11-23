#include <fstream>
#include <iostream>
#include "Projeto.h"
#include "ErroDeArquivo.h"
#include "Ferramenta.h"
#include "Pessoa.h"
#include "Atividade.h"
#include "AtividadeDeEsforcoFixo.h"
#include "AtividadeDePrazoFixo.h"
#include "Recurso.h"

using namespace std;

class PersistenciaDeProjeto {
public:
    PersistenciaDeProjeto();
    virtual ~PersistenciaDeProjeto();

    Projeto* carregar(string arquivo);
    void salvar(Projeto* p, string arquivo);

protected:
    string arquivo;
};
