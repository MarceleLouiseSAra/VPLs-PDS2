#include "Pokemon.hpp"
#include <iostream>
#include <string>

using namespace std;

Pokemon::Pokemon(string nome, string tipo_ataque, double forca_ataque)
    : _nome(nome), _tipo_ataque(tipo_ataque), _forca_ataque(forca_ataque),
      _energia(100) {}

void Pokemon::falar_nome() { cout << this->_nome << '!' << endl; }

void Pokemon::falar_tipo_ataque() { cout << this->_tipo_ataque << '!' << endl; }

void Pokemon::imprimir_status() {
  cout << this->_nome << '!' << endl;
  cout << "Energia: " << this->_energia << endl;
}

void Pokemon::imprimir_informacoes() {
  cout << "Pokemon: " << this->_nome << endl;
  cout << "Tipo ataque: " << this->_tipo_ataque << endl;
  cout << "Dano: " << this->calcular_dano() << endl;
  cout << "Energia: " << this->_energia << endl;
}

void Pokemon::atacar(Pokemon &outro_pokemon) {
  this->falar_nome();
  this->falar_tipo_ataque();
  cout << "Dano: " << this->calcular_dano() << endl;
  outro_pokemon._energia -= this->calcular_dano();
}

void Pokemon::receber_dano(double valor_dano) {
    
  if (this->_energia > 0 && valor_dano <= this->_energia) {
    this->_energia -= valor_dano;
  }
  if (this->_energia == 0) {
    cout << this->_nome << ' ' << "morreu!" << endl;
  }
  
}