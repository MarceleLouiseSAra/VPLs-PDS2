#include "PokemonAquatico.hpp"
#include "Pokemon.hpp"
#include <iostream>
#include <string>

using namespace std;

PokemonAquatico::PokemonAquatico(string nome, string tipo_ataque,
                                 double forca_ataque, double litros_jato)
    : Pokemon(nome, tipo_ataque, forca_ataque), _litros_jato(litros_jato) {}

void PokemonAquatico::falar_tipo_ataque() {
  Pokemon::falar_tipo_ataque();
  cout << "Splash!" << endl;
}

double PokemonAquatico::ataque_aquatico() {
  return this->_forca_ataque + this->_litros_jato;
}

double PokemonAquatico::calcular_dano() { return this->ataque_aquatico(); }