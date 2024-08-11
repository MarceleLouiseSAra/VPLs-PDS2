#include <iostream>
#include <vector>

using namespace std;

class NegativeResultException : public exception {
public:
  int valor;

  NegativeResultException(int x) : valor(x) {}

  virtual const char *what() const throw() {
    return "Erro: Resultado Negativo.";
  }
};

int main() {

  vector<int> vetor;
  vetor.push_back(-20);
  vetor.push_back(-10);
  vetor.push_back(0);
  vetor.push_back(10);
  vetor.push_back(20);

  int n;
  try {
    cin >> n;

    if (vetor.at(n) < 0) {
      throw NegativeResultException(n);
    } else {
      cout << vetor.at(n);
    }

  } catch (NegativeResultException &e) {
    cout << e.what() << endl;
    cout << vetor.at(n) << endl;
  } catch (exception &e) {
    cout << e.what() << endl;
  }

  return 0;
}