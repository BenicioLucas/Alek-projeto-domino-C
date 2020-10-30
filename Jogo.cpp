#include <stdio.h>

#include "./Domino_View.cpp"

void jogo()
{
    Peca domino_pecas[28];

    int jogadorPecas1  = 7;
    int jogadorPecas2  = 7;

    int numera_peca = 1;
    bool playerOne,playerTwo;
    Jogador jogador1;
    Jogador jogador2;
   
    
    int index = 0;
    //preenche a array pecas
    for(int l = 0; l < 7; l++)
    {
       for(int r = 0; r < 7; r++)
        {
            if(l<=r)
            {
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
    
    int jogador_start;
    int jogador_next;

    bool acha_igual_jog1 = false;
    int bigger_piece_jog1 = '\0';
    for (int i = 0; i < 7; i++)
    {
        if(domino_pecas[jogador1.indexPecas[i]].left_side == domino_pecas[jogador1.indexPecas[i]].right_side)
        {
            if((domino_pecas[bigger_piece_jog1].left_side + domino_pecas[bigger_piece_jog1].right_side) < (domino_pecas[jogador1.indexPecas[i]].left_side + domino_pecas[jogador1.indexPecas[i]].right_side))
            {
                bigger_piece_jog1 = jogador1.indexPecas[i];
            }
            acha_igual_jog1 = true;
        }    
    }
    
    

    int bigger_piece_jog2 = '\0';
    bool acha_igual_jog2 = false;
    for (int i = 0; i < 7; i++)
    {
        if(domino_pecas[jogador2.indexPecas[i]].left_side == domino_pecas[jogador2.indexPecas[i]].right_side)
        {
            if((domino_pecas[bigger_piece_jog2].left_side + domino_pecas[bigger_piece_jog2].right_side) < (domino_pecas[jogador2.indexPecas[i]].left_side + domino_pecas[jogador2.indexPecas[i]].right_side))
            {
                bigger_piece_jog2 = jogador2.indexPecas[i];
            }
            acha_igual_jog2 = true;
        }    
    }


    if(bigger_piece_jog1 == '\0' && bigger_piece_jog2 == '\0')
    {
        if((domino_pecas[bigger_piece_jog1].left_side != 0 && domino_pecas[bigger_piece_jog1].right_side != 0) || (domino_pecas[bigger_piece_jog2].left_side != 0 && domino_pecas[bigger_piece_jog1].right_side != 0))
        {
            for (int i = 0; i < 7; i++)
            {
                if((domino_pecas[bigger_piece_jog1].left_side + domino_pecas[bigger_piece_jog1].right_side) < (domino_pecas[jogador1.indexPecas[i]].left_side + domino_pecas[jogador1.indexPecas[i]].right_side))
                {
                   bigger_piece_jog1 = jogador1.indexPecas[i];
                }
            }
            
            for (int i = 0; i < 7; i++)
            {
                if((domino_pecas[bigger_piece_jog2].left_side + domino_pecas[bigger_piece_jog1].right_side) < (domino_pecas[jogador2.indexPecas[i]].left_side + domino_pecas[jogador2.indexPecas[i]].right_side))
                {
                   bigger_piece_jog1 = jogador2.indexPecas[i];
                }
            }

            if((domino_pecas[bigger_piece_jog1].left_side + domino_pecas[bigger_piece_jog1].right_side) > (domino_pecas[bigger_piece_jog2].left_side + domino_pecas[bigger_piece_jog2].right_side))
            {
                jogador_start = 1;
                jogador_next = 2;
            }else
            {
                jogador_start = 2;
                jogador_next = 1;
            }
            
        }
        
    }


    if(acha_igual_jog1 && acha_igual_jog2)
    {
        if(domino_pecas[bigger_piece_jog1].left_side > domino_pecas[bigger_piece_jog2].left_side)
        {
            printf("\n\nJOGADOR 1 COMEÇA");
            jogador_start = 1;
            jogador_next = 2;

        }else
        {
            printf("\n\nJOGADOR 2 COMEÇA");
            jogador_start = 2;
            jogador_next = 1;
        }
    }else if(acha_igual_jog1 && !acha_igual_jog2)
    {
        jogador_start = 1;
        jogador_next = 2;
        printf("\n\nJOGADOR 1 COMEÇA");
    }else if(!acha_igual_jog1 && acha_igual_jog2)
    {
        jogador_start = 2;
        jogador_next = 1;
        printf("\n\nJOGADOR 2 COMEÇA");
    }

    bool win_condition = false;

    //CRIA MESA
    Mesa mesa;
    int contador_mesa = 0;
    int index_compra = 7;
    int guarda_compra = 0;
    do
    {
        do
        {
            if(jogador_start == 1)
            {
                //PRINTA MESA
                for (int i = 0; i < contador_mesa; i++)
                {
                    printf("[%d|%d]", domino_pecas[jogador1.indexPecas[mesa.index_mesa[i]]].left_side, domino_pecas[jogador1.indexPecas[mesa.index_mesa[i]]].right_side);
                }

                linha_175:
                
                   //NUMERA PECAS
                    for (int i = 0; i < jogadorPecas1; i++) 
                    {
                        printf("%d.[%d|%d]\n",numera_peca, domino_pecas[jogador1.indexPecas[i]].left_side, domino_pecas[jogador1.indexPecas[i]].right_side);
                        numera_peca++;
                    }
                    numera_peca = 1;

            }else if(jogador_start == 2)
            {
                
                
                for (int i = 0; i < jogadorPecas2 ; i++) 
                {
                    printf("%d.[%d|%d]\n",numera_peca, domino_pecas[jogador2.indexPecas[i]].left_side, domino_pecas[jogador2.indexPecas[i]].right_side);
                    numera_peca++;
                }
                numera_peca = 1; 
            }
            
            printf("\n(1) - Jogar");
            printf("\n(2) - Comprar peça");
            printf("\n(3) - Sair do jogo");

            int escolhe_menu_player;
            printf("\n\nSUA ESCOLHA FOI: \n");
            scanf("%d", &escolhe_menu_player);
            flush_in();
            switch (escolhe_menu_player)
            {
                case 1:
                int peca_jogada;
                printf("\nEscolha uma peça:\n");
                scanf("%d", &peca_jogada);
                mesa.index_mesa[contador_mesa] = peca_jogada-1;
                contador_mesa++;
                flush_in();
                break;

                case 2:
                char compra_sn;
                printf("\n\nDESEJA MESMO COMPRA UMA PECA (S/N): \n");
                compra_sn = getchar();
                flush_in();
                if(toupper(compra_sn) == 'S')
                {
                    jogador1.indexPecas[index_compra] = randomEmbaralha[guarda_compra+14];
                    guarda_compra++;
                    index_compra++;
                    jogadorPecas1++;

                    goto linha_175;
                    
                }
                break;

                case 3:
                exit(1);
            
                default:
                break;
            }
        }while(jogador_start);

        do
        {
            
        }while(jogador_next);

    }while(!win_condition); 
        
}
