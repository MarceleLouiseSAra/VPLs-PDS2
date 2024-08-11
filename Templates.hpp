#include <iostream>
#include <string>

using namespace std;

template<typename T>

class Vetor {
  public:
  int i;
  int n;
  T *p;

  Vetor(int n){
    this->n = n;
    this->i = 0;
    this->p = new T[this->n];
  }

  Vetor(Vetor &source){
    this->i = source.i;
    this->n = source.n;
    this->p = new T[source.n];
    for(int i = 0; i < source.n; i++){
        this->p[i] = source.p[i];
    }
  }

  ~Vetor(){
    delete[] p;
  }

  void SetElemento(int i, T x){
    if(i < this->n){
      p[i] = x;
    }
  }

  T GetElemento(int i){
    if(i < this->n){
      return this->p[i];
    }
    return 0;
  }

  void AdicionaElemento(T x){
    if(this->i < n){
      this->p[i] = x;
      this->i++;
    }
  }

  void Imprime(){
    cout << this->p[0];
    for(int i = 1; i < this->n; i++){
      cout << ' ' << this->p[i];
    }
    cout << '\n';
  }

};