#include <stdio.h>

#include "./Domino_View.cpp"

void jogo()
{
    Peca domino_pecas[28];
    int domino_pecasMesa[28];


    for (int i = 0; i < 28; i++) {
        domino_pecasMesa[i] = '\0';
    }

    int jogadorPecas1  = 7;
    int jogadorPecas2  = 7;

    
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
            printf("\n\nJOGADOR 1 COMEÇA\n");
            jogador_start = 1;
            jogador_next = 2;

        }else
        {
            printf("\n\nJOGADOR 2 COMEÇA\n");
            jogador_start = 2;
            jogador_next = 1;
        }
    }else if(acha_igual_jog1 && !acha_igual_jog2)
    {
        jogador_start = 1;
        jogador_next = 2;
        printf("\n\nJOGADOR 1 COMEÇA\n");
    }else if(!acha_igual_jog1 && acha_igual_jog2)
    {
        jogador_start = 2;
        jogador_next = 1;
        printf("\n\nJOGADOR 2 COMEÇA\n");
    }

    bool win_condition = false;
    int jogueimerdanaparede = '\0';
    int peca_jogada;

    //CRIA MESA
    Mesa mesa;

    int pecas_deletadas[28];
    int contador_deleted = 0;
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
                   printf("\n\n[%d|%d]\n\n", domino_pecas[domino_pecasMesa[i]].left_side, domino_pecas[domino_pecasMesa[i]].right_side);
                }


                //printa_peca_add:
                   //NUMERA PECAS
                    for (int i = 0; i < jogadorPecas1; i++) 
                    {
                        printf("\n%d.[%d|%d]", i, domino_pecas[jogador1.indexPecas[i]].left_side, domino_pecas[jogador1.indexPecas[i]].right_side);
                    }


            }else if(jogador_start == 2)
            {
                
                
                for (int i = 0; i < jogadorPecas2 ; i++) 
                {
                    printf("\n[%d|%d]", domino_pecas[jogador2.indexPecas[i]].left_side, domino_pecas[jogador2.indexPecas[i]].right_side);
                }
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
                printf("\nEscolha uma peça:\n");
                scanf("%d", &peca_jogada);

                domino_pecasMesa[contador_mesa] = jogador1.indexPecas[peca_jogada];
                
                jogadorPecas1--;

                for(int k = peca_jogada; k < jogadorPecas1; k++){ // Algoritmo que joga todo o array pra esquerda
                    jogador1.indexPecas[k] = jogador1.indexPecas[k+1];
                }

              
                contador_mesa++;
                flush_in();
                jogador_start = false;
                break;

                case 2:
                char compra_sn;
                printf("\n\nDESEJA MESMO COMPRAR UMA PECA (S/N): \n");
                compra_sn = getchar();
                flush_in();
                if(toupper(compra_sn) == 'S')
                {
                    jogador1.indexPecas[index_compra] = randomEmbaralha[guarda_compra+14];
                    guarda_compra++;
                    index_compra++;
                    jogadorPecas1++;


                    //goto printa_peca_add;

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
            printf("Dou a bunda e acho gostoso");
            
        }while(jogador_next);

    }while(!win_condition); 
        
}