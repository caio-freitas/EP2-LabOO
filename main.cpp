#include <iostream>
#include "Recurso.h"
#include "Pessoa.h"
#include "Ferramenta.h"
#include "Atividade.h"

using namespace std;

int main()
{
    Pessoa::setValorPorHoraPadrao(10);
    /********************* EP1 **********************/
    string nomeProjeto;
    int opcao;
    char resposta;
    cout << "Deseja carregar um novo projeto (s/n)?";
    cin >> resposta;
    cout << "Digite o nome do Projeto:  ";
    cin >> nomeProjeto;
    if(resposta=='n') {
        Projeto* proj = new Projeto(nomeProjeto);
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
                        if (!proj->adicionarRecurso(pers)) {
                            cout << "Nao eh possivel adicionar uma nova pessoa" << endl;
                        }
                    }
                    else if (resposta=='s') {
                        Pessoa* pers = new Pessoa(nome, horas);
                        if (!proj->adicionarRecurso(pers)) {
                            cout << "Nao eh possivel adicionar uma nova pessoa" << endl;
                        }
                    }
                }
            }
            else if (opcao==2) {
                /** Menu para Adicionar Atividades **/
                string nome;
                int option;
                char ans;
                int horas, i, dias;
                cout << "Nome: ";
                cin >> nome;
                cout << "Prazo fixo (p) ou trabalho fixo (t)? ";
                cin >> ans;
                if(ans=='t') {
                    cout << "Horas necessarias: ";
                    cin >> horas;
                }
                else if (ans=='p') {
                    cout << "Dias necessarios: ";
                    cin >> dias;
                }
                /************************************************************/
                    do{
                    Atividade* atividade = new Atividade(nome, horas);
                    int resp;
                    proj->adicionar(atividade);
                    cout << "Deseja adicionar um recurso (s/n): ";
                    cin >> ans;
                    option = 1;
                    while (ans=='s'&& option != 0) {
                        Recurso** recursos = proj->getRecursos();
                        list<Recurso*>*::iterator i = recursos->begin();
                        while(i != recursos->end()) {
                            cout << *i+1 << " - ";
                            recursos[i]->imprimir();
                            i++;
                        }
                        cout << "Escolha um recurso ou 0 para cancelar: ";
                        cin >> resp;
                        if(resp != 0) {
                            i = recursos->begin();
                            while(*i!=resp-1)
                                i++;
                            if(atividade->adicionar(i) == 0)
                              cout << "Nao foi possivel adicionar recurso" << endl;
                            else {
                              cout << "Adicionado a atividade" << endl;


                            } while(proj->getQuantidadeDeAtividades()< MAXIMO_ATIVIDADES && ans == 's');

                    /*****************************************************************************/
                        }
                    }
            //delete atividade;
                }
            }
            /** Menu para Terminar Atividade **/
            else if (opcao==3) {
                int resp, dr;
                vector<Atividade*> atividades = proj->getAtividades();
                vector<Atividade*>::iterator i = atividades->begin();
                while(i != atividades->end()) {
                    i->imprimir(); /** ISSO TÁ ESTRANHIO... **/
                }
                cout << "Escolha uma atividade ou 0 para cancelar: ";
                cin >> resp;
                if(atividades[resp-1]->estaTerminada)
                    cout << "Atividade ja terminada" << endl;
                else{
                    cout << "Duracao real: ";
                    cin >> dr;
                    atividades[resp-1]->terminar(dr);
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
                string filname;
                cout << "Nome do arquivo: ";
                cin >> filename;
            }
        } while(opcao!=0);

    delete proj;
    return 0;
    /*********************************************************/
}
