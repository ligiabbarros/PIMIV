/* ==============================================
   	PIM IV  |  Registro e Login
============================================== */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

// Variavel do tipo ponteiro que aponta para o arquivo txt de relatório de
// pacientes
FILE *filePointerRelatoriopacientes;

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
int imprimeEmDestaque(char *Cabecalho){

	printf("\n--------------------------------\n");
	printf("\n%s\n", Cabecalho);
	printf("\n--------------------------------\n\n");

	return 0;
}

// Função para registrar usuário
int registraUsuario(){

	filePointerRegistros = fopen("registros.txt","r");

	if (filePointerRegistros == NULL){

		imprimeEmDestaque("Crie sua conta:");

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

		imprimeEmDestaque("Registro concluído");

	}else{
		imprimeEmDestaque("Voce ja esta registrado!");
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
		imprimeEmDestaque("Logue na sua conta:");
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
			imprimeEmDestaque("Usuário ou senha inválidos.\n\nTente novamente.");
		} 
	}

	imprimeEmDestaque("Login Efetuado!");
	
	
	return 0;
	
}

// Função para cadastrar paciente
int cadastraPaciente(){

	filePointerPacientes = fopen("pacientes.txt","r");

	if (filePointerPacientes == NULL){

		imprimeEmDestaque("Cadastro de paciente");

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
		imprimeEmDestaque("Paciente já cadastrado.");
	}
	return 0;
}

//global 
char retornoRecuperaLinha[50] = "";

// recupera linha
const char * recuperaLinha(int linha){

	char linhaRecuperada[50];
	int count = 0;

	filePointerPacientes = fopen("pacientes.txt", "r");

	while (fgets(linhaRecuperada, sizeof linhaRecuperada, filePointerPacientes) != NULL){
		if (count == linha){
			strcpy(retornoRecuperaLinha, linhaRecuperada);
		}
		count++;
	}
	return retornoRecuperaLinha;
}

// Função para gerar relatório
int geraRelatorio(){

	imprimeEmDestaque("Relatorio");
	//variaveis
	int anoNascimento = 0;
	int idade = 0;
	int idadeDeRisco = 18; // mudar pra 65 no final
	int anoAtual = 0;
	char comorbidadesRegistradas[300];
	char nome[30] = "";
	char cep[10] = "";

	time_t s, val = 1;
	struct tm* current_time;
	s = time(NULL);
	current_time = localtime(&s);

	anoAtual = (current_time->tm_year + 1900);

	filePointerPacientes = fopen("pacientes.txt", "r");

	if (filePointerPacientes != NULL){
		anoNascimento = atoi(recuperaLinha(12));
		idade = anoAtual - anoNascimento;

		strcpy(comorbidadesRegistradas, recuperaLinha(15));
		removerNewLine(comorbidadesRegistradas);

		strcpy(nome, recuperaLinha(0));
		removerNewLine(nome);

		if (strcmp(comorbidadesRegistradas, "nenhuma") == 0){
			printf("O paciente %s não possui comorbidades.\n", nome);
		}else{
			printf("O paciente %s possui as seguintes comorbidades: %s\n", nome, comorbidadesRegistradas);
		}

		if (idade > idadeDeRisco){
			strcpy(cep, recuperaLinha(9));
			removerNewLine(cep);

			printf("O paciente %s pertence ao grupo de risco, idade: %d anos\nGerando relatório...\n", nome, idade);

			filePointerRelatoriopacientes = fopen("relatorioPacientes.txt", "w");
			fprintf(filePointerRelatoriopacientes, "Nome do paciente: %s\nCEP: %s\nIdade: %d\n", nome, cep, idade);
			fclose(filePointerRelatoriopacientes);

			printf("Relatório do paciente %s gerado com sucesso", nome);
		}else{
			printf("O paciente %s não pertence ao grupo de risco pois possui %d anos, o relatório não será gerado.", nome, idade);
		}
	}else{
		imprimeEmDestaque("Paciente não cadastrado.");
	}
	return 0;
}


// Código Principal.
int main(){

	//Variaveis para operação de Login ou Registro.
	int RegistraOuLoga;

	imprimeEmDestaque("AREA DE LOGIN");
	
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

	cadastraPaciente();
	geraRelatorio();
	return 0;
}