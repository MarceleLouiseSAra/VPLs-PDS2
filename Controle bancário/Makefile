CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BIN_DIR=bin

all: vpl_execution

$(OBJ_DIR)/ContaBancaria.o: $(INCLUDE_DIR)/ContaBancaria.hpp $(SRC_DIR)/ContaBancaria.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ContaBancaria.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/ContaBancaria.o
    
$(OBJ_DIR)/Banco.o: $(INCLUDE_DIR)/Banco.hpp $(SRC_DIR)/Banco.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Banco.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Banco.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/ContaBancaria.hpp $(INCLUDE_DIR)/Banco.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o
    
vpl_execution: $(OBJ_DIR)/main.o $(OBJ_DIR)/ContaBancaria.o $(OBJ_DIR)/Banco.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/ContaBancaria.o $(OBJ_DIR)/Banco.o -o $(BIN_DIR)/$@

clean: $(OBJ_DIR)/main.o $(OBJ_DIR)/ContaBancaria.o $(OBJ_DIR)/Banco.o $(BIN_DIR)/vpl_execution
	rm $^