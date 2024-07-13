#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

string correcao(string guessing, string chave, string erros){
    int i, j;
    string correcao = guessing;
    for(i=0; i<5; i++){
        if(guessing[i] == chave[i]){
            correcao[i] = chave[i];
        }else{
            correcao[i] = '*';
        }
        for(j=0; j<5; j++){
            if(guessing[i] == chave[j] && guessing[i] != chave[i]){
                correcao[i] = tolower(guessing[i]);
            }
        }
        
        auto a = find(begin(chave), end(chave), guessing[i]);
        auto b = find(begin(erros), end(erros), guessing[i]);
        if(a!=end(chave)){
            //cout << "entrei no if" << endl;
            continue;
        }
        if(a==end(chave) && b==end(erros)){
            //cout << "entrei no else" << endl;
            erros = erros + guessing[i];
        }
    }
    cout << correcao << " " << "(" << erros << ")" << endl;
    return erros;
}

int main(){
    ifstream in("palavras.txt", fstream::in);
    if (!in.is_open()){
        return 1;
    }
    int n;
    cin >> n;
    //cout << n << endl;
    string chave;
    int i;
    for(i=0; i<=n; i++){
        //getline(in, chave, '\n');
        in >> chave;
    }
    //cout << chave << endl;
    string erros;
    string guessing;
    for(i=0; i<5; ++i){
        cin >> guessing;
        //cout << guessing << endl;
        erros = correcao(guessing, chave, erros);
        if((guessing==chave && i<5)){
            cout << "GANHOU!" << endl;
            break;
        }
        if(guessing!=chave && i==4){
            cout << "PERDEU!" << " " << chave << endl;
            break;
        }
    }
    in.close();
    return 0;
}



