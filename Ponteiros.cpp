#include <iostream>

// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por valor
//    - A segunda deve ser passada por referência 
//    - A terceira deve ser passada "por referência" usando apontadores (passagem "por referência" disponível em C)
//    A função deverá somar 1 ao valor de cada uma das 3 variáveis e retornar.


using namespace std;

void func(int a, int &b, int *c){
    a++;
    b = b + 1;
    (*c) = (*c) + 1;
}

int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int a;
    cin >> a;
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *c = nullptr;
    c = new int;
    *c = 0;
    
    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int b;
    cin >> b;
    int d[b];
    int i;
    for(i=0; i<b; i++){
        cin >> d[i];
    }
    
    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &a << endl;
    
    // 5) Imprima o VALOR da variável declarada em (1)
    cout << a << endl;
    
    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &c << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << *c << endl;
    
    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &d << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &d[0] << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << d[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    delete c;
    c = &a;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << c << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *c << endl;
    
    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *c = 5;

    // 15) Imprima o VALOR da variável declarada em (1)
    cout << a << endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    *c = d[0];

    // 17) Imprima o VALOR da variável declarada em (2)
    cout << c << endl;

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *c << endl;

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    c = &d[0];

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    if(*c == d[0]){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << c << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *c << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for(i=0; i<b; i++){
        *(c+i) = *(c+i) * 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for(i=0; i<b; i++){
        if(i==0){
            cout << d[i];
        }else{
            cout << " " << d[i];
        }
    }
    cout << endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for(i=0; i<b; i++){
        if(i==0){
            cout << *(d+i);
        }else{
            cout << " " << *(d+i);
        }
    }
    cout << endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    for(i=0; i<b; i++){
        if(i==0){
            cout << *(c+i);
        }else{
            cout << " " << *(c+i);
        }
    }
    cout << endl;

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    c = &d[b-1];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << c << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *c << endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **cc = &c;

    // 31) Imprima o VALOR da variável declarada em (30)
    cout << cc << endl;

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << &cc << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << *cc << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << **cc << endl;

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int tchubirau;
    cin >> tchubirau;
    int down;
    cin >> down;
    int down2;
    cin >> down2;

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    func(tchubirau, down, &down2);
    
    // 37) Imprima o valor das 3 variáveis criadas em (35)
    cout << tchubirau << " " << down << " " << down2 << endl;
    
    return 0;
}