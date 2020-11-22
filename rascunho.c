
int recuperarLinha(int linha) {
	static const char filename[] = "file.txt";
	FILE *file = fopen(filename, "r");
	int count = 0;
	if ( file != NULL )
	{
		char line[256]; /* or other suitable maximum line size */
		while (fgets(line, sizeof line, file) != NULL) /* read a line */
		{
			if (count == lineNumber)
			{
				//use line or in a function return it
				//in case of a return first close the file with "fclose(file);"
			}
			else
			{
				count++;
			}
		}
		fclose(file);
	}
	else
	{
		//file doesn't exist
	}
}

// Função para cadastrar paciente 
int cadastraPaciente() {


}

// Função para gerar relatório
int geraRelatorio() {


}




// Função para 
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