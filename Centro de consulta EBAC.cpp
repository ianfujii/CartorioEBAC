#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria 
#include <locale.h> //bilbioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings
    char arquivo [40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/strings
	
    printf ("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //c�pia dos valores das strings
    
    FILE *file; //cria o arquivo
    file =  fopen(arquivo, "w"); //cria o arquivo
    fprintf(file,cpf); //salvo o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, "-");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "-");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "-");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");
    
    
     
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Defini��o de linguagem (biblioteca)
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	    printf("N�o foi poss�vel abrir o arquivo, n�o localizado. \n");
    }
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	printf("Este usu�rio foi removido com sucesso! \n");
    system("pause");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
{
	printf("Esse usu�rio n�o existe!\n");
	system("pause");
}
	
}



int main()
    {
	int opcao=0; // Defini��o das vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); // Defini��o de linguagem (biblioteca)
	
	printf("###Centro de consulta - EBAC###\n\n"); //Menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1- Registrar nomes\n");
	printf("\t2- Consultar nomes\n");
	printf("\t3- Deletar nomes\n"); 
	printf("\t4- Sair do sistema\n\n");
	printf("Digite a op��o desejada:"); // Fim do menu
	
	scanf("%d", &opcao); // Op��es de escolha do usu�rio
	
	system("cls");
	
	
	switch(opcao)
	{
		case 1:
		registro(); //chamda de fun��es 
		break; 
		
		 case 2:
		 consulta();
		break;
		
		 case 3:
		 deletar();
		break;	
		
		case 4:
			 printf("Obrigado por utilizar o sistema!\n");
		 return 0;
		 break;
		

		default:
			printf("Essa op��o n�o est� dispon�vel no momento\n");
    	system("pause");
    	break;
		
	    }
	
	

    }
} 

	
	

	
	
	

