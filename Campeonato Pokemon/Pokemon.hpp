#ifndef Pokemon_H
#define Pokemon_H
#include <iostream>
#include <string>

using namespace std;

class Pokemon{
    public:
    string _nome;
    string _tipo_ataque;
    double _forca_ataque; 
    double _energia;

    void to_upper(string &s);

    Pokemon(string nome, string tipo_ataque, double forca_ataque);

    void falar_nome();

    virtual void falar_tipo_ataque();

    void imprimir_status();

    void imprimir_informacoes();

    virtual double calcular_dano() = 0;

    void atacar(Pokemon &outro_pokemon);

    void receber_dano(double valor_dano);
};

#endif