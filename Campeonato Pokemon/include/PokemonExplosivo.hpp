#ifndef PokemonExplosivo_H
#define PokemonExplosivo_H
#include "Pokemon.hpp"
#include <string>

using namespace std;

class PokemonExplosivo : public Pokemon {
  public:
  double _temperatura_explosao;

  PokemonExplosivo(std::string nome, std::string tipo_ataque, double forca_ataque, double temperatura_explosao);

  virtual void falar_tipo_ataque() override;

  virtual double calcular_dano() override;

  double ataque_explosivo();

};

#endif