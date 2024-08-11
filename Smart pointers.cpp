#include <iostream>
#include <memory>

using namespace std;

class Teste {
public:
  int number;

  Teste() {
    this->number = 0;
    cout << "Construtor " << this->number << endl;
  }

  Teste(int x) : number(x) { cout << "Construtor " << this->number << endl; }

  ~Teste() { cout << "Destrutor " << this->number << endl; }
};

int main() {

  int n;
  cin >> n;

  if (n % 2 == 0) {
    for (int c = 1; c <= n; c++) {
      __attribute__((unused)) Teste *aux1 = new Teste(c);//quando o escopo do PONTEIRO para teste acaba, ele para de existir, mas o objeto apontado por ele não é desalocado
      __attribute__((unused)) unique_ptr<Teste> aux2(new Teste(c));//somente o unique_ptr chama o destrutor
      //delete aux1;
      //se quiser chamar o destrutor do objeto apontado por aux1, tem que desalocar aux1
    }
  }

  if (n % 2 != 0) {
    shared_ptr<Teste> aux1(new Teste(0));
    for (int c = 1; c <= n; c++) {
      shared_ptr<Teste> aux2 = aux1;
      (*aux2).number = c;
    }
    cout << aux1.use_count() << endl;
  }

  return 0;
}