#include <stdio.h>

#include "./Domino_View.cpp"

void jogo()
{
    Peca domino_pecas[28];
    int domino_pecasMesa[28];
    int j = 0;

    char deseja_inv;

    char resp_inv;
    char resp_inv2;

    for (int i = 0; i < 28; i++) {
        domino_pecasMesa[i] = '\0';
        domino_pecas[i].status = 0;
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
        domino_pecas[jogador1.indexPecas[i]].status = 1;
    }

    //atribui pecas jog2
    for (int i = 0; i < 7; i++)
    {
        jogador2.indexPecas[i] = randomEmbaralha[i+7];
        domino_pecas[jogador2.indexPecas[i]].status = 1;
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
    int peca_jogada;

    //CRIA MESA
    Mesa mesa;
    int contador_deleted = 0;
    int contador_mesa = 0;
    int index_compra = 7;
    int index_compra2 = 7;

    do
    {
        do
        {
            if(jogador_start == 1)
            {
                printf("==================================================================================================================================\n");
                printf("MESA:\n");
                //PRINTA MESA
                for (int i = 0; i < contador_mesa; i++)
                {
                   printf("[%d|%d] ", domino_pecas[domino_pecasMesa[i]].left_side, domino_pecas[domino_pecasMesa[i]].right_side);
                }
                printf("\n==================================================================================================================================");
                //printa_peca_add:
                //NUMERA PECAS
                printf("\nPRINTANDO PECAS DO JOGADOR 1:");
                for (int i = 0; i < jogadorPecas1; i++) 
                {
                    printf("\n%d.[%d|%d]", i, domino_pecas[jogador1.indexPecas[i]].left_side, domino_pecas[jogador1.indexPecas[i]].right_side);
                }


            }
            else
            {
                goto jogador2;
            }
            
            printf("\n(1) - JOGAR");
            printf("\n(2) - COMPRAR PECA");
            printf("\n(3) - SAIR DO JOGO");

            int escolhe_menu_player1;
            printf("\n\nJOG1 - SUA ESCOLHA FOI: \n");
            scanf("%d", &escolhe_menu_player1);
            flush_in();
            switch (escolhe_menu_player1)
            {
                case 1:
                printf("\nJOG 1 - ESCOLHA UMA PECA:\n");
                scanf("%d", &peca_jogada);        
                flush_in();

                printf("\nESQUERDA OU DIREITA?\n");
                scanf("%c", &deseja_inv);
                flush_in();

                printf("\nVOCE DESEJA INVERTER A PECA?\n");
                scanf("%c", &resp_inv2);
            
                if(toupper(resp_inv2) == 'S')
                {
                    if(toupper(deseja_inv) == 'E' )
                    {
                        int peca_temporaria;
                        domino_pecasMesa[contador_mesa] = jogador1.indexPecas[peca_jogada];

                        //printf("tentando inverter -> %d|%d", domino_pecas[domino_pecasMesa[contador_mesa]].left_side, domino_pecas[domino_pecasMesa[contador_mesa]].right_side);

                        peca_temporaria = domino_pecas[domino_pecasMesa[contador_mesa]].right_side;

                        domino_pecas[domino_pecasMesa[contador_mesa]].right_side = domino_pecas[domino_pecasMesa[contador_mesa]].left_side;
                        domino_pecas[domino_pecasMesa[contador_mesa]].left_side  = peca_temporaria;
 
                        for (int c = 26 ; c >= 0 ; c--){
                        domino_pecasMesa[c+1] = domino_pecasMesa[c];
                        }
                        domino_pecasMesa[0] = jogador1.indexPecas[peca_jogada];



                    }else
                    {
                        int peca_temporaria;
                        domino_pecasMesa[contador_mesa] = jogador1.indexPecas[peca_jogada];

                        //printf("tentando inverter -> %d|%d", domino_pecas[domino_pecasMesa[contador_mesa]].left_side, domino_pecas[domino_pecasMesa[contador_mesa]].right_side);

                        peca_temporaria = domino_pecas[domino_pecasMesa[contador_mesa]].right_side;

                        domino_pecas[domino_pecasMesa[contador_mesa]].right_side = domino_pecas[domino_pecasMesa[contador_mesa]].left_side;
                        domino_pecas[domino_pecasMesa[contador_mesa]].left_side  = peca_temporaria;
                    
                    }

                }else
                {
                    // Joga a peça
                    if(toupper(deseja_inv) == 'E' )
                    {
 
                        for (int c = 26 ; c >= 0 ; c--)
                        {
                            domino_pecasMesa[c+1] = domino_pecasMesa[c];
                        }
                        domino_pecasMesa[0] = jogador1.indexPecas[peca_jogada];
                    
                    }else
                    {
                        domino_pecasMesa[contador_mesa] = jogador1.indexPecas[peca_jogada];
                    }
                }

                if (contador_mesa > 0)
                {
                    if(toupper(deseja_inv) == 'E' )
                    {

                        if(domino_pecas[domino_pecasMesa[1]].left_side == domino_pecas[jogador1.indexPecas[peca_jogada]].right_side)
                        {
                            jogadorPecas1--;

                            for(int k = peca_jogada; k < jogadorPecas1; k++)
                            { // Algoritmo que joga todo o array pra esquerda
                                jogador1.indexPecas[k] = jogador1.indexPecas[k+1];
                            }

                            contador_mesa++;
                    
                            jogador_start = 0;
                            j = 1;
                            break;

                        }else
                        {
                            printf("\n\nJOGADA INVALIDA\n\n");
                            continue;
                        }

                    }else
                    {


                        if (domino_pecas[domino_pecasMesa[contador_mesa - 1]].right_side == domino_pecas[jogador1.indexPecas[peca_jogada]].left_side)
                        {
                            jogadorPecas1--;

                            for(int k = peca_jogada; k < jogadorPecas1; k++)
                            { // Algoritmo que joga todo o array pra esquerda
                            jogador1.indexPecas[k] = jogador1.indexPecas[k+1];
                            }

                            contador_mesa++;
                
                            jogador_start = 0;
                            j = 1;
                            break;
                        }else
                        {
                            printf("\n\nJOGADA INVALIDA\n\n");
                            continue;
                        }

                    }
                }else
                {
                                
                    jogadorPecas1--;

                    for(int k = peca_jogada; k < jogadorPecas1; k++)
                    { // Algoritmo que joga todo o array pra esquerda
                        jogador1.indexPecas[k] = jogador1.indexPecas[k+1];
                    }

                    contador_mesa++;
                
                    jogador_start = 0;
                    j = 1;
                    break;

                }
                


                case 2:
                char compra_sn;
                printf("\n\nJOG 1 - DESEJA MESMO COMPRAR UMA PECA (S/N): \n");
                compra_sn = getchar();
                flush_in();
                if(toupper(compra_sn) == 'S')
                {
                    for (int k = 0; k < 28; k++)
                    {
                        // printf("peça que vou comprar - > %d|%d\n",domino_pecas[randomEmbaralha[k]].left_side,domino_pecas[randomEmbaralha[k]].right_side);
                        // printf("Status da peça que vou comprar -> %d ", domino_pecas[randomEmbaralha[k]].status);
                        
                        if(domino_pecas[randomEmbaralha[k]].status == 0)
                        {
                            jogador1.indexPecas[index_compra] = randomEmbaralha[k];
                            domino_pecas[randomEmbaralha[k]].status = 1;
                            index_compra++;
                            jogadorPecas1++;
                            
                            break;
                        } else if (k == 27)
                        {
                            printf("\nSEM PECAS DISPONIVEI PARA COMPRA!");
                        }   
                        
                    }
                    
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
            jogador2:
                if (jogador_next == 1 || j == 1)
                printf("==================================================================================================================================\n");
                printf("MESA:\n");
                {
                    for (int i = 0; i < contador_mesa; i++)
                    {
                    printf("[%d|%d] ", domino_pecas[domino_pecasMesa[i]].left_side, domino_pecas[domino_pecasMesa[i]].right_side);
                    }
                    printf("\n==================================================================================================================================");
                    printf("\nPRINTANDO AS PEÇAS DO JOGADOR 2:");
                    for (int i = 0; i < jogadorPecas2 ; i++) 
                    {
                        printf("\n%d.[%d|%d]", i, domino_pecas[jogador2.indexPecas[i]].left_side, domino_pecas[jogador2.indexPecas[i]].right_side);
                    }
                    

                int escolhe_menu_player2;
                printf("\n(1) - JOGAR");
                printf("\n(2) - COMPRAR PECA");
                printf("\n(3) - SAIR DO JOGO");
                printf("\n\nJOG2 - SUA ESCOLHA FOI: \n");
                scanf("%d", &escolhe_menu_player2);
                flush_in();
                switch (escolhe_menu_player2)
                {
                    case 1:
                    printf("\nJOG 2 - ESCOLHA UMA PECA:\n");
                    scanf("%d", &peca_jogada);
                    flush_in();

                    printf("\nESQUERDA OU DIREITA?\n");
                    scanf("%c", &deseja_inv);
                    flush_in();

                    printf("\nVOCE DESEJA INVERTER A PECA?\n");
                    scanf("%c", &resp_inv);

                    if(toupper(resp_inv) == 'S')
                    {
                        if(toupper(deseja_inv) == 'E' )
                        {
                            int peca_temporaria2;
                            for (int c = 26 ; c >= 0 ; c--)
                            {
                            domino_pecasMesa[c+1] = domino_pecasMesa[c];
                            }
                            domino_pecasMesa[0] = jogador2.indexPecas[peca_jogada];


                            //printf("tentando inverter -> %d|%d", domino_pecas[domino_pecasMesa[contador_mesa]].left_side, domino_pecas[domino_pecasMesa[contador_mesa]].right_side);

                            peca_temporaria2 = domino_pecas[domino_pecasMesa[0]].right_side;

                            domino_pecas[domino_pecasMesa[0]].right_side = domino_pecas[domino_pecasMesa[0]].left_side;
                            domino_pecas[domino_pecasMesa[0]].left_side  = peca_temporaria2;
                        
                        }else
                        {

                            int peca_temporaria2;
                            domino_pecasMesa[contador_mesa] = jogador2.indexPecas[peca_jogada];

                            //printf("tentando inverter -> %d|%d", domino_pecas[domino_pecasMesa[contador_mesa]].left_side, domino_pecas[domino_pecasMesa[contador_mesa]].right_side);

                            peca_temporaria2 = domino_pecas[domino_pecasMesa[contador_mesa]].right_side;

                            domino_pecas[domino_pecasMesa[contador_mesa]].right_side = domino_pecas[domino_pecasMesa[contador_mesa]].left_side;
                            domino_pecas[domino_pecasMesa[contador_mesa]].left_side  = peca_temporaria2;
                        }
    

                    }else
                    {
                        if(toupper(deseja_inv) == 'E' )
                        {
                            for (int c = 28 ; c >= 0 ; c--)
                            {
                                domino_pecasMesa[c+1] = domino_pecasMesa[c];
                        
                            }
                            domino_pecasMesa[0] = jogador2.indexPecas[peca_jogada];
                        }else
                        {
                            domino_pecasMesa[contador_mesa] = jogador2.indexPecas[peca_jogada];
                        }
                      
                    }


                    if (contador_mesa > 0)
                    {
                        if(toupper(deseja_inv) == 'E')
                        {
                            /*
                            if (toupper(resp_inv) == 'S'){
                                if(domino_pecas[domino_pecasMesa[1]].left_side == domino_pecas[jogador2.indexPecas[peca_jogada]].left_side){
                                jogadorPecas2--;

                                for(int k = peca_jogada; k < jogadorPecas2; k++)
                                {   //Algoritmo que joga todo o array pra esquerda
                                    jogador2.indexPecas[k] = jogador2.indexPecas[k+1];
                                }

                                contador_mesa++;
                                jogador_next = 0;
                                jogador_start = 1;
                                break;
                            }else{
                                printf("JOGADA INVALIDA");
                                continue;
                            }

                            }else{
                                */

                            
                            if(domino_pecas[domino_pecasMesa[1]].left_side == domino_pecas[jogador2.indexPecas[peca_jogada]].right_side)
                            {
                                jogadorPecas2--;

                                for(int k = peca_jogada; k < jogadorPecas2; k++)
                                {   //Algoritmo que joga todo o array pra esquerda
                                    jogador2.indexPecas[k] = jogador2.indexPecas[k+1];
                                }

                                contador_mesa++;
                                jogador_next = 0;
                                jogador_start = 1;
                                break;
                            }else{
                                printf("JOGADA INVALIDA");
                                continue;
                            }
                          //  
                        }else
                        {

                            if (domino_pecas[domino_pecasMesa[contador_mesa - 1]].right_side == domino_pecas[jogador2.indexPecas[peca_jogada]].left_side)
                            {
                                jogadorPecas2--;

                                for(int k = peca_jogada; k < jogadorPecas2; k++)
                                {   //Algoritmo que joga todo o array pra esquerda
                                jogador2.indexPecas[k] = jogador2.indexPecas[k+1];
                                }

                                contador_mesa++;

                                jogador_next = 0;
                                jogador_start = 1;
                                break;
                            }
                            else 
                            {
                                printf("\n\nJOGADA INVALIDA\n\n");
                                continue;
                            }
                        }
                    }else
                        {
                                                
                            jogadorPecas2--;

                            for(int k = peca_jogada; k < jogadorPecas2; k++)
                            {   //Algoritmo que joga todo o array pra esquerda
                                jogador2.indexPecas[k] = jogador2.indexPecas[k+1];
                            }

                            contador_mesa++;

                            
                            jogador_next = 0;
                            jogador_start = 1;
                            break;
                        }
                

                        case 2:
                        char compra_sn;
                        printf("\n\nJOG 2 - DESEJA MESMO COMPRAR UMA PECA? (S/N): \n");
                        compra_sn = getchar();
                        flush_in();
                        if(toupper(compra_sn) == 'S')
                        {
                            for (int k = 0; k < 28; k++)
                            {
                                // printf("peça que vou comprar - > %d|%d\n",domino_pecas[randomEmbaralha[k]].left_side,domino_pecas[randomEmbaralha[k]].right_side);
                                // printf("Status da peça que vou comprar -> %d ", domino_pecas[randomEmbaralha[k]].status);
                                
                                if(domino_pecas[randomEmbaralha[k]].status == 0)
                                {
                                    jogador2.indexPecas[index_compra2] = randomEmbaralha[k];
                                    domino_pecas[randomEmbaralha[k]].status = 1;
                                    index_compra2++;
                                    jogadorPecas2++;
                                    //goto printa_peca_add;
                                    
                                    break;
                                } else if (k == 27)
                                {
                                    printf("\n\nSEM PECAS DISPONIVEIS PARA COMPRA!");
                                }   
                        
                            }
                        }
                        break;

                        case 3:
                        exit(1);
                        break;

                    break;
                }
            }

        }while(jogador_next);

    }while(!win_condition); 
}