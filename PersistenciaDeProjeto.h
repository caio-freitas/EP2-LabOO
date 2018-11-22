#include "Projeto.h"
#include <fstream>


class PersistenciaDeProjeto(){
public:
    PersitenciaDeProjeto();
    ~virtual PersistenciaDeProjeto();

    Projeto* carregar(string arquivo);
    void salvar(Projeto* p, string arquivo);
protected:

}
