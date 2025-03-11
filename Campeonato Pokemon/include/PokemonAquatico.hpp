#ifndef PokemonAquatico_H
#define PokemonAquatico_H
#include "Pokemon.hpp"
#include <string>

using namespace std;

class PokemonAquatico : public Pokemon {
  public:
  double _litros_jato;

  PokemonAquatico(string nome, string tipo_ataque, double forca_ataque, double litros_jato);

  virtual void falar_tipo_ataque() override;

  virtual double calcular_dano() override;

  double ataque_aquatico();

};

#endif