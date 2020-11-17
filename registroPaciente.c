#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Variáveis Globais para Senhas/Usuarios de login e registro.
char Usuario[30] = "";
char Senha[30] = "";
char UsuarioL[30] = "";
char SenhaL[30] = "";
char IDPW[60] = "";
char IDPWL[60] = "";

// Variavel do tipo ponteiro que aponta para o arquivo txt dos registros (file_pointer_1).
FILE *fp1;

// Funcao para imprimir cabeçalho
int imprimeCabecalho(char *Cabecalho, bool ClearScreen){

	if (ClearScreen) {
		system("clear");
	}

	printf("\n--------------------------------\n");
	printf("\n%s\n", Cabecalho);
	printf("\n--------------------------------\n\n");

	return 0;
}