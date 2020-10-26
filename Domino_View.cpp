//CHAMA MENU

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "./Domino_Model.cpp"


int iniciaMenu()
{
    int option; // OPÇÃO
    do
    {
      
        printf("Domino The Game\n");
        printf("===============\n");
        // MENU //
        printf("(1) - Iniciar novo jogo\n");
        printf("(2) - Continuar a jogar\n");
        printf("(3) - Salvar jogo\n");
        printf("(4) - Carregar jogo\n");
        printf("(5) - Regras do jogo\n");
        printf("(6) - Sair\n\n");

        printf("Opcao selecionada: \n");
        scanf("%d", &option);
        flush_in();
        
        if (option < 1 || option > 6)
        {
            continue;
        }
        else
        {
            break;
        }
        
    }while(true);
    
    return option;
}