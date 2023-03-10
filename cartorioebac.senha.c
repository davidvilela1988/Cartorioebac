#include <stdio.h> //biblioteca de comunica??o com o usu?rio
#include <stdlib.h> //biblioteca de aloca??o de espa?o em mem?ria
#include <locale.h> //biblioteca de aloca??es de texto por regi?o
#include <string.h> //biblioteca respons?vel por cuidar das string

int registro() //fun??o respons?vel por cadastrar os usu?rios no sistema
{
	//in?cio da cria??o de vari?veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria??o de vari?veis/string
	
	printf("Digite o CPF (sem espa?os, pontos ou tra?os) a ser cadastrado: "); //coletando informa??o do usu?rio
	scanf("%s", cpf); //%s refere-se  a string
	
	strcpy(arquivo, cpf); //Respons?vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" sginfica escrever
	fprintf(file,cpf); //salva o valor da vari?vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o primeiro nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta() //consulta de registros
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N?o foi poss?vel abrir o arquivo! (N?o localizado) \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s?o as informa??es do usu?rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu?rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O Usu?rio n?o se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo vari?veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem da tela inicial
	
	printf("### Cart?rio da EBAC ###\n\n");
	printf("TELA DE LOGIN \n\nDigite a sua senha de administrador: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		system("cls");
		
		for(laco=1;laco=1;)
		{
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
			printf("### Cart?rio da EBAC ###\n\n"); //In?cio do menu
			printf("Escolha a op??o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes;\n");
			printf("\t2 - Consultar nomes;\n");
			printf("\t3 - Deletar nomes;\n");
			printf("\t4 - Sair do sistema;\n\n\n");
			printf("(Digite o n?mero com a op??o desejada e tecle 'Enter'):");//Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu?rio
	
			system("cls"); //respons?vel por limpar a tela
		
			switch(opcao) //in?cio da sele??o do menu
			{
				case 1:
				registro(); //chamada de fun??es
				break;
			
				case 2:
				consulta(); //chamada de fun??es
				break;
			
				case 3:
				deletar(); //chamada de fun??es
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema.\n");
				return 0;
				break;
			
				default:
				printf("Esta op??o n?o est? dispon?vel!\n");
				system("pause");
					break;	
		
			} //fim da sele??o
		}
	}
	
	else
		printf("Senha incorreta!");
}
