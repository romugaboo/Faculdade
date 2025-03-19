#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv)
{
    FILE *entrada, *saida;
    int c;
    entrada = fopen("loremipsum.txt", "r");
    saida = fopen("resultado.txt", "w");
    if (entrada == NULL)
        fprintf(stderr, "Erro na abertura!\n");
    c = fgetc(entrada);

    while (c != EOF)
    {
        fputc(c, saida);
        c = fgetc(entrada);
        if (c == '\n')
            fputc('\r', saida);
    }
    fclose(saida);
    fclose(entrada);
    system("pause");
    return 0;
}