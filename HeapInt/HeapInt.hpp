#ifndef HeapInt_H
#define HeapInt_H
#include <iostream>

using namespace std;

class HeapInt{
  public:
  int *p;

  HeapInt();

  HeapInt(int x);

  HeapInt(const HeapInt &copy);

  ~HeapInt();

  void operator=(int value);

  HeapInt operator=(const HeapInt &copy);

  HeapInt operator+(const HeapInt &copy);

  HeapInt operator-(const HeapInt &copy);

  bool operator==(const HeapInt &copy);

  friend istream& operator>>(istream &is, const HeapInt &copy);

  friend ostream& operator<<(ostream &os, const HeapInt &copy);

};

#endif