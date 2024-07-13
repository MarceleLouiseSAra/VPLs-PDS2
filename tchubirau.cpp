#include <iostream>
#include <string>
#include <list>

using namespace std;

class tchubirau{
    public:

    int id;
    static int quantity;
    static int automatic;
    
    tchubirau(){
        this->id = tchubirau::automatic;
        tchubirau::automatic++;
        tchubirau::quantity++;
    }
    
   tchubirau(int x){
        this->id = x;
        tchubirau::quantity++;
    }
    
    /*
    ~tchubirau(){
        cout << "opa" << endl;
        tchubirau::quantity--;
    }
    */
    
};

int tchubirau::quantity = 0;
int tchubirau::automatic = 1;

int main(){
    
    list <tchubirau> lista;

    char modo;
    int a = 1;
    
    while(a){
        
        cin >> modo;
        
        if(modo=='A'){ //adiciona um novo objeto com id automático no final da lista. Deve ser impresso o id e o endereço de memória do objeto criado.
            tchubirau obj;
            lista.push_back(obj);
            cout << lista.back().id << " " << &lista.back() << endl;
        }
        
        if(modo=='C'){ //adiciona um novo objeto com id fornecido no início da lista. Deve ser impresso o id e o endereço de memória do objeto criado ou "ERRO" caso o id não seja negativo.
        //Nesse caso, só ids negativos podem ser fornecidos e o id automático não é alterado
            int x = 0;
            cin >> x;
            if(x >= 0){
                cout << "ERRO" << endl;
            }else{
                tchubirau obj(x);
                lista.push_front(obj);
                cout << lista.front().id << " " << &lista.front() << endl;
            }
        }
        
        if(modo=='R'){ //remove (e deleta) um objeto da frente da lista. Deve ser impresso o id e o endereço endereço de memória do objeto removido. Caso a lista esteja vazia deve ser impresso "ERRO"
            if(tchubirau::quantity == 0){
                cout << "ERRO" << endl;
            }else{
                cout << lista.front().id << " " << &lista.front() << endl;
                    lista.pop_front();
                    tchubirau::quantity--;
            }
        }
        
        if(modo=='N'){ //imprime o valor do contador com número de objetos existentes.
            cout << tchubirau::quantity << endl;
        }
        
        if(modo=='P'){ //imprime o id e o endereço de memória do i-ésimo elemento da lista. Se i for um valor inválido (menor que 1 ou maior que o número de elementos) seu programa deverá imprimir "ERRO"
            int i = 0;
            cin >> i;
            if(i < 1 || i > tchubirau::quantity){
                cout << "ERRO" << endl;
            }else{
                list<tchubirau>::iterator it;
                it = lista.begin();
                for(i -= 1; i != 0; i--){
                    it++;
                }
                cout << (*it).id;
                cout << " ";
                cout << &(*it) << endl;
            }
        }
        
        if(modo=='L'){ //Imprime, para todos os elementos da lista, o id e o endereço de memória do objeto, sendo um elemento por linha com quebra de linha no final. 
            list<tchubirau>::iterator it;
            for(it = lista.begin(); it != lista.end(); it++){
                cout << (*it).id;
                cout << " ";
                cout << &(*it) << endl;
            }
        }
        
        if(modo=='E'){ //termina a execução do programa.
            a = 0;
            break;
        }
        
    }

}