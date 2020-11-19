#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Variáveis Globais para registro do paciente
char Nome[100] = "";
char Cpf[11] = "";
char Telefone[15] = "";
char Rua[200] = "";
int Numero[10] = "";
char Complemento[20] = "";
char Bairro[100] = "";
char Cidade[100] = "";
char Estado[50] = "";
char CEP[15] = "";
int diaNascimento[2] = "";
int mesNascimento[2] = "";
int anoNascimento[4] = ""; 
char Email[100] = "";
char Diagnostico[10] = "";
char Comorbidade[300] = "";

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

// Função para cadastrar paciente
int cadastraPaciente(){

	filePointerPacientes = fopen("pacientes.txt","r");

	if (filePointerPacientes == NULL){

		imprimeCabecalho("Cadastro de paciente", true);

		printf("\nNome completo do paciente:\n-> ");
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
