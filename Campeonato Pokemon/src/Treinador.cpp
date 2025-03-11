#include "Treinador.hpp"
#include "Pokemon.hpp"
#include "PokemonAquatico.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonExplosivo.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Treinador::Treinador(string nome) : _nome(nome) {}

void Treinador::cadastrar_pokemon_eletrico(string nome, string tipo_ataque,
                                           double forca_ataque,
                                           double potencia_raio) {
  Pokemon *pk =
      new PokemonEletrico(nome, tipo_ataque, forca_ataque, potencia_raio);
  this->_pokemons.push_back(pk);
}

void Treinador::cadastrar_pokemon_aquatico(string nome, string tipo_ataque,
                                           double forca_ataque,
                                           double litros_jato) {
  Pokemon *pk = new PokemonAquatico(nome, tipo_ataque, forca_ataque, litros_jato);
  this->_pokemons.push_back(pk);
}

void Treinador::cadastrar_pokemon_explosivo(string nome, string tipo_ataque,
                                            double forca_ataque,
                                            double temperatura_explosao) {
  Pokemon *pk = new PokemonExplosivo(nome, tipo_ataque, forca_ataque,
                                     temperatura_explosao);
  this->_pokemons.push_back(pk);
}

Pokemon *Treinador::usar_pokemon(int idpk) {
  vector<Pokemon *>::iterator it;
  int i = 0;
  for (it = _pokemons.begin(); it != _pokemons.end(); it++, i++) {
    if (i == idpk) {
      return (*it);
    }
  }
  return nullptr;
}

void Treinador::imprimir_informacoes() {
  if (!_pokemons.empty()) {
      
    cout << "Nome:" << ' ' << this->_nome << endl;
    cout << "----------" << endl;
    vector<Pokemon *>::iterator it;
    
    for (it = _pokemons.begin(); it != _pokemons.end(); it++) {
      (*it)->imprimir_informacoes();
      cout << "----------" << endl;
    }
  } else {
    cout << "Nome:" << ' ' << this->_nome << endl;
    cout << "----------" << endl;
    cout << "Nenhum Pokemon cadastrado!" << endl;
    cout << "----------" << endl;
  }
}
