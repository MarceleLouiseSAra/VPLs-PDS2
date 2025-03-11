#include <iostream>
#include <iomanip>
#include <string>
#include "ContaBancaria.hpp"

using namespace std;

    ContaBancaria::ContaBancaria(int x, string y){
        this->id = x;
        this->Cliente = y;
        this->Saldo = 0;
    }
    
    void ContaBancaria::Deposito(float x){
        this->Saldo += x;
    }
    
    void ContaBancaria::Saque(float y){
        this->Saldo -= y;
    }
    
    void ContaBancaria::Pix(ContaBancaria* dest, float z){
        (*dest).Saldo += z;
        this->Saldo -= z;
    }
    
    void ContaBancaria::Imprime(){
        cout << setprecision(2) << fixed;
        cout << this->id << " " << this->Cliente << " " << this->Saldo << endl;
    }