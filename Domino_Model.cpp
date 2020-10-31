//Grupo: ALEK
//Funcionalidade: cria as pecas do jogo do domino

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

void flush_in();


typedef struct Pecas
{
    int left_side;
    int right_side;
    int status;
    int jogador;
} Peca;

typedef struct Jogador
{
    int indexPecas[28];
    bool status[28];
} tipoJ;

typedef struct Mesa
{
    int index_Mesa[28];
} tipoM;


//funcao para limpar opcao
void flush_in()
{ 
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n'){} 
}