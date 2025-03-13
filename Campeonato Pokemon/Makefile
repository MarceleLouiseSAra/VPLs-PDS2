CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BIN_DIR=bin

greetings:
	@echo "Compilação realizada com sucesso!"

$(OBJ_DIR)/Campeonato.o: $(INCLUDE_DIR)/Campeonato.hpp $(SRC_DIR)/Campeonato.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Campeonato.cpp -I$(INCLUDE_DIR) -o $@

$(OBJ_DIR)/Treinador.o: $(INCLUDE_DIR)/Treinador.hpp $(SRC_DIR)/Treinador.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Treinador.cpp -I$(INCLUDE_DIR) -o $@

$(OBJ_DIR)/Pokemon.o: $(INCLUDE_DIR)/Pokemon.hpp $(SRC_DIR)/Pokemon.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Pokemon.cpp -I$(INCLUDE_DIR) -o $@

$(OBJ_DIR)/PokemonAquatico.o: $(INCLUDE_DIR)/Pokemon.hpp $(INCLUDE_DIR)/PokemonAquatico.hpp $(SRC_DIR)/PokemonAquatico.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/PokemonAquatico.cpp -I$(INCLUDE_DIR) -o $@

$(OBJ_DIR)/PokemonEletrico.o: $(INCLUDE_DIR)/Pokemon.hpp $(INCLUDE_DIR)/PokemonEletrico.hpp $(SRC_DIR)/PokemonEletrico.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/PokemonEletrico.cpp -I$(INCLUDE_DIR) -o $@

$(OBJ_DIR)/PokemonExplosivo.o: $(INCLUDE_DIR)/Pokemon.hpp $(INCLUDE_DIR)/PokemonExplosivo.hpp $(SRC_DIR)/PokemonExplosivo.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/PokemonExplosivo.cpp -I$(INCLUDE_DIR) -o $@

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/Campeonato.hpp $(INCLUDE_DIR)/Treinador.hpp $(INCLUDE_DIR)/Pokemon.hpp $(INCLUDE_DIR)/PokemonAquatico.hpp $(INCLUDE_DIR)/PokemonEletrico.hpp $(INCLUDE_DIR)/PokemonExplosivo.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $@

run: $(OBJ_DIR)/Campeonato.o $(OBJ_DIR)/Treinador.o $(OBJ_DIR)/Pokemon.o $(OBJ_DIR)/PokemonAquatico.o $(OBJ_DIR)/PokemonEletrico.o $(OBJ_DIR)/PokemonExplosivo.o $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

all: run

build: run greetings

clean: $(OBJ_DIR)/Campeonato.o $(OBJ_DIR)/Treinador.o $(OBJ_DIR)/Pokemon.o $(OBJ_DIR)/PokemonAquatico.o $(OBJ_DIR)/PokemonEletrico.o $(OBJ_DIR)/PokemonExplosivo.o $(OBJ_DIR)/main.o $(BIN_DIR)/run
	rm $^