#include "Campeonato.hpp"
#include "PokemonAquatico.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonExplosivo.hpp"
#include "Treinador.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Campeonato::cadastrar_treinador(std::string nome) {
  Treinador *tr = new Treinador(nome);
  this->_treinadores.push_back(tr);
}

void Campeonato::cadastrar_pokemon_eletrico(int idt, string nome,
                                            string tipo_ataque,
                                            double forca_ataque,
                                            double potencia_raio) {
  vector<Treinador *>::iterator it;
  int i = 0;
  for (it = _treinadores.begin(); it != _treinadores.end(); it++, i++) {
    if (i == idt) {
      (*it)->cadastrar_pokemon_eletrico(nome, tipo_ataque, forca_ataque,
                                        potencia_raio);
    }
  }
}

void Campeonato::cadastrar_pokemon_aquatico(int idt, string nome,
                                            string tipo_ataque,
                                            double forca_ataque,
                                            double litros_jato) {
  vector<Treinador *>::iterator it;
  int i = 0;
  for (it = _treinadores.begin(); it != _treinadores.end(); it++, i++) {
    if (i == idt) {
      (*it)->cadastrar_pokemon_aquatico(nome, tipo_ataque, forca_ataque,
                                        litros_jato);
    }
  }
}

void Campeonato::cadastrar_pokemon_explosivo(int idt, string nome,
                                             string tipo_ataque,
                                             double forca_ataque,
                                             double temperatura_explosao) {
  vector<Treinador *>::iterator it;
  int i = 0;
  for (it = _treinadores.begin(); it != _treinadores.end(); it++, i++) {
    if (i == idt) {
      (*it)->cadastrar_pokemon_explosivo(nome, tipo_ataque, forca_ataque,
                                         temperatura_explosao);
    }
  }
}

void Campeonato::imprimir_informacoes_treinador(int idt) {
  vector<Treinador *>::iterator it;
  int a = 0;
  for (it = _treinadores.begin(); it != _treinadores.end(); it++, a++) {
    if (a == idt) {
      (*it)->imprimir_informacoes();
    }
  }
}

void Campeonato::executar_batalha(int idt1, int idpk1, int idt2, int idpk2) {
  cout << "### Batalha ###" << endl;
  Treinador *t1, *t2;
  int i = 0;
  vector<Treinador *>::iterator it;
  for (it = _treinadores.begin(); it != _treinadores.end(); it++, i++) {
      if (i == idt1) {
          t1 = *it;
      }
      if (i == idt2) {
          t2 = *it;
      }
  }
  
  Pokemon *p1, *p2;
  p1 = (*t1).usar_pokemon(idpk1);
  p2 = (*t2).usar_pokemon(idpk2);

    cout << (*t1)._nome << ' ' << "(" << p1->_nome << ")" << ' ' << "vs." << ' ';
    cout << (*t2)._nome << ' ' << "(" << p2->_nome << ")" << endl;

  (*p1).atacar(*p2);
  (*p2).imprimir_status();
  cout << "#########" << endl;
}