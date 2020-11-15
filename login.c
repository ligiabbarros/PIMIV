/* ==============================================
   	PIM IV  |  Registro e Login
============================================== */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Variáveis Globais para Senhas/Usuarios de login e registro.
char Usuario[30] = "";
char Senha[30] = "";
char UsuarioL[30] = "";
char SenhaL[30] = "";
char IDPW[60] = "";
char IDPWL[60] = "";


// Funcao para imprimir cabeçalho
int imprimeCabecalho(char *Cabecalho){
	printf("\n--------------------------------\n");
	printf("\n%s\n", Cabecalho);
	printf("\n--------------------------------\n\n");

	return 0;
}

// Função para operação de Login.
int login(){
	
	while (strcmp(IDPW,IDPWL) != 0) {
		imprimeCabecalho("Logue na sua conta:");
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
			imprimeCabecalho("Usuário ou senha inválidos.\n\nTente novamente.");
		}
	}

	imprimeCabecalho("Login Efetuado!");
	
	return 0;
	
}

// Função para operação de Registro.
int registra(){
	
	imprimeCabecalho("Crie sua conta:");

	printf("\n1) Usuario | Defina seu usuario:\n");
	printf("-Limite de 30 caracteres!\n");
	printf("-Use somente letras e numeros!\n");
	printf("-Nao use caracteres especiais!\n");
	printf("-Nao coloque espacos!\n");
	printf("-Letras maiusculas ou minusculas fazem diferenca!\n-> ");
	scanf("%s",Usuario);

	printf("\n\n1) Senha | Defina sua senha:\n");
	printf("-Limite de 30 caracteres!\n");
	printf("-Use somente letras e numeros!\n");
	printf("-Nao use caracteres especiais!\n");
	printf("-Nao coloque espacos!\n");
	printf("-Letras maiusculas ou minusculas fazem diferenca!\n-> ");
	scanf("%s",Senha);
			
	imprimeCabecalho("Registro concluído");

	return 0;
}

// Código Principal.
int main(){
	
	//Variaveis para operação de Login ou Registro.
	int LoginOuCadastro;
	
	
	imprimeCabecalho("AREA DE LOGIN");
	
	printf("\nDeseja fazer login ou registrar-se?\n\n");
	printf("Escolha [1] -> para CRIAR CONTA\n");
	printf("Escolha [2] -> para LOGAR\n\n-> ");

	scanf("%i",&LoginOuCadastro);
	
	
	// Variavel do tipo ponteiro que aponta para o arquivo txt dos registros (file_pointer_1).
	FILE *fp1;
	
	
	
	// Código das operações de Registro e Login.
	switch (LoginOuCadastro){
		case 1:
			fp1 = fopen("registros.txt","r");
			if	(fp1 == NULL){
				fp1 = fopen("registros.txt","w");
				registra();
				fclose(fp1);
				
				fp1 = fopen("registros.txt","a");
				strcpy(IDPW,Usuario);
				strcat(IDPW,Senha);
				
				fputs(IDPW, fp1);
				
				fclose(fp1);
				
			}else{
				imprimeCabecalho("ERRO: Voce ja esta registrado!");

				fgets(IDPW, 60 ,fp1);
				
				fclose(fp1);
			}
		
			login();

			break;
		case 2:
			fp1 = fopen("registros.txt", "r");
			if (fp1 == NULL){
				printf("\nERRO: Nao ha um usuario registrado ainda!\n");
				printf("Impossivel efetuar LOGIN\n");
				printf("Iniciando registro...\n");
				registra();
				fclose(fp1);
				
				fp1 = fopen("registros.txt","w");
				fclose(fp1);
				
				fp1 = fopen("registros.txt","a");
				strcpy(IDPW,Usuario);
				strcat(IDPW,Senha);
				
				fputs(IDPW, fp1);
				
				fclose(fp1);
				
			}
			
			fp1 = fopen("registros.txt", "r");
			fgets(IDPW, 60, fp1);
			
			login();
			
			break;
		default:
			printf("\nVoce escolheu uma opcao invalida!\n");
			printf("Programa Encerrado\n");
			break;
	}
	
	return 0;
}