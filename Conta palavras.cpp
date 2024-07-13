#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

void travessao(string &s){
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(s[i] == '-'){
            s[i] = ' ';
        }
    }
}

void remove_punct(string &s){
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(ispunct(s[i])){
            s.erase(i--, 1);
            len = s.size();
        }
    }
}

void to_lower(string &s){
    int len = s.size();
    for(int i = 0; i < len; i++){
        s[i] = tolower(s[i]);
    }
}

int main(){
    string arq;
    cin >> arq;
    ifstream in(arq, fstream::in);
    if (!in.is_open()){
        return 1;
    }
    
    string espaco = " ";
    string line;
    string aux;
    while(getline(in, line)){
        aux += line;
        aux += espaco;
    }
    //cout << aux << endl;
    
    travessao(aux);
    remove_punct(aux);
    to_lower(aux);
    
    stringstream texto(aux);
    
    vector<string> palavras;
    string palavra;
    while(getline(texto, palavra, ' ')){
        palavras.push_back(palavra);
    }
    
    sort(palavras.begin(), palavras.end());
    
    vector<string> vector2;
    vector<string>::iterator it_vector1;
    vector<string>::iterator it_vector2;

    for(it_vector1 = palavras.begin(), it_vector2 = palavras.begin()+1; 
        it_vector1 != palavras.end(); 
        it_vector1++, it_vector2++){
        if(*it_vector2 != *it_vector1){
            vector2.push_back(*it_vector1);
        }
    }
    
    int counter = 0;
    vector<int> quantity;
    for(it_vector1 = vector2.begin(); it_vector1 != vector2.end(); it_vector1++){
        counter = 0;
        for(it_vector2 = palavras.begin(); it_vector2 != palavras.end(); it_vector2++){
            if(*it_vector1 == *it_vector2){
                counter++;
            }
        }
        quantity.push_back(counter);
    }
    
    vector<string>::iterator it_vector;
    vector<int>::iterator it_q;
    
    for(it_vector = vector2.begin(), it_q = quantity.begin(); 
        it_vector != vector2.end(), it_q != quantity.end();
        it_vector++, it_q++){
        cout << *it_vector << " " << *it_q << endl;
    }
    
    return 0;
}