#ifndef PokemonEletrico_H
#define PokemonEletrico_H
#include "Pokemon.hpp"
#include <string>

using namespace std;

class PokemonEletrico : public Pokemon {
    public:
    double _potencia_raio;

    PokemonEletrico(string nome, string tipo_ataque, double forca_ataque, double potencia_raio);

    virtual void falar_tipo_ataque() override;

    virtual double calcular_dano() override;

    double ataque_eletrico();
};

#endif