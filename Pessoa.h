#include "Recurso.h"
using namespace std;


class Pessoa : public Recurso{
private:
    double valorPorHora;
    int horasDiarias;
    static double valorPorHoraPadrao;
    bool recebePadrao;

public:
    Pessoa(string nome, double valorPorHora, int horasDiarias);
    Pessoa(string nome, int horasDiarias);
    virtual ~Pessoa();

    virtual double getValorPorHora();
    virtual int getHorasDiarias();
    virtual bool recebeValorPadrao();

    static void setValorPorHoraPadrao(double valor);
    static double getValorPorHoraPadrao();
    double getCusto();
};
