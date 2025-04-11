#ifndef ENCRIP_H_
#define ENCRIP_H_

#define MAX 6

// Funcao para encriptar o arquivo de texto
// Entrada: arquivo de entrada, arquivo de saida, expressao para encriptar (ate 6 valores)
// Saida: arquivo de saida em binario encriptado
// Pre-condicao: arquivo de texto, arquivo binario, valor inteiro
// Pos-condicao: nenhuma
void encriptar_arquivo(const char* arquivo_entrada, const char* arquivo_saida, const char* expressao);

// Funcao para decriptar arquivo de texto
// Entrada: arquivo de entrada, arquivo de saida, expressao para encriptar (ate 6 valores)
// Saida: arquivo de saida em binario encriptado
// Pre-condicao: arquivo binario, arquivo de texto, valor inteiro
// Pos-condicao: nenhuma
void decriptar_arquivo(const char* arq_entrada, const char* arq_saida, const char* expressao);

// Funcao para rotacionar bits a esquerda
// Entrada: byte a ser rotacionado, numero de rotacao
// Saida: valor rotacionado n vezes
// Pre-condicao: valor a ser rotacionado e o byte
// Pos-condicao: retorna o valor rotacionado
unsigned char rotacionar_esquerda(unsigned char valor, int n);

// Funcao para rotacionar bits a direita
// Entrada: byte a ser rotacionado, numero de rotacao
// Saida: valor rotacionado n vezes
// Pre-condicao: valor a ser rotacionado e o byte
// Pos-condicao: retorna o valor rotacionado
unsigned char rotacionar_direita(unsigned char valor, int n);

#endif // ENCRIP_H_
