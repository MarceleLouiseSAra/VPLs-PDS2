#ifndef Banco_H
#define Banco_H
#include "ContaBancaria.hpp"
#include <string> 

using namespace std;

struct Banco{
    int Contas;
    ContaBancaria* Vetor[20];

    Banco();

    ContaBancaria* CriaConta(int x, string y);

    ContaBancaria* Pesquisa(int id);

    void ListaContas();

};

#endif
    