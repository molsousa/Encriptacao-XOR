#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "encrip.h"

int main(int argc, char* argv[]) // uso de argumentos para execucao no terminal
{
    system("color F");

    if(argc != 5){
        printf("(uso:) <arq_entrada> <arq_saida> <pin_%d> C/D\n", MAX);
        exit(1);
    }

    if(strlen(argv[3]) > MAX){ //nao permitido expressao acima do valor maximo especificado
        printf("Expressao invalida\n");
        exit(1);
    }

    *argv[4] = tolower(*argv[4]);

    if(*argv[4] == 'c')
        encriptar_arquivo(argv[1], argv[2], argv[3]); // manda o arquivo base, arquivo de saida, expressao

    else if(*argv[4] == 'd')
        decriptar_arquivo(argv[1], argv[2], argv[3]); // manda o arquivo base, arquivo de saida, expressao

    else
        printf("Opcao invalida\n");

    return 0;
}
