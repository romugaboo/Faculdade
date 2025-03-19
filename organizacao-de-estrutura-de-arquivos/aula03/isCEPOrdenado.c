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

int main(int argc, char**argv)
{
	FILE *f;
	Endereco e, e2;
	int qt;
	int c = 0;
	char o;

	printf("Tamanho da Estrutura: %ld\n\n", sizeof(Endereco));
	f = fopen("cep_ordenado.dat","r");
	qt = fread(&e,sizeof(Endereco),1,f);
	while(qt > 0)
	{
		c++;
		qt = fread(&e2,sizeof(Endereco),1,f);

		while (c == 1){
			if(strncmp(e.cep, e2.cep,8) > 0)
			{
			 	printf("A ordem deve ser descrescente\n");
				o = 'd';
				c++;
			}
			else if(strncmp(e.cep, e2.cep,8) < 0)
			{
				printf("A ordem deve ser crescente\n");
				o = 'c';
				c++;
			}
			else{
				c--;
			}
		}
		if (o == 'd' && strncmp(e.cep, e2.cep,8) < 0){
			 printf("Porém, há elementos fora de ordem\n");
			 break;
		}
		if (o == 'c' && strncmp(e.cep, e2.cep,8) > 0){
			 printf("Porém, há elementos fora de ordem\n");
			 break;
		}
		e = e2;		
	}
	fclose(f);
}