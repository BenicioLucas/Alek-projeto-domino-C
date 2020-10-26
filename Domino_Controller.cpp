#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#include "./Jogo.cpp"

void executaMenu()
{
    int option;
    option = iniciaMenu();
    switch(option)
    {
        case 1:
        jogo();
        break;

        case 6:
        printf("batata frita com cheddar e bacon");
        exit(0);
    }
}