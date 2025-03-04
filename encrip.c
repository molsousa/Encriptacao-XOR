#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "encrip.h"

// Funcao para encriptar o arquivo de texto
// Entrada: arquivo de entrada, arquivo de saida, expressao para encriptar (ate MAX valores)
// Saida: arquivo de saida em binario encriptado
// Pre-condicao: arquivo de texto, arquivo binario, valor inteiro
// Pos-condicao: nenhuma
void encriptar(const char *arquivo_entrada, const char *arquivo_saida, const char *senha)
{
    FILE *fr = fopen(arquivo_entrada, "r");
    FILE *fw = fopen(arquivo_saida, "wb");

    int senha_vetor[MAX];
    int senha_len = strlen(senha);
    for(int i = 0; i < senha_len; i++){
        senha_vetor[i] = senha[i] - '0'; // converte char para int
    }

    unsigned char byte;
    while (fread(&byte, 1, 1, fr) == 1){
        int soma = 0;
        // encriptacao: XOR + adicao + rotacao
        for (int i = 0; i < senha_len; i++){
            soma += senha_vetor[i];
            byte = (byte ^ soma) + soma;
            byte = rotacionar_esquerda(byte, 3); // rotacao de 3 bits
        }
        fwrite(&byte, 1, 1, fw);
    }

    fclose(fr);
    fclose(fw);
}

// Funcao para decriptar arquivo de texto
// Entrada: arquivo de entrada, arquivo de saida, expressao para encriptar (ate MAX valores)
// Saida: arquivo de saida em binario encriptado
// Pre-condicao: arquivo binario, arquivo de texto, valor inteiro
// Pos-condicao: nenhuma
void decriptar(const char *arquivo_entrada, const char *arquivo_saida, const char *senha)
{
    FILE *fr = fopen(arquivo_entrada, "rb");
    FILE *fw = fopen(arquivo_saida, "w");

    int senha_vetor[MAX];
    int senha_len = strlen(senha);
    for(int i = 0; i < senha_len; i++){
        senha_vetor[i] = senha[i] - '0';
    }
    unsigned char byte;

    while(fread(&byte, 1, 1, fr) == 1){
        int soma_total = 0;
        // Pré-calcula a soma total para uso reverso
        for(int i = 0; i < senha_len; i++){
            soma_total += senha_vetor[i];
        }

        // decriptacao: rotacao reversa + subtracao + XOR
        for(int i = senha_len - 1; i >= 0; i--){
            byte = rotacionar_direita(byte, 3); // reverte rotacao
            byte = (byte - soma_total) ^ soma_total;
            soma_total -= senha_vetor[i];
        }
        fwrite(&byte, 1, 1, fw);
    }

    fclose(fr);
    fclose(fw);
}

// Funcao para rotacionar bits a esquerda
// Entrada: byte a ser rotacionado, numero de rotacao
// Saida: valor rotacionado n vezes
// Pre-condicao: valor a ser rotacionado e o byte
// Pos-condicao: retorna o valor rotacionado
unsigned char rotacionar_esquerda(unsigned char valor, int n)
{
    n = n % 8; // Garante que n está entre 0 e 7
    return (valor << n) | (valor >> (8 - n));
}

// Funcao para rotacionar bits a esquerda
// Entrada: byte a ser rotacionado, numero de rotacao
// Saida: valor rotacionado n vezes
// Pre-condicao: valor a ser rotacionado e o byte
// Pos-condicao: retorna o valor rotacionado
unsigned char rotacionar_direita(unsigned char valor, int n)
{
    n = n % 8;
    return ((valor >> n) | (valor << (8 - n))) & 0xFF;
}
