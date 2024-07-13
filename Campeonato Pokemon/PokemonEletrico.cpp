#include "PokemonEletrico.hpp"
#include "Pokemon.hpp"
#include <iostream>
#include <string>

using namespace std;

PokemonEletrico::PokemonEletrico(string nome, string tipo_ataque,
                                 double forca_ataque, double potencia_raio)
    : Pokemon(nome, tipo_ataque, forca_ataque), _potencia_raio(potencia_raio) {}

void PokemonEletrico::falar_tipo_ataque() {
  Pokemon::falar_tipo_ataque();
  cout << "Bzzzz!" << endl;
}

double PokemonEletrico::ataque_eletrico() {
  return this->_forca_ataque * this->_potencia_raio;
}

double PokemonEletrico::calcular_dano() { return this->ataque_eletrico(); }