#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espeaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteac responsavel por cuidar das strings


int registro()//Função responsável por cadastrar os usuários no sistema.
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//Inicio da criação de Variáveis/String.
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de Variáveis/String
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário.
	scanf("%s",cpf);//"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
		
	FILE * file;//cria o arquivo 	
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever.
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//Inicio da criação de Variáveis/String.
	char cpf[40];
	char conteudo[200];
	//Final da criação de Variáveis/String
	
	printf("Digite o CPF a ser consultado: ");//Coletando informação do usuário.
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, este CPF não foi localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	fclose(file);
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//Inicio da criação de Variáveis/String
	char cpf[40];
	//Final da criação de Variáveis/String
	
	printf("Digite o CPF a ser deletado: ");//Coletando informação do usuário.
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF do usuário não encontrado no sistema!\n");
		system("pause");
	}
	else
	{
		fclose(file);//Fechando o arquivo, pois ele existe
		remove(cpf);//Deletando o arquivo do CPF
		printf("\nO CPF solicitado foi deletado!\n\n");
		system("pause");
	}
}

int main()
{

	int opcao=0;//definindo as variaveis
	int laco=1;

	for(laco=1;laco=1;)//Definindo laço de repetição
	{
	
		system("cls");//Responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");//Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: ");//Final do Menu

		scanf("%d", &opcao);//armazenando a escolha do usuario
	
		system("cls");
		
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1:
				registro(); //Chamada de funções
			break;
			
			case 2:
				consulta(); //Chamada de funções
			break;
			
			case 3:
				deletar(); //Chamada de funções
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;
			
			default:
				printf("Esta opção não está disponível! Digite uma opção válida!\n\n");
			system("pause");
			break;
			
		}//final da seleção
	
	}
}
