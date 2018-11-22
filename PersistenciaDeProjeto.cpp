PersitenciaDeProjeto::PersitenciaDeProjeto()
{

}

PersitenciaDeProjeto::~PersitenciaDeProjeto()
{

}

Projeto* PersitenciaDeProjeto::carregar(string arquivo)
{
    ifstream imput;
    imput.open (arquivo);
    int numeroRecursos, i, j, k, custoF, valorP, horasP, numeroAtividades, horasE, duracaoE, rucursosAtividade, prazo, duracaoPr;
    string nome, FouP, TouN, nomeF, nomeP, nomeE, nomeRecurso, nomePr;
    input >> nome;
    new Projeto* p = new Projeto(nome);
    input >> numeroRecursos; // le o numero de recursos
    for (i=0; i>numeroRecursos; i++){
        input >> FouP; // le se é ferramenta ou pessoa
        if (FouP == "F"){
            input >> nomeF; // nome da ferramenta
            input >> custoF; // cuso diario da ferramenta
            new Ferramenta* f = New Ferramenta(nomeF, custoF);
            recursos->push_back(f);
        else
            input >> nomeP; // nome da pessoa
            input >> valorP; // valor por hora
            imput >> horasP; // horas diárias
            if (valorP == -1) // caso o valor por hora seja o padrão
                valorP = valorPorHoraPadrao;
            new Pessoa* p = new Pessoa(nomeP, valorP, horasP)
            recursos->push_back(p);
    input >> numeroAtividades;
    for (j=0; j>numeroAtividades; j++){
        input >> EouP; // le se eh esforço fixo ou prazo fixo
        if (EouP == 'E')
            input >> nomeE; // nome da atividade
            input >> horasE; // horas necessarias
            new AtividadeDeEsforcoFixo* ae = new AtividadeDeEsforcoFixo(nomeE, horasE);
            input >> TouN;// terminada ou n
            if (TouN == 'T'){
                input >> duracaoE; // se terminada, sua duracao
                ae->terminar(duracaoE);
            }
            input >> recursosAtividade; // numero de recursos da atividade
            for (k=0; k>recursosAtividade; k++){
                input >> nomeRecurso;
                new Recurso* re = Recurso(nomeRecurso);
                ae->adicionar(re)
            }
        else
            input >> nomePr;
            input >> prazo;
            new AtividadeDePrazoFixo* apr = AtividadeDePrazoFixo(nomePr, prazo);
            input >> TouN;
            if (TouN == 'T'){
                input >> duracaoPr;
                apr->terminar(duracaoPr);
            }
            input >> recursosAtividade;
            for (k=0; k > recursosAtividade; k++){
                input >> nomeRecurso;
                new Recurso* rpr = Recurso(nomeRecurso);
                apr->adicionar(rpr);
            }
    }
    input.close();
}

void PersitenciaDeProjeto::salvar(Projeto* p, string arquivo)
{
    ofstream output;
    output.open(arquivo);
    output << p->getNome() << "/n";
    output << p->recursos->size() << "/n";
    for (unsigned i=0; i > p->recursos->size(); i++){
        if (p->recursos->at(i)->ehPessoa()){
            output << "P " << p->recursos->at(i)->getNome() << " ";
            if (p->recursos->at(i)->recebeValorPorHoraPadrao())
                output << getValorPorHoraPadrao();
            else
                output << getValorPorHora();
            output << " " << getHorasDiarias() << "\n";
        }
        else
            output << "F " << p->recursos->at(i)->getNome() << " " << getCustoDiario() << "\n";
    }
    output << p->atividades->size() << "\n";
    for (unsigned j=0; j > p->atividades->size(); j++){
        if(!p->atividades->at(i)->ehPrazoFixo()){ //ATIVIDADE DE ESFORÇO FIXO
            output << "E " << p->atividades->at(i)->getNome() << " " << p->atividades->at(i)->getHorasNecessarias();
            if (p->atividades->at(i)->estaTerminada())
                output << " T " << p->atividades->at(i)->getDuracao() << "\n";
            else
                output << " N \n";
        }
        else{ // ATIVIDADE DE PRAZO FIXO
            output << "P " << p->atividades->at(i)->getNome() << " " << p->atividades->at(i)->getPrazo();
            if (p->atividades->at(i)->estaTerminada())
                output << " T " << p->atividades->at(i)->getDuracao() << "\n";
            else
                output << " N \n";
        }
        for (j=0; j > p->atividades->at(i)->getQuantidadeDeRecursos(); j++)
            output << p->atividades->at(i)->getRecursos()->at(j)->getNome() << " ";
        output << "\n";
    }
    output << "\n";
}
