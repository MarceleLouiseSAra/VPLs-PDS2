#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "aluno.hpp"

using namespace std;

bool ordenar(aluno &a1, aluno &a2){
    return a1.nome < a2.nome;
}

int main(){
    vector<aluno> alunos;
    while(1){
        //cout << "entrei no primeiro while" << endl;
        string nome;
        cin >> nome;
        if(nome == "END"){
            break;
        }
        int matricula;
        cin >> matricula;
        aluno p = aluno(matricula, nome);
        alunos.push_back(p);

        while(1){
            //cout << "entrei no segundo while" << endl;
            int nota = 0;
            cin >> nota;
            if(nota==-1){
                break;
            }
            alunos.back().adiciona(nota);
        }
    }
    
    sort(alunos.begin(), alunos.end(), ordenar);

    vector<aluno>::iterator it;
    for(it = alunos.begin(); it != alunos.end(); it++){
        //cout << "entrei no for" << endl;
        it->acesso();
        it->media();
        it->maior();
        it->menor();
        cout << endl;
    }
    
    return 0;
}

// g++ -c aluno.cpp -o aluno.o
// g++ -c main.cpp -o main.o
// g++ main.o aluno.o -o main
// ./main