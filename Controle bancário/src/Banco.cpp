#include <iostream>
#include <string>
#include "Banco.hpp"
#include "ContaBancaria.hpp"

using namespace std;

    Banco::Banco(){
        this->Contas = 0;
        int i;
        for(i=0; i<20; i++){
            Vetor[i] = nullptr;
        }
    }
    
    ContaBancaria* Banco::CriaConta(int x, string y){
        int i = this->Contas;
        if(this->Pesquisa(x)==nullptr){
            Vetor[i] = new ContaBancaria(x, y);
            this->Contas++;
            return Vetor[i];
        }
        return nullptr;
    }
    
    ContaBancaria* Banco::Pesquisa(int x){
        int i = 0;
        ContaBancaria* ptr = nullptr;
        for(i=0; i<20; i++){
            ptr = Vetor[i];
            if(ptr==nullptr){
                return nullptr;
            }
            if((*ptr).id==x){
                return Vetor[i];
            }else{
                continue;
            }
        }
        return nullptr;
    }
    
    void Banco::ListaContas(){
        int i = 0;
        ContaBancaria* ptr = nullptr;
        for(i=0; i<20; i++){
            ptr = Vetor[i];
            if(ptr==nullptr){
                continue;
            }else{
                ptr->Imprime();
            }
        }
        ptr = nullptr;
    }