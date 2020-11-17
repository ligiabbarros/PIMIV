#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dir.h>
#include <process.h>

void removerNewLine(char* buffer){
    buffer[strcspn(buffer, "\r\n")] = 0;
}

void cadastrar_paciente(){
    char nome[60];
    char cpf[15];
    char telefone[15];

    char rua[60];
    char numero[10];
    char bairro[60];
    char cidade[60];
    char uf[5];
    char cep[15];

    char data_nascimento[15];
    char email[40];
    char data_diagnostico[15];
    //char comorbidades[20][20];

    char possui_comorbidade[10];
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
    printf("Digite o endereço do paciente\n");
    printf("Rua: ");
    fgets(rua, sizeof rua, stdin);
    removerNewLine(rua);

    printf("\n");
    printf("Número: ");
    fgets(numero, sizeof numero, stdin);
    removerNewLine(numero);

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
    printf("Data de Nascimento: ");
    fgets(data_nascimento, sizeof data_nascimento, stdin);
    removerNewLine(data_nascimento);

    printf("\n");
    printf("E-mail: ");
    fgets(email, sizeof email, stdin);
    removerNewLine(email);

    printf("\n");
    printf("Data do Diagnóstico: ");
    fgets(data_diagnostico, sizeof data_diagnostico, stdin);
    removerNewLine(data_diagnostico);


    int numComorbidades;
    int ch;
    char comorbStr[100];
    do{
        printf("Digite o número de comorbidades do paciente (0 se não tiver):");
        scanf("%d", &numComorbidades);
        printf("%d", numComorbidades);
    }while(!(numComorbidades>=0 && numComorbidades<21));
    //consome o \n deixado pelo scanf
    while((ch = getchar()) != '\n' && ch != EOF);

    if(numComorbidades == 0){
        char* comorbStr = "O paciente não possui comorbidades.";

        //snprintf(fileName, sizeof(fileName), "%s%s.txt", pasta, cpf);



        int check;
        char* pasta = "Cadastros Pacientes";
        check = mkdir(pasta);

        //checking if directory is created
        if (!check)
            printf("Directory created\n");
        else {
            printf("Unable to create directory\n");
            //exit(1);
        }

        char caminho[200];
        printf("%s", caminho);
        char* fileName = cpf;
        //snprintf(fileName, sizeof(fileName), "%s%s.txt", pasta, cpf);
        strcpy(caminho, "Cadastros Pacientes\\");
        strcat(caminho, fileName);
        strcat(caminho, ".txt");
        FILE *fp;
        fp = fopen(caminho, "w");
        if (fp == NULL)
    {
        printf("fopen failed");
    }

        fprintf(fp, "Nome: %s\nCPF: %s\nTelefone: %s\nEndereco: %s, %s, %s, %s, %s\nCEP: %s\n\nData de Nascimento: %s\nE-mail: %s\nData do Diagnóstico: %s\nComorbidades: %s",
         nome, cpf, telefone, rua, numero, bairro, cidade, uf, cep, data_nascimento, email, data_diagnostico, comorbStr);

        fclose(fp);

    }else if(numComorbidades == 1){
        //char comorbStr[20];
        printf("\n");
        printf("Digite a comorbidade: ");
        fgets(comorbStr, 100, stdin);
        removerNewLine(comorbStr);



        int check;
        char* pasta = "Cadastros Pacientes";
        check = mkdir(pasta);

        //checking if directory is created
        if (!check)
            printf("Directory created\n");
        else {
            printf("Unable to create directory\n");
            //exit(1);
        }

        char caminho[200];
        char* fileName = cpf;
        //snprintf(fileName, sizeof(fileName), "%s%s.txt", pasta, cpf);
        strcpy(caminho, "Cadastros Pacientes\\");
        strcat(caminho, fileName);
        strcat(caminho, ".txt");
        FILE *fp;
        fp = fopen(caminho, "w");
        if (fp == NULL)
    {
        printf("fopen failed caminho: %s", caminho);
    }



        fprintf(fp, "Nome: %s\nCPF: %s\nTelefone: %s\nEndereco: %s, %s, %s, %s, %s\nCEP: %s\n\nData de Nascimento: %s\nE-mail: %s\nData do Diagnóstico: %s\nComorbidades: %s",
         nome, cpf, telefone, rua, numero, bairro, cidade, uf, cep, data_nascimento, email, data_diagnostico, comorbStr);

    }else{
        char comorbidades[numComorbidades][20];
        printf("\n");
            int i = 0;
            while(i<numComorbidades){
                printf("Digite a %iª comorbidade: ", i+1);
                fgets(comorbidades[i], 20, stdin);
                removerNewLine(comorbidades[i]);
                //printf("%s", comorbidades[i]);
                printf("\n");
                i++;
            }

        int check;
        char* pasta = "Cadastros Pacientes";
        check = mkdir(pasta);

        //checking if directory is created
        if (!check)
            printf("Directory created\n");
        else {
            printf("Unable to create directory\n");
            //exit(1);
        }

        char caminho[200];
        char* fileName = cpf;
        //snprintf(fileName, sizeof(fileName), "%s%s.txt", pasta, cpf);
        strcpy(caminho, "Cadastros Pacientes\\");
        strcat(caminho, fileName);
        strcat(caminho, ".txt");
        FILE *fp;
        fp = fopen(caminho, "w");
        if (fp == NULL)
    {
        printf("fopen failed caminho: %s", caminho);
    }
        fprintf(fp, "Nome: %s\nCPF: %s\nTelefone: %s\nEndereco: %s, %s, %s, %s, %s\nCEP: %s\n\nData de Nascimento: %s\nE-mail: %s\nData do Diagnóstico: %s\nComorbidades: ",
         nome, cpf, telefone, rua, numero, bairro, cidade, uf, cep, data_nascimento, email, data_diagnostico);

        fclose(fp);

        fp = fopen(caminho, "a+");

        if (fp == NULL)
    {
        printf("fopen failed a+");
    }

        //loop para inserir as comorbidades no arquivo
        //imprimir o primeiro sem vírgula.
        printf("%s", comorbidades[0]);
        fprintf(fp, "%s", comorbidades[0]);
        //imprimir vírgula e espaço depois o i.
        for(int i = 1; i<numComorbidades; i++){
            //printf("teste %d", i);
            printf(", %s", comorbidades[i]);
            fprintf(fp, ", %s", comorbidades[i]);
        }

        fclose(fp);
    }
}

int main()
{
    //printf("Hello world!\n");
    cadastrar_paciente();
    //teste();

    return 0;
}
