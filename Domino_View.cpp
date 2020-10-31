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
        printf("(1) - Iniciar novo jogo\n");
        printf("(2) - Sair\n\n");

        printf("Opcao selecionada: \n");
        scanf("%d", &option);
        flush_in();
        
        if (option < 1 || option > 2)
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