/* ==============================================
   	PIM IV  |  Registro e Login
============================================== */


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

// Função para registrar usuário
int registraUsuario(){

	fp1 = fopen("registros.txt","r");

	if (fp1 == NULL){

		imprimeCabecalho("Crie sua conta:", true);

		printf("\n1) Usuario | Defina seu usuario:\n");
		printf("-Limite de 30 caracteres!\n");
		printf("-Use somente letras e numeros!\n");
		printf("-Nao use caracteres especiais!\n");
		printf("-Nao coloque espacos!\n");
		printf("-Letras maiusculas ou minusculas fazem diferenca!\n\n-> ");
		scanf("%s",Usuario);

		printf("\n\n1) Senha | Defina sua senha:\n");
		printf("-Limite de 30 caracteres!\n");
		printf("-Use somente letras e numeros!\n");
		printf("-Nao use caracteres especiais!\n");
		printf("-Nao coloque espacos!\n");
		printf("-Letras maiusculas ou minusculas fazem diferenca!\n\n-> ");
		scanf("%s",Senha);

		strcpy(IDPW,Usuario);
		strcat(IDPW,Senha);

		fp1 = fopen("registros.txt","w");
		fputs(IDPW, fp1);
		fclose(fp1);

		imprimeCabecalho("Registro concluído", true);

	}else{
		imprimeCabecalho("ERRO: Voce ja esta registrado!", true);
	}

	return 0;
}

// Função para logar usuário
int logaUsuario(){

	fp1 = fopen("registros.txt", "r");

	if (fp1 == NULL){
		printf("\nERRO: Nao ha um usuario registrado ainda!\n");
		printf("Impossivel efetuar LOGIN\n");
		printf("Iniciando registro...\n");
		registraUsuario();
	}
	
	fp1 = fopen("registros.txt", "r");
	fgets(IDPW, 60, fp1);

	while (strcmp(IDPW,IDPWL) != 0) {
		imprimeCabecalho("Logue na sua conta:", false);
		printf("\nUsuario:\n");
		printf("-> ");
		scanf("%s",UsuarioL);
		printf("\n");
		printf("\nSenha:\n");
		printf("-> ");
		scanf("%s",SenhaL);

		strcpy(IDPWL, UsuarioL);
		strcat(IDPWL, SenhaL);

		if (strcmp(IDPW,IDPWL) != 0) {
			imprimeCabecalho("Usuário ou senha inválidos.\n\nTente novamente.", true);
		}
	}

	imprimeCabecalho("Login Efetuado!", true);
	
	return 0;
	
}

// Código Principal.
int main(){
	
	//Variaveis para operação de Login ou Registro.
	int RegistraOuLoga;
	
	
	imprimeCabecalho("AREA DE LOGIN", true);
	
	printf("\nDeseja fazer login ou registrar-se?\n\n");
	printf("Escolha [1] -> para REGISTRAR CONTA\n");
	printf("Escolha [2] -> para LOGAR\n\n-> ");

	scanf("%i",&RegistraOuLoga);


	// Código das operações de Registro e Login.
	switch (RegistraOuLoga){
		case 1:
			registraUsuario();
			break;
		case 2:
			logaUsuario();
			break;
		default:
			printf("\nVoce escolheu uma opcao invalida!\n");
			printf("Programa Encerrado\n");
			break;
	}
	
	return 0;
}