#ifndef ContaBancaria_H
#define ContaBancaria_H
#include <string>

using namespace std;

struct ContaBancaria{
    int id;
    string Cliente;
    float Saldo;

    ContaBancaria(int x, string y);
    
    void Deposito(float x);

    void Saque(float y);
    
    void Pix(ContaBancaria* dest, float z);
    
    void Imprime();

};

#endif
    