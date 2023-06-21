#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaços em memória 
#include <locale.h> //bilbioteca de alocaçôes de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/strings
    char arquivo [40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis/strings
	
    printf ("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //cópia dos valores das strings
    
    FILE *file; //cria o arquivo
    file =  fopen(arquivo, "w"); //cria o arquivo
    fprintf(file,cpf); //salvo o valor da variável
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
	setlocale(LC_ALL, "Portuguese"); // Definição de linguagem (biblioteca)
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	    printf("Não foi possível abrir o arquivo, não localizado. \n");
    }
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	printf("Este usuário foi removido com sucesso! \n");
    system("pause");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
{
	printf("Esse usuário não existe!\n");
	system("pause");
}
	
}



int main()
    {
	int opcao=0; // Definição das variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); // Definição de linguagem (biblioteca)
	
	printf("###Centro de consulta - EBAC###\n\n"); //Menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1- Registrar nomes\n");
	printf("\t2- Consultar nomes\n");
	printf("\t3- Deletar nomes\n"); 
	printf("\t4- Sair do sistema\n\n");
	printf("Digite a opção desejada:"); // Fim do menu
	
	scanf("%d", &opcao); // Opções de escolha do usuário
	
	system("cls");
	
	
	switch(opcao)
	{
		case 1:
		registro(); //chamda de funções 
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
			printf("Essa opção não está disponível no momento\n");
    	system("pause");
    	break;
		
	    }
	
	

    }
} 

	
	

	
	
	

