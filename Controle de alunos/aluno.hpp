#ifndef aluno_H
#define aluno_H
#include <string>
#include <vector>
#include <map>

using namespace std;

struct aluno{
    map<int, string> registro;
    string nome;
    int matricula;
    vector<int> notas;

    aluno(int x, string y);

    void acesso();

    void adiciona(int x);

    void media();

    void maior();

    void menor();
};

#endif
