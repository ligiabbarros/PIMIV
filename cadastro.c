#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int numero;

int main(int argc, char *argv[])			

{
setlocale(LC_ALL, "Portuguese");
	printf("Grupo de Risco\n\n");
	printf("1- Maior de 65 anos\n");
	printf("2- Possui alguma Comorbidade\n");
	printf("3- Nenhuma op��o\n");
	printf("4- As duas op��o\n");
	printf("\nEscolha op��o desejada: \n");
	scanf("%d", &numero);
	switch(numero)
	{
		case 1:
			system("cls");
			printf("Maior de 65 anos\n");
			break;
			
		case 2:
			system("cls");
			printf("Possui alguma Comorbidade\n");
			break;
			
		case 3:
			system("cls");
			printf("Nenhuma op��o\n");
			break;	
		
		case 4:
			system("cls");
			printf("As duas op��o\n");
			break;
	}
 
	
	system("pause");
	return 0;
}
