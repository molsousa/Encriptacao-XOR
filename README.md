# Algoritmo de encriptação-XOR
### Encriptar arquivo de textos em qualquer caractere utilizando numerais.

O algoritmo utiliza rotações de bits a esquerda e a direita, durante a movimentação de bits para valores positivos, caso movimente os bits para a esquerda 'n' vezes, sendo n > 1, se perde a informação do bit anterior ao bit de sinal (que em valores positivos, o bit de sinal é sempre 0) a rotação de bits serve pra não perder os bits anteriores ao do sinal, rotacionando os bits que estavam a margem para o final da fila de bits se feita a rotação para a esquerda. A rotação a direita faz com os bits que estavam ao final, vão para a frente da fila, desfazendo a rotação a esquerda.

O operador xor é uma camada a mais que garante que a cada rotação, crie uma nova chave de encriptação utilizando numerais, como os numerais são valores inteiros, dentro do intervalo numeral de diversos tipos de codificação (UTF-8, Unicode, etc.), a informação não é perdida quando executada a decriptação do arquivo binário anteriormente encriptado.

- É necessário compilar os arquivos fonte e a biblioteca antes de utilizar o programa. 
- A entrada deve ser feita pelo terminal.
- A encriptação pode ser feita sobre qualquer símbolo que possibilite a leitura em um bloco de notas padrão.
- Para encriptação foi utilizado o operador xor "^" e rotação de bits.
- A chave de acesso suporta no máximo 6 numerais.
- Para decriptar é necessário que tenha os mesmos numerais que usou para encriptar.

### Para a entrada é necessário:
  1. Inserir executável.
  2. Inserir arquivo de texto padrão (em encriptação).
  3. Inserir arquivo de saída binário (em encriptação).
  4. Inserir a chave de acesso.
  5. Inserir comando de encriptar ou decriptar.
  

  **Exemplo de execução**:

      .\xor.exe arq_fonte.txt arq_destino.bin 123456 E
