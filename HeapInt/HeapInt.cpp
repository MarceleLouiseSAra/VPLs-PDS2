#include "HeapInt.hpp"
#include <iostream>

using namespace std;

HeapInt::HeapInt() {
//   cout << "Entrei no construtor." << endl;
  this->p = new int;
  *(this->p) = 0;
}

HeapInt::HeapInt(int x) {
//   cout << "Entrei no construtor." << endl;
  this->p = new int;
  *(this->p) = x;
}

HeapInt::HeapInt(const HeapInt &copy) {
//   cout << "Construtor por cópia foi chamado." << endl;
  this->p = new int;
  *(this->p) = *(copy.p);
}

HeapInt::~HeapInt() {
//   cout << "Entrei no destrutor." << endl;
  delete p;
}

void HeapInt::operator=(int value) {
  this->p = new int;
  *(this->p) = value;
}

HeapInt HeapInt::operator=(const HeapInt &copy) {
//   cout << "Assigment operator foi chamado." << endl;
  this->p = new int;
  *(this->p) = *(copy.p);
  return *this;
}

HeapInt HeapInt::operator+(const HeapInt &copy) {
  HeapInt aux;
  *(aux.p) = *(this->p) + *(copy.p);
  return aux;
}

HeapInt HeapInt::operator-(const HeapInt &copy) {
  HeapInt aux;
  *(aux.p) = *(this->p) - *(copy.p);
  return aux;
}

bool HeapInt::operator==(const HeapInt &copy) {
  if (*(this->p) == *(copy.p)) {
    return true;
  }
  return false;
}

istream& operator>>(istream &is, const HeapInt &copy) {
  is >> *(copy.p);
  return is;
}

ostream& operator<<(ostream &os, const HeapInt &copy) {
  os << *(copy.p);
  return os;
}