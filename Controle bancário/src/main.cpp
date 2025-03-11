#include <iostream>
#include <string>
#include "ContaBancaria.hpp"
#include "Banco.hpp"

using namespace std;

int main(){
    Banco Bank;
    char modo;
    int a = 1;
    while(a){
        cin >> modo;
        if(modo=='C'){
            int i = Bank.Contas;
            int x;
            cin >> x;
            string y;
            cin >> y;
            ContaBancaria* ptr = Bank.CriaConta(x, y);
            if(ptr==nullptr){
                cout << "ERRO: conta repetida" << endl;
            }else{
                Bank.Vetor[i] = ptr;
                cout << "conta criada" << endl;
            }
            ptr = nullptr;
        }
        
        if(modo=='D'){
            int x;
            cin >> x;
            float y;
            cin >> y;
            ContaBancaria* ptr = Bank.Pesquisa(x);
            if(ptr==nullptr){
                cout << "ERRO: conta inexistente" << endl;
            }else{
                (*ptr).Deposito(y);
                cout << "deposito efetuado" << endl;
            }
            ptr = nullptr;
        }
        
        if(modo=='S'){
            int x;
            cin >> x;
            float y;
            cin >> y;
            ContaBancaria* ptr = Bank.Pesquisa(x);
            if(ptr==nullptr){
                cout << "ERRO: conta inexistente" << endl;
            }else{
                (*ptr).Saque(y);
                cout << "saque efetuado" << endl;
            }
            ptr = nullptr;
        }
        
        if(modo=='P'){
            int x;
            cin >> x;
            int y;
            cin >> y;
            float z;
            cin >> z;
            ContaBancaria* ptr1 = Bank.Pesquisa(x);
            ContaBancaria* ptr2 = Bank.Pesquisa(y);
            if(ptr1!=nullptr&&ptr2!=nullptr){
                (*ptr1).Pix(ptr2, z);
                cout << "pix efetuado" << endl;
            }else{
                cout << "ERRO: conta inexistente" << endl;
            }
            ptr1 = nullptr;
            ptr2 = nullptr;
        }
        
        if(modo=='I'){
            Bank.ListaContas();
        }
        
        if(modo=='T'){
            a = 0;
            break;
        }
        
    }
    
    return 0;
}