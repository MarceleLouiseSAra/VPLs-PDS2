#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "aluno.hpp"

using namespace std;

    aluno::aluno(int x, string y){
        //this->registro.insert(pair<int, string>(x, y));
        this->nome = y;
        this->matricula = x;
    }
    
    void aluno::adiciona(int x){
        this->notas.push_back(x);
    }
    
    void aluno::acesso(){
        //map<int, string>::iterator it_map;
        //for(it_map = registro.begin(); it_map != registro.end(); it_map++){
        cout << /*it_map->first*/ this->matricula << ' ';
        cout << /*it_map->second;*/ this->nome;
        //}
        
        vector<int>::iterator it_vector;
        for(it_vector = notas.begin(); it_vector != notas.end(); it_vector++){
            cout << ' ' << *it_vector;
        }
        cout << endl;
    }

    void aluno::media(){
        float soma = 0, counter = 0;
        vector<int>::iterator it;
        for(it = notas.begin(); it != notas.end(); it++, counter++){
            soma += *it;
        }
        float media = soma/counter;
        cout << setprecision(2) << fixed;
        cout << media << " ";
    }

    void aluno::maior(){
        int maior = 0, aux = 0;
        vector<int>::iterator it;
        for(it = notas.begin(); it != notas.end(); it++){
            aux = *it;
            if(aux > maior){
                maior = aux;
            }
        }
        cout << maior << " ";
    }
    
    void aluno::menor(){
        int menor = 100, aux = 0;
        vector<int>::iterator it;
        for(it = notas.begin(); it != notas.end(); it++){
            aux = *it;
            if(aux < menor){
                menor = aux;
            }
        }
        cout << menor;
    }
