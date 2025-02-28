#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "encrip.h"

// Funcao para encriptar o arquivo de texto
// Entrada: arquivo de entrada, arquivo de saida, expressao para encriptar (ate 6 valores)
// Saida: arquivo de saida em binario encriptado
// Pre-condicao: arquivo de texto, arquivo binario, valor inteiro
// Pos-condicao: nenhuma
void encriptar_arquivo(const char *arq_entrada, const char *arq_saida, const char *expressao)
{
    FILE *fr = fopen(arq_entrada, "r");
    FILE *fw = fopen(arq_saida, "wb"); // exportar arquivo binario

    int i, caractere;
    int exp_vetor[MAX];
    int exp_numerica = atoi(expressao); // arquivo padrao aceita apenas numerais

    if(!fr || !fw){
        printf("Nao foi possivel abrir/escrever o arquivo\n");
        exit(1);
    }

    importar_vetor(exp_vetor, exp_numerica);

    for(i = 0; i < MAX; i++){
        // printf("%d\n", exp_vetor[i]); //[DEBUG]

        while( (caractere = getc(fr)) != EOF ){
            caractere = caractere ^ exp_vetor[i]; // expressao XOR para encriptar

            putc(caractere, fw);
        }
        rewind(fr);
        rewind(fw); // retorna ao inicio do arquivo para reescrever (se necessario)
    }
    fclose(fr);
    fclose(fw);
}

// Funcao para decriptar arquivo de texto
// Entrada: arquivo de entrada, arquivo de saida, expressao para encriptar (ate 6 valores)
// Saida: arquivo de saida em binario encriptado
// Pre-condicao: arquivo binario, arquivo de texto, valor inteiro
// Pos-condicao: nenhuma
void decriptar_arquivo(const char *arq_entrada, const char *arq_saida, const char *expressao)
{
    FILE *fr = fopen(arq_entrada, "rb"); // abrir arquivo binario
    FILE *fw = fopen(arq_saida, "w");

    int i, caractere;
    int exp_vetor[MAX];
    int exp_numerica = atoi(expressao); // arquivo padrao aceita apenas numerais

    if(!fr || !fw){
        printf("Nao foi possivel abrir/escrever o arquivo\n");
        exit(1);
    }

    importar_vetor(exp_vetor, exp_numerica);

    for(i = 0; i < MAX; i++){
        // printf("%d\n", exp_vetor[i]); //[DEBUG]

        while( (caractere = getc(fr)) != EOF ){
            caractere = caractere ^ exp_vetor[i]; // expressao XOR para desfazer encriptacao

            putc(caractere, fw);
        }
        rewind(fr);
        rewind(fw); // retorna ao inicio do arquivo para reescrever (se necessario)
    }
    fclose(fr);
    fclose(fw);
}

// Funcao para receber a expressao numerica
// Entrada: vetor de 6 posicoes e uma expressao numerica inteira
// Saida: vetor de 6 posicoes com numeros de ate 1 unidade
// Pre-condicao: vetor criado, expressao inserida
// Pos-condicao: nenhuma
void importar_vetor(int *v, int numeral)
{
    int aux, i, n;
    double divisor;

    n = MAX-1;

    for(i = 0; i < MAX; i++){
        divisor = (double) pow(10, n);

        aux = (int) (numeral / divisor);
        // printf("v[%d] = %d\n", i, aux); //[DEBUG]

        v[i] = aux;
        numeral = numeral % ((int)divisor);

        // printf("%d\n", v[i]); //[DEBUG]

        n--;
    }
}
