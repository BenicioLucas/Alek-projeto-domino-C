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
    char status;
    int jogador;
} Peca;

Peca pecas[28];

typedef struct Jogador
{
    int indexPecas[28];

} tipoJ;

struct Mesa
{
    int lado1;
    int lado2;
} mesa[28];


//funcao para limpar opcao
void flush_in(){ 
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n'){} 
}
