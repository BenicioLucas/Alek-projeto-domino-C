#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
        exit(0);
    }
}