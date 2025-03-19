#include <stdio.h>

void limpaArray(int array[], int size){
  for (int i = 0; i < size; i++)
    array[i] = 0;
}

int main(int argc, char** argv) {
  FILE *entrada;
  int c, caracteres[256];
  float media = 0, espaco = 0, letras = 0;

  limpaArray(caracteres, 256);

  if (argc != 2) {
    fprintf(stderr, "Erro na chamada do comando\n");
    fprintf(stderr, "Uso %s, [ARQUIVO ORIGEM]\n", argv[0]);
    return 1;
  }
  
  entrada = fopen(argv[1], "r");
  if (!entrada) {
    fprintf(stderr, "Arquivo %s nao pode ser aberto para leitura", argv[1]);
    return 1;
  }
 
  c = fgetc(entrada);
  caracteres[c]++;
  while (c != EOF) {
    if (c == ' '){
      espaco++;
    }
    if (c != ' '){
      letras++;
    }
    c = fgetc(entrada);
    caracteres[c]++;
  }
    
  media = letras / espaco;
  fclose(entrada);

  //Questão 1
  printf("O documento selecionado tem %.0f letras. \n", letras);
  printf("O documento selecionado tem %.0f palavras. \n", espaco);
  printf("A media de letras por palavra eh de %.2f. \n", media);

  //Questão 2
  printf("O numero de ocorrencia de cada letra eh:\n");
  for (int i = 'A'; i < 'z'; i++){
    if (caracteres[i] != 0)
      printf("%c: %d \n", i, caracteres[i]);
  }
  return 0; 
}