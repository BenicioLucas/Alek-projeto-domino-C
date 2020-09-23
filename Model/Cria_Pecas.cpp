//Grupo: ALEK
//Funcionalidade: cria as pecas do jogo do domino

#include <stdio.h>

typedef struct Pecas
{
    int left_side;
    int rigth_side;
    char status; //branco, 1, 2, m
    
} Peca;


void cria_pecas()
{
    Peca pecas[28];
    int i = 0;
    for(int l = 0; l < 7; l++){
       for(int r = l; r < 7; r++){
            pecas[i].left_side = l;
            pecas[i].rigth_side = r;
            i++;
        }
    }

    //for pra printar as peças
    for (int i = 0; i < 28; i++)
    {
        printf("[%d|%d]\n", pecas[i].left_side, pecas[i].rigth_side);
    }
    
}
