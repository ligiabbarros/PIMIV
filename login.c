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

// Variáveis Globais para registro do paciente
char nome[200] = "";
char cpf[50] = "";
char telefone[50] = "";
char rua[200] = "";
char numero[10] = "";
char complemento[20] = "";
char bairro[100] = "";
char cidade[100] = "";
char uf[50] = "";
char cep[15] = "";
char diaNascimento[10] = "";
char mesNascimento[10] = "";
char anoNascimento[10] = ""; 
char email[100] = "";
char data_diagnostico[15] = "";
char comorbidade[300] = "";

// Variavel do tipo ponteiro que aponta para o arquivo txt dos registros.
FILE *filePointerRegistros;

// Variavel do tipo ponteiro que aponta para o arquivo txt de cadastro de
// pacientes
FILE *filePointerPacientes;

//limpa string
const char * removeNL(char *s) {
	while (*s) {
		if (*s == '\n') {
			*s=' ';
		}
		s++;
	}
	return s;
}

//remover histórico buffer
void limpaStdin(void)
{
   int c;
   do {
	   c = getchar();
   } while (c != '\n' && c != EOF);
}

//funcao pra remover linha 
void removerNewLine(char* buffer){
	buffer[strcspn(buffer, "\r\n")] = 0;
}

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

		limpaStdin();

		printf("Digite os dados do paciente\n");
		printf("Nome: ");
		fgets(nome, sizeof nome, stdin);
		removerNewLine(nome);
		printf("\n");

		printf("CPF (sem pontos ou tracos): ");
		fgets(cpf, sizeof cpf, stdin);
		removerNewLine(cpf);
		printf("\n");

		printf("Telefone (sem pontos ou tracos): ");
		fgets(telefone, sizeof telefone, stdin);
		removerNewLine(telefone);
		printf("\n");
		
		printf("Digite o endereco do paciente\n");
		printf("Rua: ");
		fgets(rua, sizeof rua, stdin);
		removerNewLine(rua);
		printf("\n");

		printf("Numero: ");
		fgets(numero, sizeof numero, stdin);
		removerNewLine(numero);
		printf("\n");

		printf("Complemento: ");
		fgets(complemento, sizeof complemento, stdin);
		removerNewLine(complemento);
		printf("\n");

		printf("Bairro: ");
		fgets(bairro, sizeof bairro, stdin);
		removerNewLine(bairro);
		printf("\n");

		printf("Cidade: ");
		fgets(cidade, sizeof cidade, stdin);
		removerNewLine(cidade);
		printf("\n");

		printf("UF: ");
		fgets(uf, sizeof uf, stdin);
		removerNewLine(uf);
		printf("\n");

		printf("CEP (sem pontos ou tracos): ");
		fgets(cep, sizeof cep, stdin);
		removerNewLine(cep);
		printf("\n");

		printf("Dia de Nascimento: ");
		fgets(diaNascimento, sizeof diaNascimento, stdin);
		removerNewLine(diaNascimento);
		printf("\n");
		
		printf("Mes de Nascimento: ");
		fgets(mesNascimento, sizeof mesNascimento, stdin);
		removerNewLine(mesNascimento);
		printf("\n");

		printf("Ano de Nascimento: ");
		fgets(anoNascimento, sizeof anoNascimento, stdin);
		removerNewLine(anoNascimento);
		printf("\n");

		printf("E-mail: ");
		fgets(email, sizeof email, stdin);
		removerNewLine(email);
		printf("\n");

		printf("Data do Diagnostico: ");
		fgets(data_diagnostico, sizeof data_diagnostico, stdin);
		removerNewLine(data_diagnostico);
		printf("\n");

		printf("Comorbidades: ");
		fgets(comorbidade, sizeof comorbidade, stdin);
		removerNewLine(comorbidade);
		printf("\n");

		//grava cada dado em uma linha no arquivo
		filePointerPacientes = fopen("pacientes.txt", "a");

		fprintf(filePointerPacientes, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", nome, cpf, telefone, rua, numero, complemento, bairro, cidade, uf, cep, diaNascimento, mesNascimento, anoNascimento, email, data_diagnostico, comorbidade);
		fclose(filePointerPacientes);
	}else{
		imprimeCabecalho("ERRO: Paciente já cadastrado.", true);
	}
	return 0;
}

//global 
char retornoRecuperaLinha[50] = "";

// recupera linha
const char * recuperaLinha(int linha){

	char linhaRecuperada[50];
	char linhaRecuperadaF[50];
	int count = 1;

	filePointerPacientes = fopen("pacientes.txt", "r");

	while (fgets(linhaRecuperada, sizeof linhaRecuperada, filePointerPacientes) != NULL)
		{
			if (count == linha)
			{
				strcpy(retornoRecuperaLinha, linhaRecuperada);
				puts(retornoRecuperaLinha);
			}
			else
			{
				count++;
			}
		} 
		return retornoRecuperaLinha;
}

//calculadora comorbidade
int calculaComorbidade(){

	//variaveis
	char idadeCalculada[20];
	char comorbidadeIdentificada[10];

	filePointerPacientes = fopen("pacientes.txt", "r");

	if (filePointerPacientes != NULL){
		

		strcpy(comorbidadeIdentificada, recuperaLinha(13));
		puts(comorbidadeIdentificada);
		
	

	}else{
		imprimeCabecalho("ERRO: Paciente não cadastrado.", true);
	}
	return 0;
}


// Código Principal.
int main(){
	cadastraPaciente();
	calculaComorbidade();

	/*
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

	cadastraPaciente(); */
	return 0;
}