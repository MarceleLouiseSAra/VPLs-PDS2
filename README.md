# VPLs de P.D.S. II

*Programação e Desenvolvimento de Software II* é uma matéria ofertada pelo Departamento de Ciência da Computação da Universidade Federal de Minas Gerais 
e que utiliza da linguagem de programação *C++* para introduzir os conceitos que caracterizam o paradigma de programação orientada a objetos – no qual, por sua vez, 
contribui para a criação de um código enxuto, modularizado (organizado em subdivisões, promovendo a indepedência entre diferentes partes do código) e escalável.

Em particular, chamo atenção para o uso de um arquivo *Makefile* para otimizar o processo de compilação; a sua utilização garante que arquivos que não sofreram alterações sejam recompilados desnecessariamente.

## Modo de uso

### Para os programas em /,

```bash
# digite, no terminal, os comandos:
g++ <nome_do_arquivo>.cpp -o <nome_do_arquivo>
./<nome_do_arquivo>
```

### Para o programa em "Controle de alunos",

```bash
# digite, no terminal, os comandos:
g++ -c aluno.cpp -o aluno.o
g++ -c main.cpp -o main.o
g++ main.o aluno.o -o main
./main
```

### Para os programas nas demais pastas,

```bash
# gere o executável ao digitar, no terminal, o comando:
make all
```

```bash
# Então, mude o diretório para a pasta "bin" com o comando
cd bin
```

```bash
# A seguir, digite:
./vpl_execution
```

```bash
# Para excluir os arquivos .o, volte para o diretório anterior com o comando
cd ..
```

```bash
# e digite 
 make clean
```

Infelizmente, o programa que se encontra na pasta "HeapInt" (ainda) não pode ser executado.
