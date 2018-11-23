#include "PersistenciaDeProjeto.h"
#include <algorithm>

PersistenciaDeProjeto::PersistenciaDeProjeto()
{

}

PersistenciaDeProjeto::~PersistenciaDeProjeto()
{

}

Projeto* PersistenciaDeProjeto::carregar(string arquivo)
{
    ifstream input;
    input.open (arquivo.c_str());
    if (input.bad())
        throw new ErroDeArquivo("Erro de Arquivo");
    int numeroRecursos, i, j, k, custoF, valorP, horasP, numeroAtividades, horasE, duracaoE, recursosAtividade, prazo, duracaoPr;
    string nome, FouP, TouN, nomeF, nomeP, nomeE, nomeRecurso, nomePr, EouP;
    input >> nome;
    Projeto* p = new Projeto(nome);
    input >> numeroRecursos; // le o numero de recursos
    for (i=0; i<numeroRecursos; i++){
        input >> FouP; // le se é ferramenta ou pessoa
        if (FouP == "F"){
            input >> nomeF; // nome da ferramenta
            input >> custoF; // custo diario da ferramenta
            Ferramenta* f = new Ferramenta(nomeF, custoF);
            p->getRecursos()->push_back(f);
        }
        else if(FouP == "P"){
            input >> nomeP; // nome da pessoa
            input >> valorP; // valor por hora
            input >> horasP; // horas diárias
            if (valorP == -1) // caso o valor por hora seja o padrão
                valorP = Pessoa::getValorPorHoraPadrao();
            Pessoa* pers = new Pessoa(nomeP, valorP, horasP);
            p->getRecursos()->push_back(pers);
        }
    }
    input >> numeroAtividades;
    for (j=0; j<numeroAtividades; j++){
        input >> EouP; // le se eh esforço fixo ou prazo fixo
        if (EouP == "E"){
            input >> nomeE; // nome da atividade
            input >> horasE; // horas necessarias
            AtividadeDeEsforcoFixo* ae = new AtividadeDeEsforcoFixo(nomeE, horasE);
            input >> TouN;// terminada ou n
            if (TouN == "T"){
                input >> duracaoE; // se terminada, sua duracao
                ae->terminar(duracaoE);
            }
            input >> recursosAtividade; // numero de recursos da atividade
            for (k=0; k < recursosAtividade; k++){
                input >> nomeRecurso;
                list<Recurso*>::iterator it = p->getRecursos()->begin();
                while (it!= p->getRecursos()->end()) {
                    if((*it)->getNome() == nomeRecurso)
                        ae->adicionar((*it));
                }
            }
        }
        else if(EouP == "P"){
            input >> nomePr;
            input >> prazo;
            AtividadeDePrazoFixo* apr = new AtividadeDePrazoFixo(nomePr, prazo);
            input >> TouN;
            if (TouN == "T"){
                input >> duracaoPr;
                apr->terminar(duracaoPr);
            }
            input >> recursosAtividade;
                list<Recurso*>::iterator it = p->getRecursos()->begin();
                while (it!= p->getRecursos()->end()) {
                    if((*it)->getNome() == nomeRecurso)
                        apr->adicionar((*it));
                }
        }
    }
    input.close();
    return p;
}

void PersistenciaDeProjeto::salvar(Projeto* p, string arquivo)
{
    ofstream output;
    output.open(arquivo.c_str());
    output << p->getNome() << "/n";
    output << p->getRecursos()->size() << "/n";
    list<Recurso*>::iterator it = p->getRecursos()->begin();
    for (int i=0; i < p->getRecursos()->size(); i++){
        int num=0;
        while(num<i) {
            num++;
            it++;
        }
        Pessoa* pers = dynamic_cast<Pessoa*>(*it);
        if(pers!=NULL) { /**Não é pessoa**/
            output << "P " << pers->getNome() << " ";
            if (pers->recebeValorPadrao())
                output << pers->getValorPorHoraPadrao();
            else
                output << pers->getValorPorHora();
            output << " " << pers->getHorasDiarias() << "\n";
        }
        else {
            Ferramenta* ferra = dynamic_cast<Ferramenta*>((*it));
            output << "F " << ferra->getNome() << " " << ferra->getCustoDiario() << "\n";
        }
    }
    /**********/
    output << p->getAtividades()->size() << "\n";
    for (int i=0; i < p->getAtividades()->size(); i++){
        AtividadeDeEsforcoFixo* jagunco = dynamic_cast<AtividadeDeEsforcoFixo*>(p->getAtividades()->at(i));
        if(jagunco!=NULL){ //Se for Atividade de Esforço Fixo
            output << "E " << jagunco->getNome() << " " << jagunco->getHorasNecessarias();
            if (jagunco->estaTerminada())
                output << " T " << jagunco->getDuracao() << "\n";
            else
                output << " N \n";
        }
        else{ // ATIVIDADE DE PRAZO FIXO
            AtividadeDePrazoFixo* jagunco = dynamic_cast<AtividadeDePrazoFixo*>(p->getAtividades()->at(i));
            output << "P " << jagunco->getNome() << " " << jagunco->getPrazo();
            if (jagunco->estaTerminada())
                output << " T " << jagunco->getDuracao() << "\n";
            else
                output << " N \n";
        }
        for (unsigned int j=0; j < jagunco->getQuantidadeDeRecursos(); j++)
            output << jagunco->getRecursos()[j]->getNome() << " ";
        output << "\n";
    }
    output << "\n";
}
