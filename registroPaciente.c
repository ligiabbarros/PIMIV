#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Variáveis Globais para registro do paciente
char nome[100] = "";
char cpf[20] = "";
char telefone[20] = "";
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


// Variavel do tipo ponteiro que aponta para o arquivo txt dos registros (file_pointer_1).
FILE *fp1;

// Variavel do tipo ponteiro que aponta para o arquivo txt de cadastro de
// pacientes
FILE *filePointerPacientes;

//buffer pra remover linha 
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

// Função para cadastrar paciente
int main(){

	filePointerPacientes = fopen("pacientes.txt","r");

	if (filePointerPacientes == NULL){

	    imprimeCabecalho("Cadastro de paciente", true);

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

		filePointerPacientes = fopen("pacientes.txt", "a");
		fputs(nome, filePointerPacientes);
		fputs(cpf, filePointerPacientes);
		fputs(telefone, filePointerPacientes);
		fputs(rua, filePointerPacientes);
		fputs(numero, filePointerPacientes);
        fputs(complemento, filePointerPacientes);
		fputs(bairro, filePointerPacientes);
		fputs(cidade, filePointerPacientes);
		fputs(uf, filePointerPacientes);
		fputs(cep, filePointerPacientes);
		fputs(diaNascimento, filePointerPacientes);
        fputs(mesNascimento, filePointerPacientes);
        fputs(anoNascimento, filePointerPacientes);
		fputs(data_diagnostico, filePointerPacientes);
		fputs(email, filePointerPacientes);
		fputs(comorbidade, filePointerPacientes);
		fclose(filePointerPacientes);
	}else{
		imprimeCabecalho("ERRO: Paciente já cadastrado.", true);
	}

	return 0;
}
