#ifndef ENCRIP_H_
#define ENCRIP_H_

#define MAX 6

// Funcao para encriptar o arquivo de texto
// Entrada: arquivo de entrada, arquivo de saida, expressao para encriptar (ate 6 valores)
// Saida: arquivo de saida em binario encriptado
// Pre-condicao: arquivo de texto, arquivo binario, valor inteiro
// Pos-condicao: nenhuma
void encriptar_arquivo(const char *arq_entrada, const char *arq_saida, const char *expressao);

// Funcao para decriptar arquivo de texto
// Entrada: arquivo de entrada, arquivo de saida, expressao para encriptar (ate 6 valores)
// Saida: arquivo de saida em binario encriptado
// Pre-condicao: arquivo binario, arquivo de texto, valor inteiro
// Pos-condicao: nenhuma
void decriptar_arquivo(const char *arq_entrada, const char *arq_saida, const char *expressao);

// Funcao para receber a expressao numerica
// Entrada: vetor de 6 posicoes e uma expressao numerica inteira
// Saida: vetor de 6 posicoes com numeros de ate 1 unidade
// Pre-condicao: vetor criado, expressao inserida
// Pos-condicao: nenhuma
void importar_vetor(int *v, int numeral);

#endif // ENCRIP_H_
