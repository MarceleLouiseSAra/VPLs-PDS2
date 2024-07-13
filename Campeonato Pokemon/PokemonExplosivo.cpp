#include "PokemonExplosivo.hpp"
#include "Pokemon.hpp"
#include <iostream>
#include <string>

using namespace std;

PokemonExplosivo::PokemonExplosivo(string nome, string tipo_ataque,
                                   double forca_ataque,
                                   double temperatura_explosao)
    : Pokemon(nome, tipo_ataque, forca_ataque),
      _temperatura_explosao(temperatura_explosao) {}

void PokemonExplosivo::falar_tipo_ataque() {
  Pokemon::falar_tipo_ataque();
  cout << "Boom!" << endl;
}

double PokemonExplosivo::ataque_explosivo() {
  return this->_forca_ataque / this->_temperatura_explosao;
}

double PokemonExplosivo::calcular_dano() { return this->ataque_explosivo(); }