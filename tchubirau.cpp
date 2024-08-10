#include <iostream>
#include <list>
#include <string>

using namespace std;

class tchubirau {
private:
  int ID;
  static int quantity;
  static int automaticID;

public:
  tchubirau() {
    this->ID = tchubirau::automaticID;
    tchubirau::quantity++;
    tchubirau::automaticID++;
  }

  tchubirau(int x) {
    if (x >= 0) {
      cout << "ERRO" << endl;
    } else {
      this->ID = x;
      tchubirau::quantity++;
    }
  }

  ~tchubirau() {
    cout << "Destrutor para " << tchubirau::getID() << ' '
         << tchubirau::getAddress() << " foi chamado!" << endl;
    tchubirau::quantity--;
  }

  int getID() { return this->ID; }

  int *getAddress() { return &this->ID; }

  static int getQuantity() { return tchubirau::quantity; }
};

int tchubirau::quantity = 0;
int tchubirau::automaticID = 1;

int main() {

  list<tchubirau *> lista;

  char modo;
  int a = 1;

  while (a) {

    cin >> modo;

    if (modo == 'A') { // adiciona um novo objeto com id automático no final da
                       // lista. Deve ser impresso o id e o endereço de memória
                       // do objeto criado.
      tchubirau *aux = new tchubirau; // alocando dinâmicamente o objeto porque posso controlar quando o destrutor é chamado (pelo delete)
      lista.push_back(aux);
      cout << (*aux).getID() << ' ' << (*aux).getAddress() << endl;
    }

    if (modo ==
        'C') { // adiciona um novo objeto com id fornecido no início da lista.
               // Deve ser impresso o id e o endereço de memória do objeto
               // criado ou "ERRO" caso o id não seja negativo.
      // Nesse caso, só ids negativos podem ser fornecidos e o id automático não
      // é alterado
      int n;
      cin >> n;
      tchubirau *aux = new tchubirau(n);
      lista.push_front(aux);
      cout << (*aux).getID() << ' ' << (*aux).getAddress() << endl;
    }

    if (modo ==
        'R') { // remove (e deleta) um objeto da frente da lista. Deve ser
               // impresso o id e o endereço endereço de memória do objeto
               // removido. Caso a lista esteja vazia deve ser impresso "ERRO"
      if (lista.empty()) {
        cout << "ERRO" << endl;
      } else {
        cout << lista.front()->getID() << " " << lista.front()->getAddress()
             << endl;
        delete lista.front();
        lista.pop_front();
        // tchubirau::quantity--;
      }
    }

    if (modo ==
        'N') { // imprime o valor do contador com número de objetos existentes.
      cout << tchubirau::getQuantity() << endl;
    }

    if (modo ==
        'P') { // imprime o id e o endereço de memória do i-ésimo elemento da
               // lista. Se i for um valor inválido (menor que 1 ou maior que o
               // número de elementos) seu programa deverá imprimir "ERRO"

      int i, n;
      cin >> n;
      list<tchubirau *>::iterator it;
      if (n < 1 || n > tchubirau::getQuantity()) {
        cout << "ERRO" << endl;
        break;
      } else {
        for (it = lista.begin(), i = 0; it != lista.end(); it++, i++) {
          if (i == n) {
            cout << (*it)->getID() << ' ' << (*it)->getAddress() << endl;
            break;
          }
        }
      }
    }

    if (modo == 'L') { // Imprime, para todos os elementos da lista, o id e o
                       // endereço de memória do objeto, sendo um elemento por
                       // linha com quebra de linha no final.
      list<tchubirau *>::iterator it;
      for (it = lista.begin(); it != lista.end(); it++) {
        cout << (*it)->getID() << ' ' << (*it)->getAddress() << endl;
      }
    }

    if (modo == 'E') { // termina a execução do programa.
      while (1) {
        if (lista.empty()) {
          break;
        } else {
          delete lista.front();
          lista.pop_front();
        }
      }
      break;
    }
  }

  return 0;
}