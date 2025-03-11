// #include "avaliacao_basica_pokemon.hpp"
#include "Campeonato.hpp"
#include "Pokemon.hpp"
#include "PokemonAquatico.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonExplosivo.hpp"
#include "Treinador.hpp"
#include <iostream>
#include <string>

int main() {
  // cout << "entrei na main" << endl;

  Campeonato _Campeonato;

  char modo;

  while (cin >> modo) {

    if (modo == 't') { // comando para cadastrar um treinador no campeonato
      //cout << "entrei no t" << endl;
      string nome;
      cin >> nome;
      _Campeonato.cadastrar_treinador(nome);
    }

    if (modo == 'i') { // comando para imprimir as informações de um treinador
                       // de acordo com o id
      //cout << "entrei no i" << endl;
      int idt;
      cin >> idt;
      _Campeonato.imprimir_informacoes_treinador(idt);
    }

    if (modo == 'e') { // comando para adicionar um PokemonEletrico ao treinador
                       // informado.
      //cout << "entrei no e" << endl;
      int idt;
      string nome, tipo_ataque;
      double forca_ataque, potencia_raio;
      cin >> idt;
      cin >> nome;
      cin >> tipo_ataque;
      cin >> forca_ataque;
      cin >> potencia_raio;
      _Campeonato.cadastrar_pokemon_eletrico(idt, nome, tipo_ataque,
                                             forca_ataque, potencia_raio);
    }

    if (modo == 'q') { // comando para adicionar um PokemonAquatico ao treinador
                       // informado
      //cout << "entrei no q" << endl;
      int idt;
      string nome, tipo_ataque;
      double forca_ataque, litros_jato;
      cin >> idt;
      cin >> nome;
      cin >> tipo_ataque;
      cin >> forca_ataque;
      cin >> litros_jato;
      _Campeonato.cadastrar_pokemon_aquatico(idt, nome, tipo_ataque,
                                             forca_ataque, litros_jato);
    }

    if (modo == 'x') { // comando para adicionar um PokemonExplosivo ao
                       // treinador informado
      //cout << "entrei no x" << endl;
      int idt;
      string nome, tipo_ataque;
      double forca_ataque, temperatura_explosao;
      cin >> idt;
      cin >> nome;
      cin >> tipo_ataque;
      cin >> forca_ataque;
      cin >> temperatura_explosao;
      _Campeonato.cadastrar_pokemon_explosivo(
          idt, nome, tipo_ataque, forca_ataque, temperatura_explosao);
    }

    if (modo == 'h') { // comando para realizar uma batalha de acordo com os ids
                       // informados
      //cout << "entrei no h" << endl;
      int idt1, idpk1, idt2, idpk2;
      cin >> idt1;
      cin >> idpk1;
      cin >> idt2;
      cin >> idpk2;
      _Campeonato.executar_batalha(idt1, idpk1, idt2, idpk2);
    }

    if (modo == 'b') { // deve chamar a função 'avaliacao_basica()' implementada
                       // no arquivo "avaliacao_basica_pokemon.hpp" (já incluído
                       // no main.cpp). Essa função faz uma avaliação
                       // complementar do código (não apenas dos resultados)
      //cout << "entrei no b" << endl;
      // avaliacao_basica();
    }

    // if (modo == 'E') {
    //   break;
    // }
  }

  return 0;
}