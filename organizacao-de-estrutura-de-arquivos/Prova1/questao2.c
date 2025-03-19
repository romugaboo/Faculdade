#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv)
{
    FILE *f;
    int c, byte[256];

    for (int i = 0; i < 256; i++)
        byte[i] = 0;

    f = fopen("lorem.txt", "rw");
    if (f == NULL){
        fprintf(stderr, "Erro na abertura!\n\n");
        return -1;
    }
    c = fgetc(f);
    while (c != EOF)
    {
        byte[c] += 1;
        c = fgetc(f);
    }

    for (int i = 0; i < 256; i++)
    {
        if (byte[i] != 0)
            printf("Incidencia do byte %d (letra %c): %d\n", i, i, byte[i]);
    }
    return 0;
}