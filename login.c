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

// Variáveis Globais para cadastro de pacientes.
char Nome[30] = "";
char CPF[11] = "";
char Telefone[11] = "";
char Rua[30] = "";
char Numero[5] = "";
char Bairro[15] = "";
char Cidade[15] = "";
char Estado[2] = "";
char CEP[8] = "";
char DataDiagnostico[8] = "";
char DataNascimento[8] = "";
char Email[30] = "";
char Comorbidades[60] = "";

// Variavel do tipo ponteiro que aponta para o arquivo txt dos registros.
FILE *filePointerRegistros;

// Variavel do tipo ponteiro que aponta para o arquivo txt de cadastro de
// pacientes
FILE *filePointerPacientes;

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

	filePointerRegistros = fopen("registros.txt","r");

	if (filePointerRegistros == NULL){

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

		filePointerRegistros = fopen("registros.txt","w");
		fputs(IDPW, filePointerRegistros);
		fclose(filePointerRegistros);

		imprimeCabecalho("Registro concluído", true);

	}else{
		imprimeCabecalho("ERRO: Voce ja esta registrado!", true);
	}

	return 0;
}

// Função para logar usuário
int logaUsuario(){

	filePointerRegistros = fopen("registros.txt", "r");

	if (filePointerRegistros == NULL){
		printf("\nERRO: Nao ha um usuario registrado ainda!\n");
		printf("Impossivel efetuar LOGIN\n");
		printf("Iniciando registro...\n");
		registraUsuario();
	}
	
	filePointerRegistros = fopen("registros.txt", "r");
	fgets(IDPW, 60, filePointerRegistros);

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

// Função para cadastrar paciente
int cadastraPaciente(){

	filePointerPacientes = fopen("pacientes.txt","r");

	if (filePointerPacientes == NULL){

		imprimeCabecalho("Cadastro de paciente", true);

		printf("\nNome completo:\n-> ");
		scanf("%s",Nome);
		printf("\nCPF:\n\n-> ");
		scanf("%s",CPF);
		printf("\nTelefone:\n\n-> ");
		scanf("%s",Telefone);
		printf("\nRua:\n\n-> ");
		scanf("%s",Rua);
		printf("\nNumero:\n\n-> ");
		scanf("%s",Numero);
		printf("\nBairro:\n\n-> ");
		scanf("%s",Bairro);
		printf("\nCidade:\n\n-> ");
		scanf("%s",Cidade);
		printf("\nEstado:\n\n-> ");
		scanf("%s",Estado);
		printf("\nCEP:\n\n-> ");
		scanf("%s",CEP);
		printf("\nData de nascimento:\n\n-> ");
		scanf("%s",DataNascimento);
		printf("\nData do diagnostico:\n\n-> ");
		scanf("%s",DataDiagnostico);
		printf("\nEmail:\n\n-> ");
		scanf("%s",Email);
		printf("\nComorbidades:\n\n-> ");
		scanf("%s",Comorbidades);

		filePointerPacientes = fopen("pacientes.txt", "a");
		fputs(Nome, filePointerPacientes);
		fputs(CPF, filePointerPacientes);
		fputs(Telefone, filePointerPacientes);
		fputs(Rua, filePointerPacientes);
		fputs(Numero, filePointerPacientes);
		fputs(Bairro, filePointerPacientes);
		fputs(Cidade, filePointerPacientes);
		fputs(Estado, filePointerPacientes);
		fputs(CEP, filePointerPacientes);
		fputs(DataNascimento, filePointerPacientes);
		fputs(DataDiagnostico, filePointerPacientes);
		fputs(Email, filePointerPacientes);
		fputs(Comorbidades, filePointerPacientes);
		fclose(filePointerPacientes);
	}else{
		imprimeCabecalho("ERRO: Paciente já cadastrado.", true);
	}

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