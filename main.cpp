#include <iostream>
#include <iterator>
#include "Projeto.h"
#include "Recurso.h"
#include "Pessoa.h"
#include "Ferramenta.h"
#include "Atividade.h"
#include "AtividadeDeEsforcoFixo.h"
#include "AtividadeDePrazoFixo.h"
#include "PersistenciaDeProjeto.h"

using namespace std;

int main()
{
    PersistenciaDeProjeto* persistencia = new PersistenciaDeProjeto();
    Pessoa::setValorPorHoraPadrao(10);
    /*********************  **********************/
    string nomeProjeto;
    int opcao;
    char resposta;
    cout << "Deseja carregar um novo projeto (s/n)?";
    cin >> resposta;
    Projeto* proj = new Projeto("name");
    if(resposta=='n') {
        cout << "Digite o nome do Projeto:  ";
        cin >> nomeProjeto;
        proj = new Projeto(nomeProjeto);
    }
    else if (resposta=='s') {
        string filename;
        cout << "Digite o nome do arquivo: ";
        cin >> filename;
        proj = persistencia->carregar(filename);
    }
    if(resposta=='n') {
        do{
                /** Menu do Projeto **/
            cout << "1 - Adicionar recurso" << endl;
            cout << "2 - Adicionar atividade" << endl;
            cout << "3 - Terminar atividade" << endl;
            cout << "4 - Imprimir projeto" << endl;
            cout << "5 - Definir valor por hora padrao" << endl;
            cout << "6 - Salvar" << endl;
            cout << "0 - Sair" << endl;
            cout << "Escolha a opcao: ";
            cin >> opcao;
            if (opcao==1) {
                    /** Menu para Adicionar Recursos **/
                string nome;
                int valor, horas;
                cout << "Ferramenta (f) ou Pessoa (p): ";
                cin >> resposta;
                if(resposta=='p') {
                    cout << "Nome: ";
                    cin >> nome;
                    cout << "Horas diarias: ";
                    cin >> horas;
                    cout << "Valor por hora padrao (s/n)? ";
                    cin >> resposta;
                    if(resposta=='n') {
                        cout << "Valor por hora (em R$): ";
                        cin >> valor;
                        Pessoa* pers = new Pessoa(nome, valor, horas);
                        try {
                            proj->adicionar(pers);
                        }
                        catch(logic_error *e) {
                            cout << "Erro: " << e->what();
                        }
                    }
                    else if (resposta=='s') {
                        Pessoa* pers = new Pessoa(nome, horas);
                        try {
                            proj->adicionar(pers);
                        }
                        catch(logic_error *e) {
                            cout << "Erro: " << e->what();
                        }
                    }
                }
            }
            else if (opcao==2) {
                /** Menu para Adicionar Atividades **/
                string nome;
                int option;
                char ans;
                int horas, dias;
                cout << "Nome: ";
                cin >> nome;
                cout << "Prazo fixo (p) ou trabalho fixo (t)? ";
                cin >> ans;
                if(ans=='t') {
                    cout << "Horas necessarias: ";
                    cin >> horas;
                    AtividadeDeEsforcoFixo* atividade = new AtividadeDeEsforcoFixo(nome, horas);
                    proj->adicionar(atividade);
                }
                else if (ans=='p') {
                    cout << "Dias necessarios: ";
                    cin >> dias;
                    AtividadeDePrazoFixo* atividade = new AtividadeDePrazoFixo(nome, dias);
                    proj->adicionar(atividade);

                }
                /************************************************************/
                    do{
                    int resp;
                    cout << "Deseja adicionar um recurso (s/n): ";
                    cin >> ans;
                    option = 1;
                    while (ans=='s'&& option != 0) {
                        list<Recurso*>::iterator i = proj->getRecursos()->begin();
                        while(i != proj->getRecursos()->end()) {
                            cout << (*i)+1 << " - ";
                            (*i)->imprimir();
                            i++;
                        }
                        cout << "Escolha um recurso ou 0 para cancelar: ";
                        cin >> resp;
                        if(resp != 0) {
                            i = proj->getRecursos()->begin();
                            while(distance(proj->getRecursos()->begin(), i) != resp-1)
                                i++;
                            try {
                            proj->adicionar(*i);
                            } catch(invalid_argument *e) {
                                cout << "Erro: " << e->what();
                            }
                        }
                            else
                              cout << "Adicionado a atividade" << endl;
                        }
                    } while(proj->getAtividades()->size() < Atividade::MAX_RECURSOS && ans == 's');

                    /*****************************************************************************/
            }
            //delete atividade;
            /** Menu para Terminar Atividade **/
            else if (opcao==3) {
                int resp, dr;
                //vector<Atividade*> atividades = proj->getAtividades();
                for(unsigned int i=0; i < proj->getAtividades()->size(); i++) {
                    proj->getAtividades()->at(i)->imprimir();
                }
                cout << "Escolha uma atividade ou 0 para cancelar: ";
                cin >> resp;
                if(proj->getAtividades()->at(resp-1)->estaTerminada())
                    cout << "Atividade ja terminada" << endl;
                else{
                    cout << "Duracao real: ";
                    cin >> dr;
                    proj->getAtividades()->at(resp-1)->terminar(dr);
                }
            }
            /** Imprimir Projeto **/
            else if (opcao==4)
                proj->imprimir();

            /** Definir valor por hora padrao **/
            else if(opcao==5) {
                double novovalor;
                cout << "Valor atual: R$" << Pessoa::getValorPorHoraPadrao() << "por hora" << endl;
                cout << "Novo valor: ";
                cin >> novovalor;
                Pessoa::setValorPorHoraPadrao(novovalor);
            }
            /** Salvar **/
            else if (opcao==6) {
                string filename;
                cout << "Nome do arquivo: ";
                cin >> filename;
                persistencia->salvar(proj, filename);
            }
        } while(opcao!=0);

    delete proj;
    return 0;
    /*********************************************************/
}
}
