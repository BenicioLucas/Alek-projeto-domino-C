#include <stdio.h>

#include "./Domino_View.cpp"

void jogo()
{
    Peca domino_pecas[28];

    Jogador jogador1;
    Jogador jogador2;
    
    int index = 0;
    //preenche a array pecas
    for(int l = 0; l < 7; l++){
       for(int r = 0; r < 7; r++){
           if(l<=r){
            domino_pecas[index].left_side = l;
            domino_pecas[index].right_side = r;
            index++;
           } 
        }
    }

    int randomEmbaralha[28];
    srand(time(NULL));
    for (int i = 0; i < 28; i++)
    {
        randomEmbaralha[i] = i;
    }

    for (int i = 0; i < 28; i++)
    {
        int j = randomEmbaralha[i];
        int posicao_rand = rand()%27;
        randomEmbaralha[i] = randomEmbaralha[posicao_rand];
        randomEmbaralha[posicao_rand] = j;
    }


    int bigger_piece_jog1 = '\0';
    int bigger_piece_jog2 = '\0';


    //atribui pecas jog1
    for (int i = 0; i < 7; i++)
    {
        jogador1.indexPecas[i] = i;
    }
    //atribui pecas jog2
    for (int i = 0; i < 7; i++)
    {
        jogador2.indexPecas[i] = i+7; 
    }
    
    //printa pecas jog1
    printf("\nPecas jogador 1:");
    for (int i = 0; i < 7; i++)
    {
        printf("\n[%d|%d]", domino_pecas[randomEmbaralha[jogador1.indexPecas[i]]].left_side,domino_pecas[randomEmbaralha[jogador1.indexPecas[i]]].right_side); 
        printf(" ");
        if (i%7 == 0 && i != 0)
        {
            printf("\n");
        }
    }
    //printa pecas jog2
    printf("\nPecas jogador 2:");
    for (int i = 0; i < 7; i++)
    {
        printf("\n[%d|%d]", domino_pecas[randomEmbaralha[jogador2.indexPecas[i]]].left_side,domino_pecas[randomEmbaralha[jogador2.indexPecas[i]]].right_side); 
        printf(" ");
        if (i%7 == 0 && i != 0)
        {
            printf("\n");
        }
    } 

    
    
}