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

    //atribui pecas jog1
    for (int i = 0; i < 7; i++)
    {
        jogador1.indexPecas[i] = randomEmbaralha[i];
    }
    //atribui pecas jog2
    for (int i = 0; i < 7; i++)
    {
        jogador2.indexPecas[i] = randomEmbaralha[i+7];
    }
    
    //printa pecas jog1
    printf("\nPecas jogador 1:");
    for (int i = 0; i < 7; i++)
    {
        printf("\n[%d|%d]", domino_pecas[jogador1.indexPecas[i]].left_side, domino_pecas[jogador1.indexPecas[i]].right_side); 
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
        printf("\n[%d|%d]", domino_pecas[jogador2.indexPecas[i]].left_side, domino_pecas[jogador2.indexPecas[i]].right_side); 
        printf(" ");
        if (i%7 == 0 && i != 0)
        {
            printf("\n");
        }
    } 

    int bigger_piece_jog1 = '\0';
    bool sentinela_jog1 = false;
    for (int i = 0; i < 7; i++)
    {
        if(domino_pecas[jogador1.indexPecas[i]].left_side == domino_pecas[jogador1.indexPecas[i]].right_side)
        {
            if((domino_pecas[bigger_piece_jog1].left_side + domino_pecas[bigger_piece_jog1].right_side) < (domino_pecas[jogador1.indexPecas[i]].left_side + domino_pecas[jogador1.indexPecas[i]].right_side))
            {
                bigger_piece_jog1 = jogador1.indexPecas[i];
            }
        }    
    }
    
    if (bigger_piece_jog1 != '\0')
    {
        sentinela_jog1 = true;
    }
    

    int bigger_piece_jog2 = '\0';
    bool sentinela_jog2 = false;
    for (int i = 0; i < 7; i++)
    {
        if(domino_pecas[jogador2.indexPecas[i]].left_side == domino_pecas[jogador2.indexPecas[i]].right_side)
        {
            if((domino_pecas[bigger_piece_jog2].left_side + domino_pecas[bigger_piece_jog2].right_side) < (domino_pecas[jogador2.indexPecas[i]].left_side + domino_pecas[jogador2.indexPecas[i]].right_side))
            {
                bigger_piece_jog2 = jogador2.indexPecas[i];
            }
        }    
    }
    //printf("\n\n\n\n\n%d", bigger_piece_jog2);
    if (bigger_piece_jog2 != '\0')
    {
        sentinela_jog2 = true;
    }
    
    if(bigger_piece_jog1 == '\0' && bigger_piece_jog2 == '\0')
    {
        if((domino_pecas[bigger_piece_jog1].left_side != 0 && domino_pecas[bigger_piece_jog1].right_side != 0) || (domino_pecas[bigger_piece_jog2].left_side != 0 && domino_pecas[bigger_piece_jog1].right_side != 0))
        {
        for (int i = 0; i < 7; i++)
        {
                if((domino_pecas[bigger_piece_jog1].left_side + domino_pecas[bigger_piece_jog1].right_side) < (domino_pecas[jogador1.indexPecas[i]].left_side + domino_pecas[jogador1.indexPecas[i]].right_side))
                {
                    printf("gay");
                }
            }
        }
        printf("\n\n\n\n\n%d do lado de dentro jogador 1", bigger_piece_jog1);
        printf("\n[%d|%d]", domino_pecas[bigger_piece_jog1].left_side, domino_pecas[bigger_piece_jog1].right_side);
        
        printf("\n\n\n\n\n%d do lado de dentro jogador 2", bigger_piece_jog2);
        printf("\n[%d|%d]", domino_pecas[bigger_piece_jog2].left_side, domino_pecas[bigger_piece_jog2].right_side);

    }
    printf("\n\n\n\n\n%d do lado de fora jogador 1", bigger_piece_jog1);
    printf("\n[%d|%d]", domino_pecas[bigger_piece_jog1].left_side, domino_pecas[bigger_piece_jog1].right_side);

    printf("\n\n\n\n\n%d do lado de fora jogador 2", bigger_piece_jog2);
    printf("\n[%d|%d]", domino_pecas[bigger_piece_jog2].left_side, domino_pecas[bigger_piece_jog2].right_side);

}