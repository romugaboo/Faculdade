#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

int main(int argc, char** argv)
{
    FILE *f;
	Endereco e;
	int total, cmp, tamarq, qtdreg, inicio, meio, fim, achei;

	if(argc != 2)
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}
	
	f = fopen("cep_ordenado.dat","r");
	fseek(f,0,SEEK_END);
	tamarq = ftell(f);
	qtdreg = tamarq / sizeof(Endereco);
	inicio = 0;
	fim = qtdreg-1;
	total = 0;
    achei = 0;
	
	while(inicio <= fim && !achei)
	{
		meio = (inicio+fim)/2;
		fseek(f,meio*sizeof(Endereco),SEEK_SET);
		fread(&e,sizeof(Endereco),1,f);
		total++;
		cmp = strncmp(argv[1],e.cep,8);
		if(cmp == 0)
		{
			printf("CEP encontrado! c:\n\n");
			printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
			printf("Total lidos: %d\n", total);
			fclose(f);
			return 0;		
		}
		else if(cmp > 0)
			inicio = meio + 1;
		else
			fim = meio - 1;
	}
	
	printf("CEP nao encontrado! :c\n");
	fclose(f);
	return 1;	
}